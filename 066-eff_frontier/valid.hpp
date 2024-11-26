#ifndef VALID_H
#define VALID_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For EXIT_FAILURE
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <set>
#include <Eigen/Dense>
#include <regex>
#include "parse.hpp"
#include "parse_vec.hpp"
#define THRESHOLD 1e-6

bool isValidNumber(const std::string& str);

double safeStod(const std::string& str);

void validateCorrelationMatrix(const Eigen::MatrixXd& correlationMatrix, const std::vector<double>& stdROR);

void validateAssetData(const std::vector<std::string>& headers, const std::vector<double>& averageROR, const std::vector<double>& stdROR, const Eigen::MatrixXd& correlationMatrix); 

#endif