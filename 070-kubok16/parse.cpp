#include "parse.hpp"

Parser::Parser(std::ifstream& in) : inputStream(in) {
    if (!inputStream.good()) {
        std::cerr << "Error: Input stream is not valid for reading." << std::endl;
        exit(EXIT_FAILURE);
    }
}

Parser::~Parser() {}

void Parser::handleException(const std::string& errorMsg) {
    std::cerr << errorMsg << std::endl;
    exit(EXIT_FAILURE);
}

std::vector<int> Parser::parseSums(const std::string& line, const std::string& prefix) {
    if (line.find(prefix) == std::string::npos) {
        handleException("Error: Expected " + prefix + " in line: " + line);
    }

    std::string sumsPart = line.substr(line.find(":") + 1);
    std::istringstream ss(sumsPart);
    std::vector<int> sums;
    std::string value;

    while (std::getline(ss, value, ',')) {
        try {
            int sum = std::stoi(value);
            // Validate range of each sum
            if (sum < 10 || sum > 58) {
                handleException("Error: " + prefix + " value out of range [4, 64]: " + std::to_string(sum));
            }
            sums.push_back(sum);
        } catch (const std::exception&) {
            handleException("Error: Invalid value in " + prefix + ": " + value);
        }
    }

    return sums;
}

std::vector<int> Parser::parseGridLine(const std::string& line) {
    std::istringstream ss(line);
    std::vector<int> gridRow;
    std::string value;

    while (std::getline(ss, value, ',')) {
        try {
            int gridValue = std::stoi(value);
            // Validate grid value range
            if (gridValue < 0 || gridValue > 16) {
                handleException("Error: Grid value out of range [0, 16]: " + value);
            }
            gridRow.push_back(gridValue);
        } catch (const std::exception&) {
            handleException("Error: Invalid grid value: " + value);
        }
    }

    return gridRow;
}

void Parser::parseData() {
    std::string line;
    bool gridSection = false;

    while (std::getline(inputStream, line)) {
        if (line.empty()) continue;

        if (line.find("column sums:") != std::string::npos) {
            columnSums = parseSums(line, "column sums:");
        } else if (line.find("row sums:") != std::string::npos) {
            rowSums = parseSums(line, "row sums:");
        } else if (line == "grid:") {
            gridSection = true;
        } else if (gridSection) {
            grid.push_back(parseGridLine(line));
        } else {
            handleException("Error: Invalid format or unexpected line encountered.");
        }
    }

    // Validate required sections
    if (columnSums.empty() || rowSums.empty() || grid.empty()) {
        handleException("Error: Missing column sums, row sums, or grid data.");
    }

    // Validate exact size of row and column sums
    if (columnSums.size() != 4) {
        handleException("Error: Number of column sums must be exactly 4.");
    }
    if (rowSums.size() != 4) {
        handleException("Error: Number of row sums must be exactly 4.");
    }

    // Validate exact 4x4 grid
    if (grid.size() != 4) {
        handleException("Error: Grid must have exactly 4 rows.");
    }
    for (const auto& row : grid) {
        if (row.size() != 4) {
            handleException("Error: Each row in the grid must have exactly 4 values.");
        }
    }
}

// Getter methods
const std::vector<int>& Parser::getColumnSums() const {
    return columnSums;
}

const std::vector<int>& Parser::getRowSums() const {
    return rowSums;
}

const std::vector<std::vector<int>>& Parser::getGrid() const {
    return grid;
}
