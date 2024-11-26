#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For EXIT_FAILURE
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <Eigen/Dense>
#include "parse.hpp"
#include "parse_vec.hpp"
#include "valid.hpp"
#define THRESHOLD 1e-6

Eigen::MatrixXd calculateCovarianceMatrix(const std::vector<double>& stdROR, const Eigen::MatrixXd& correlationMatrix) {
    size_t n = stdROR.size();
    Eigen::MatrixXd covarianceMatrix(n, n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            covarianceMatrix(i, j) = stdROR[i] * stdROR[j] * correlationMatrix(i, j);
        }
    }

    return covarianceMatrix;
}

double calculateVolatility(const Eigen::VectorXd& weights, const Eigen::MatrixXd& covarianceMatrix) {
    return std::sqrt(weights.transpose() * covarianceMatrix * weights);
}

Eigen::VectorXd solveEfficientFrontierUnresctricted(const Eigen::MatrixXd& sigma, const Eigen::VectorXd& averageROR, const Eigen::Vector2d& b) {
    size_t n = sigma.rows();

    Eigen::MatrixXd A(2, n);
    A.row(0) = Eigen::VectorXd::Ones(n);
    A.row(1) = averageROR;

    Eigen::MatrixXd topBlock(n, n + 2);
    topBlock << sigma, A.transpose();

    Eigen::MatrixXd bottomBlock(2, n + 2);
    bottomBlock << A, Eigen::MatrixXd::Zero(2, 2);

    Eigen::MatrixXd systemMatrix(n + 2, n + 2);
    systemMatrix << topBlock,
                    bottomBlock;

    Eigen::VectorXd rhs = Eigen::VectorXd::Zero(n + 2);
    rhs.tail<2>() = b;

    Eigen::VectorXd solution = systemMatrix.colPivHouseholderQr().solve(rhs);

    return solution; 
}

Eigen::VectorXd solveEfficientFrontierRestricted(const Eigen::MatrixXd& sigma, const Eigen::VectorXd& averageROR, Eigen::VectorXd b) {
    size_t n = sigma.rows();
    Eigen::MatrixXd A(2, n); 
    A.row(0) = Eigen::VectorXd::Ones(n);
    A.row(1) = averageROR;

    Eigen::MatrixXd systemMatrix;  
    Eigen::VectorXd rhs;           
    Eigen::VectorXd weights(n);   

    std::vector<size_t> restrictedIndices;

    while (true) {

        size_t m = A.rows();
        Eigen::MatrixXd topBlock(n, n + m);
        topBlock << sigma, A.transpose();
        Eigen::MatrixXd bottomBlock(m, n + m);
        bottomBlock << A, Eigen::MatrixXd::Zero(m, m);
        systemMatrix.resize(n + m, n + m);
        systemMatrix << topBlock,
                        bottomBlock;
        rhs.resize(n + m);
        rhs.head(n).setZero();   
        rhs.tail(m) = b; 
        Eigen::VectorXd solution = systemMatrix.colPivHouseholderQr().solve(rhs);
        weights = solution.head(n); 

        // Check for negative weights and update A & b
        bool hasNegativeWeights = false;
        for (size_t i = 0; i < n; ++i) {
            if (weights[i] < -THRESHOLD) {
                hasNegativeWeights = true;

                Eigen::VectorXd restrictionRow = Eigen::VectorXd::Zero(n);
                restrictionRow[i] = 1.0;
                A.conservativeResize(A.rows() + 1, Eigen::NoChange);
                A.row(A.rows() - 1) = restrictionRow;

                b.conservativeResize(b.size() + 1);
                b[b.size() - 1] = 0.0;

                break; 
            }
        }

        if (!hasNegativeWeights) {
            break; 
        }
    }
    return weights;
}



int main(int argc, char* argv[]){

    bool restricted = false;
    std::string assetDataFileName;
    std::string correlationMatrixFileName;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-r") {
            restricted = true;
        } else if (assetDataFileName.empty()) {
            assetDataFileName = arg;
        } else if (correlationMatrixFileName.empty()) {
               correlationMatrixFileName = arg;
        } else {
            std::cerr << "Usage: program [-r] <universe.csv> <correlation.csv>" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if (assetDataFileName.empty() || correlationMatrixFileName.empty()) {
            std::cerr << "Usage: program [-r] <universe.csv> <correlation.csv>" << std::endl;
            exit(EXIT_FAILURE);
    }

    // parse asset universe
    std::ifstream assetDataFile(assetDataFileName);
    if (!assetDataFile.is_open()) {
        std::cerr << "Error: Could not open " + assetDataFileName << std::endl;
        exit(EXIT_FAILURE);
    }
    ParserVec assetParser(assetDataFile);
    assetParser.parseData();
    const std::vector<std::string>& headers = assetParser.getHeaders();
    const std::vector<double>& averageROR = assetParser.getAverageROR();
    const std::vector<double>& stdROR = assetParser.getStdROR();
    assetDataFile.close();

    // parse correlation matrix
    std::ifstream correlationMatrixFile(correlationMatrixFileName);
    if (!correlationMatrixFile.is_open()) {
        std::cerr << "Error: Could not open " << correlationMatrixFileName << std::endl;
        exit(EXIT_FAILURE);
    }
    Parser matrixParser(correlationMatrixFile);
    matrixParser.parseData();
    Eigen::MatrixXd correlationMatrix = matrixParser.getMatrix();
    correlationMatrixFile.close();

    //validate input
    validateAssetData(headers, averageROR, stdROR, correlationMatrix);
    validateCorrelationMatrix(correlationMatrix, stdROR);

    // calculate covariance 
    Eigen::MatrixXd sigma = calculateCovarianceMatrix(stdROR, correlationMatrix);
    // convert the avgROR
    Eigen::VectorXd avgRORVec = Eigen::Map<const Eigen::VectorXd>(averageROR.data(), averageROR.size());
    std::cout << "ROR,volatility" << std::endl;
    if(!restricted){
        for(double i = 1; i < 27; ++i){
            Eigen::Vector2d b(1.0, i/100);
            Eigen::VectorXd solution = solveEfficientFrontierUnresctricted(sigma, avgRORVec, b);
            size_t n = averageROR.size();
            Eigen::VectorXd weights = solution.head(n);
            Eigen::VectorXd lambda = solution.tail(2);
            double volatility = calculateVolatility(weights, sigma);
            std::cout << std::fixed << std::setprecision(1) << i << "%," << std::setprecision(2) << volatility*100 << "%" << std::endl;
        }
    }else{
        for(double i = 1; i < 27; ++i){
            Eigen::VectorXd b(2);
            b << 1.0,i/100; 
            Eigen::VectorXd solution = solveEfficientFrontierRestricted(sigma, avgRORVec, b);
            size_t n = averageROR.size();
            Eigen::VectorXd weights = solution.head(n);
            Eigen::VectorXd lambda = solution.tail(2);
            double volatility = calculateVolatility(weights, sigma);
            std::cout << std::fixed << std::setprecision(1) << i << "%," << std::setprecision(2) << volatility*100 << "%" << std::endl;
        }
    }


} 