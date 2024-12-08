#ifndef PARSE_HPP
#define PARSE_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Parser {
private:
    std::ifstream& inputStream;
    std::vector<int> columnSums; // Stores column sums
    std::vector<int> rowSums;    // Stores row sums
    std::vector<std::vector<int>> grid; // Stores the grid matrix

    void handleException(const std::string& errorMsg);

    std::vector<int> parseSums(const std::string& line, const std::string& prefix);
    std::vector<int> parseGridLine(const std::string& line);

public:
    Parser(std::ifstream& in);
    ~Parser();

    void parseData();


    const std::vector<int>& getColumnSums() const;
    const std::vector<int>& getRowSums() const;
    const std::vector<std::vector<int>>& getGrid() const;
};

#endif 