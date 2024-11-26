#ifndef PARSE_VEC_HPP
#define PARSE_VEC_HPP

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

class ParserVec {
public:
    ParserVec(std::ifstream& in);
    ~ParserVec();

    void parseData();

    const std::vector<std::string>& getHeaders() const;
    const std::vector<double>& getAverageROR() const;
    const std::vector<double>& getStdROR() const;

private:
    std::ifstream& inputStream;
    std::vector<std::string> headers;
    std::vector<double> averageROR;
    std::vector<double> stdROR;

    void handleException(const std::string& errorMsg);
};

#endif
