#include "valid.hpp"
#include <iostream>
#include <set>
#include <regex>
#include <Eigen/Dense>

bool isValidNumber(const std::string& str) {
    const std::regex numberRegex(R"(^-?\d+(\.\d+)?$)");
    return std::regex_match(str, numberRegex);
}

double safeStod(const std::string& str) {
    if (!isValidNumber(str)) {
        std::cerr << "Error: Invalid numeric value " << str << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::stod(str);
}

void validateCorrelationMatrix(const Eigen::MatrixXd& correlationMatrix, const std::vector<double>& stdROR) {
    if (correlationMatrix.rows() != correlationMatrix.cols()) {
        std::cerr << "Error: Correlation matrix must be square." << std::endl;
        exit(EXIT_FAILURE);
    }
    if (correlationMatrix.rows() != stdROR.size()) {
        std::cerr << "Error: Correlation matrix dimensions do not match StdROR vector size." << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < correlationMatrix.rows(); ++i) {
        if (std::abs(correlationMatrix(i, i) - 1.0) > 1e-6) {
            std::cerr << "Error: Correlation matrix diagonal elements must be 1." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < correlationMatrix.rows(); ++i) {
        for (int j = i + 1; j < correlationMatrix.cols(); ++j) {
            if (std::abs(correlationMatrix(i, j) - correlationMatrix(j, i)) > 1e-6) {
                std::cerr << "Error: Correlation matrix must be symmetric." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    for (int i = 0; i < correlationMatrix.rows(); ++i) {
        for (int j = 0; j < correlationMatrix.cols(); ++j) {
            if (correlationMatrix(i, j) < -1.0 || correlationMatrix(i, j) > 1.0) {
                std::cerr << "Error: Correlation coefficients must be between -1 and 1." << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigenSolver(correlationMatrix);
    if (eigenSolver.eigenvalues().minCoeff() < -1e-6) {
        std::cerr << "Error: Correlation matrix must be positive semi-definite." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void validateAssetData(const std::vector<std::string>& headers, const std::vector<double>& averageROR, const std::vector<double>& stdROR, const Eigen::MatrixXd& correlationMatrix) {
    if (headers.empty() || averageROR.empty() || stdROR.empty()) {
        std::cerr << "Error: Asset data file is empty or contains no valid rows." << std::endl;
        exit(EXIT_FAILURE);
    }
    if (headers.size() != averageROR.size() || headers.size() != stdROR.size()) {
        std::cerr << "Error: Asset data columns have mismatched sizes." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::set<std::string> assetNames;
    for (const auto& name : headers) {
        if (!assetNames.insert(name).second) {
            std::cerr << "Error: Duplicate asset name found: " << name << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    for (size_t i = 0; i < headers.size(); ++i) {
        if (stdROR[i] <= 0.0) {
            std::cerr << "Error: Standard deviation (StdROR) must be positive for asset: " << headers[i] << std::endl;
            exit(EXIT_FAILURE);
        }
        if (averageROR[i] < -1.0 || averageROR[i] > 1.0) {
            std::cerr << "Error: Average rate of return (AverageROR) is out of valid range [-1, 1] for asset: " << headers[i] << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if (headers.size() != correlationMatrix.rows()) {
        std::cerr << "Error: Asset data size does not match correlation matrix dimensions." << std::endl;
        exit(EXIT_FAILURE);
    }
}
