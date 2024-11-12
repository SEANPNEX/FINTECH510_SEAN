#ifndef __PARSE_H__
#define __PARSE_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For EXIT_FAILURE
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include "Matrix.hpp"

using std::string;
using std::vector;
using namespace std;


class Parser{
private:
    ifstream& inputStream;
    vector<string> headers;
    Matrix<double> data;

public:
    Parser(ifstream &in);
    ~Parser();
    void parseHeader();
    void parseData();
    vector<string> getHeaders();
    Matrix<double> getMatrix() const;
    vector<double> parseline(const string &line, vector<double> &lastValidValues);
    void handleException(const string& errorMsg);
};

#endif
