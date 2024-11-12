#include "parse.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Create a sample CSV file to test the parser
    std::ofstream testFile("test.csv");
    if (testFile.is_open()) {
        testFile << "Time,Asset1,Asset2,Asset3\n";
        testFile << "0,100.0,200.0,300.0\n";
        testFile << "1,105.0,NaN,310.0\n";
        testFile << "2,110.0,210.0,NaN\n";
        testFile << "3,115.0,215.0,320.0\n";
        testFile.close();
    } else {
        std::cerr << "Failed to create test file." << std::endl;
        return EXIT_FAILURE;
    }

    // Open the test file and create a Parser instance
    std::ifstream inputFile("test.csv");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open test file." << std::endl;
        return EXIT_FAILURE;
    }

    // Create the parser and parse the file
    Parser parser(inputFile);
    parser.parseHeader();
    parser.parseData();
    parser.getHeaders();

    // Get the parsed matrix and display it
    Matrix<double> matrix = parser.getMatrix();

    std::cout << "Parsed Matrix:" << matrix << std::endl;

    inputFile.close();
    return 0;
}
