#include "parse_vec.hpp"
#include "valid.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

ParserVec::ParserVec(std::ifstream& in) : inputStream(in) {
    if (!inputStream.good()) {
        std::cerr << "Error: Input stream is not valid for reading." << std::endl;
        exit(EXIT_FAILURE);
    }
}

ParserVec::~ParserVec() {}

void ParserVec::parseData() {
    std::string line;

    while (std::getline(inputStream, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        std::istringstream ss(line);
        std::string header, avgRORStr, stdRORStr;

        if (!std::getline(ss, header, ',')) {
            handleException("Error: Missing header value.");
        }

        if (!std::getline(ss, avgRORStr, ',')) {
            handleException("Error: Missing AverageROR value.");
        }

        if (!std::getline(ss, stdRORStr, ',')) {
            handleException("Error: Missing StdROR value.");
        }

        // Parse AverageROR
        double avgROR;
        try {
            avgROR = safeStod(avgRORStr);
        } catch (const std::invalid_argument&) {
            handleException("Error: Invalid AverageROR value.");
        }

        // Parse StdROR
        double std_ROR;
        try {
            std_ROR = safeStod(stdRORStr);
        } catch (const std::invalid_argument&) {
            handleException("Error: Invalid StdROR value.");
        }

        // Store the parsed values
        headers.push_back(header);
        averageROR.push_back(avgROR);
        stdROR.push_back(std_ROR);
    }
}

const std::vector<std::string>& ParserVec::getHeaders() const {
    return headers;
}

const std::vector<double>& ParserVec::getAverageROR() const {
    return averageROR;
}

const std::vector<double>& ParserVec::getStdROR() const {
    return stdROR;
}

void ParserVec::handleException(const std::string& errorMsg) {
    std::cerr << errorMsg << std::endl;
    exit(EXIT_FAILURE);
}
