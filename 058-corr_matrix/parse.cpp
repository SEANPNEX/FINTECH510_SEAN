#include "parse.hpp"
#include <iostream>
#include <sstream> 
#include <limits>  
#include <vector>
#include <string>
#include <stdexcept> 
#include <cfloat>
#include <cmath>

Parser::Parser(std::ifstream& in) : inputStream(in) {
    if (!inputStream.good()) {
        std::cerr << "Error: Input stream is not valid for reading." << std::endl;
        exit(EXIT_FAILURE);
    }
}

Parser::~Parser() {}

vector<string> Parser::getHeaders(){

    return headers;
}

void Parser::parseHeader() {
    std::string headerLine;
    if (!std::getline(inputStream, headerLine)) {
        std::cerr << "Error: Header line is missing or empty." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::istringstream ss(headerLine);
    std::string column;

    while (std::getline(ss, column, ',')) {
        if (column.empty()) {
            std::cerr << "Error: Empty column name detected in header." << std::endl;
            exit(EXIT_FAILURE);
        }
        headers.push_back(column);
    }

    if (headers.size() < 2) {
        std::cerr << "Error: Header must contain at least one asset column." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Parser::parseData() {
    vector<std::string> lines;
    std::string line;

    while (std::getline(inputStream, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    vector<double> lastValidValues(headers.size(), std::numeric_limits<double>::quiet_NaN());

    for (const std::string& line : lines) {
        vector<double> rowData = parseline(line, lastValidValues);
        data.pushBackRow(rowData);
    }
}

vector<double> Parser::parseline(const std::string &line, vector<double> &lastValidValues) {
    vector<double> rowData;
    std::istringstream ss(line);
    std::string value;
    int colIndex = 0;

    while (std::getline(ss, value, ',')) {
        value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

        if (value == "NaN" || value == "nan") {
            if (!std::isnan(lastValidValues[colIndex])) {
                rowData.push_back(lastValidValues[colIndex]);
            } else {
                if (colIndex==0){
                    rowData.push_back(0);
                    continue;
                }
                handleException("Error: Column '" + headers[colIndex] + "' has no valid data.");
            }
        } else {
            try {
                double num = std::stod(value);
                rowData.push_back(num);
                lastValidValues[colIndex] = num;
            } catch (const std::invalid_argument&) {
                if (!std::isnan(lastValidValues[colIndex])) {
                    rowData.push_back(lastValidValues[colIndex]);
                } else {
                    if (colIndex==0){
                        rowData.push_back(0);
                        continue;
                    }
                    handleException("Error: Column '" + headers[colIndex] + "' has no valid data.");
                }
            }
        }
        ++colIndex;
    }

    if (static_cast<int>(rowData.size()) != static_cast<int>(headers.size())) {
        handleException("Error: Parsed row does not match header column count.");
    }

    return rowData;
}

void Parser::handleException(const std::string& errorMsg) {
    std::cerr << errorMsg << std::endl;
    exit(EXIT_FAILURE);
}

Matrix<double> Parser::getMatrix() const {
        return data;
    }