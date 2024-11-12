#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For EXIT_FAILURE
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include "Matrix.hpp"
#include "parse.hpp"
#include <numeric>
#include <cmath>

using std::string;
using std::vector;
using namespace std;

Matrix<double> calculateReturns(const Matrix<double>& data) {
    int numRows = data.getRows();
    int numCols = data.getColumns();

    if (numRows < 2) {
        cerr << "Error: Not enough data to calculate returns." << endl;
        exit(EXIT_FAILURE);
    }

    Matrix<double> returnsMatrix(numRows - 1, numCols);

    for (int col = 1; col < numCols; ++col) { // Start from column 1 to ignore index column
        for (int row = 1; row < numRows; ++row) {
            double current = data[row][col];
            double previous = data[row - 1][col];

            if (previous == 0) {
                cerr << "Error: Division by zero encountered in column " << col << "." << endl;
                exit(EXIT_FAILURE);
            }

            double returnVal = (current / previous) - 1;
            returnsMatrix[row - 1][col] = returnVal;
        }
    }

    return returnsMatrix;
}

float calculateMean(std::vector<double> const& v){
    if(v.empty()){
        return 0;
    }

    auto const count = static_cast<float>(v.size());
    return std::reduce(v.begin(), v.end()) / count;
}

double calculateStandardDeviation(const vector<double>& data, double mean) {
    double sumSquares = 0.0;
    for (double val : data) {
        sumSquares += pow(val - mean, 2);
    }
    return sqrt(sumSquares / (data.size() - 1));
}

vector<double> sliceMatrixColumn(const Matrix<double>& matrix, int colIndex) {
    if (colIndex < 0 || colIndex >= matrix.getColumns()) {
        cerr << "Error: Column index out of range." << endl;
        exit(EXIT_FAILURE);
    }

    vector<double> columnData;
    for (int row = 0; row < matrix.getRows(); ++row) {
        columnData.push_back(matrix[row][colIndex]);
    }
    return columnData;
}

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

double calculateCovariance(Matrix<double> returns, int indexA, int indexB, double meanA, double meanB){
    double sum = 0;
    int n = returns.getRows();
    for (int i = 0; i < n; ++i){
            sum += (returns[i][indexA] - meanA) * (returns[i][indexB] - meanB);
        }
        return sum / n;
}


ifstream openFile(string name) {
    ifstream in(name);
    if (!in.is_open()) {
        cerr << "Unable to open " << name << endl;
        exit(EXIT_FAILURE);
    }
    return in;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return EXIT_FAILURE;
    }

    string filename = argv[1];

    if (!fileExists(filename)) {
        cerr << "Error: File '" << filename << "' does not exist or cannot be accessed." << endl;
        return EXIT_FAILURE;
    }

    ifstream in = openFile(filename);
    
    Parser p(in);
    p.parseHeader();
    p.parseData();
    Matrix<double> matrix = p.getMatrix();
    // cout << "Read matrix" << matrix << endl;
    Matrix<double> return_matrix = calculateReturns(matrix);
    // cout << "returns" << return_matrix << endl;
    vector<string> headers = p.getHeaders();
    Matrix<double> statistics(2, headers.size() - 1); // Ignore the first column (index)

    for (int i = 1; i < static_cast<int>(headers.size()); ++i) { // Start from column 1
        vector<double> columnData = sliceMatrixColumn(return_matrix, i);
        double mean = calculateMean(columnData);
        double stdDev = calculateStandardDeviation(columnData, mean);
        statistics[0][i - 1] = mean;
        statistics[1][i - 1] = stdDev;
    }

    // cout << "Statistics Matrix (Mean and Standard Deviation):" << endl;
    // cout << statistics << endl;

    Matrix<double> correlationMatrix(headers.size() -1, headers.size() -1);
    // calculate the correlation



    for(int i = 0; i < correlationMatrix.getRows(); ++i){
        for (int j=0; j < correlationMatrix.getColumns(); ++j){
            if (i==j){
                correlationMatrix[i][j] = 1.0;
            }
            else{
                double meanA = statistics[0][i];
                double meanB = statistics[0][j];
                double stdA = statistics[1][i];
                double stdB = statistics[1][j];
                if (stdA == 0 || stdB == 0) {
                cerr << "Error: Standard deviation is zero, correlation undefined for indices " << i << " and " << j << "." << endl;
                exit(EXIT_FAILURE);
                }
                double covAB = calculateCovariance(return_matrix, i+1, j+1, meanA, meanB);
                double corAB = covAB / (stdA * stdB);
                correlationMatrix[i][j] = corAB;
            }

        }
    }



    vector<string> slicedHeader(headers.begin() + 1, headers.end());
    for(string asset:slicedHeader){
        cout << asset << endl;
    }
    // cout << "Correlation Matrix:" << endl;
    cout << correlationMatrix << endl;


    // cout << "Parsing completed successfully." << endl;

    return 0;
}
