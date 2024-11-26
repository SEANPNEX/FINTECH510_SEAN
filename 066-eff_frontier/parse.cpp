#include "parse.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

Parser::Parser(std::ifstream& in) : inputStream(in) {
    if (!inputStream.good()) {
        std::cerr << "Error: Input stream is not valid for reading." << std::endl;
        exit(EXIT_FAILURE);
    }
}

Parser::~Parser() {}

void Parser::parseData() {
    std::vector<std::vector<double>> rows;
    std::string line;

    while (std::getline(inputStream, line)) {
        if (!line.empty()) {
            rows.push_back(parseLine(line));
        }
    }

    if (rows.empty()) {
        std::cerr << "Error: No data rows found in the input." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Initialize Eigen::MatrixXd with data from rows
    data = Eigen::MatrixXd(rows.size(), rows[0].size());
    for (size_t i = 0; i < rows.size(); ++i) {
        for (size_t j = 0; j < rows[i].size(); ++j) {
            data(i, j) = rows[i][j];
        }
    }
}

std::vector<double> Parser::parseLine(const std::string& line) {
    std::vector<double> rowData;
    std::istringstream ss(line);
    std::string value;

    while (std::getline(ss, value, ',')) {
        value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

        if (value.empty() || value == "NaN" || value == "nan") {
            handleException("Error: Missing or invalid value in data.");
        } else {
            try {
                rowData.push_back(std::stod(value));
            } catch (const std::invalid_argument&) {
                handleException("Error: Unable to parse value '" + value + "'.");
            }
        }
    }

    return rowData;
}

void Parser::handleException(const std::string& errorMsg) {
    std::cerr << errorMsg << std::endl;
    exit(EXIT_FAILURE);
}

Eigen::MatrixXd Parser::getMatrix() const {
    return data;
}
