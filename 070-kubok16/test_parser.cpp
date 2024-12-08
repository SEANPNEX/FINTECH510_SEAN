#include "parse.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void runTest(const std::string& filename) {
    std::cout << "Running test with file: " << filename << std::endl;

    try {
        // Open the test file
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Error: Could not open file " + filename);
        }

        // Parse the data
        Parser parser(inputFile);
        parser.parseData();

        // Output the parsed data
        std::cout << "Column sums: ";
        for (int value : parser.getColumnSums()) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        std::cout << "Row sums: ";
        for (int value : parser.getRowSums()) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        std::cout << "Grid:" << std::endl;
        for (const auto& row : parser.getGrid()) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        // Catch and print any errors
        std::cerr << "Test failed: " << e.what() << std::endl;
    }

    std::cout << "---------------------------------------------------" << std::endl;
}

int main() {
    // List of test files
    std::vector<std::string> testFiles = {
        "missing_column_sum.txt",
        "missing_grid.txt",
        "missing_row_sum.txt",
        "missing_rows.txt",
        "out_of_range_1.txt",
        "out_of_range_2.txt",
        "valid1.txt"
    };

    // Run tests for each file
    for (const std::string& testFile : testFiles) {
        runTest(testFile);
    }

    return 0;
}
