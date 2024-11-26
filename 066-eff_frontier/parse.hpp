#ifndef PARSE_HPP
#define PARSE_HPP

#include <fstream>
#include <vector>
#include <string>
#include <Eigen/Dense>

class Parser {
public:
    Parser(std::ifstream& in);
    ~Parser();

    void parseData();
    Eigen::MatrixXd getMatrix() const;

private:
    std::ifstream& inputStream;
    Eigen::MatrixXd data;

    std::vector<double> parseLine(const std::string& line);
    void handleException(const std::string& errorMsg);
};

#endif
