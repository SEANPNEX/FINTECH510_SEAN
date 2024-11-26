#include <iostream>
#include <fstream>
#include "parse_vec.hpp"

void runParserVecTest() {
    // Specify the path to your CSV file
    std::string filePath = "universe.csv";

    // Open the file as an input stream
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }

    try {
        // Instantiate the ParserVec with the input file stream
        ParserVec parser(inputFile);

        // Parse the data
        parser.parseData();

        // Get and print the parsed values
        const std::vector<std::string>& headers = parser.getHeaders();
        const std::vector<double>& avgROR = parser.getAverageROR();
        const std::vector<double>& stdROR = parser.getStdROR();

        std::cout << "Headers, AverageROR, StdROR:" << std::endl;
        for (size_t i = 0; i < headers.size(); ++i) {
            std::cout << headers[i] << ", " << avgROR[i] << ", " << stdROR[i] << std::endl;
        }

        // Close the file
        inputFile.close();
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }
}

int main() {
    runParserVecTest();
    return 0;
}
