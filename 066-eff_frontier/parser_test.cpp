#include <iostream>
#include <fstream>
#include "parse.hpp"

void runParserTest() {
    // Specify the path to your CSV file
    std::string filePath = "correlation.csv";

    // Open the file as an input stream
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }

    try {
        // Instantiate the Parser with the input file stream
        Parser parser(inputFile);

        // Parse the data
        parser.parseData();

        // Get the parsed matrix
        Eigen::MatrixXd matrix = parser.getMatrix();

        // Print the resulting matrix
        std::cout << "Parsed Matrix:" << std::endl;
        std::cout << matrix << std::endl;

        // Close the file
        inputFile.close();
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
}

int main() {
    runParserTest();
    return 0;
}
