#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#include "StockData.hpp"
using namespace std;

std::ifstream openFile(std::string name) { 
    std::ifstream in(name);
    if (!in.is_open()) {
        std::cerr << "Unable to open " << name << std::endl;
        exit(EXIT_FAILURE);  // since we are in function, return would go back to main
    }
    return in;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " stockDataFile\n";
        return EXIT_FAILURE;
    }

    std::ifstream inputFile = openFile(argv[1]);

    std::vector<StockData> data;
    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        data.push_back(StockData::fromString(line));
    }
   
    // Insert assignment code
    vector<double> ror = {};
    for (size_t i = 1; i < data.size(); ++i) {
        double ror_single = data[i].rateOfReturn(data[i - 1]); 
        ror.push_back(ror_single);
    }

    // // Print rates of return
    // std::cout << "Rates of Return:" << std::endl;
    // for (const auto& r : ror) {
    //     std::cout << std::fixed << std::setprecision(6) << r << std::endl;
    // }

    double average = std::accumulate(ror.begin(), ror.end(), 0.0) / ror.size();
    auto max_it = std::max_element(ror.begin(), ror.end());
    auto min_it = std::min_element(ror.begin(), ror.end());
    std::string max_date = data[std::distance(ror.begin(), max_it) + 1].date;
    std::string min_date = data[std::distance(ror.begin(), min_it) + 1].date;


    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average Daily Return: " << (average) << "%" << std::endl;
    std::cout << "Largest Gain: " << (*max_it ) << "% on " << max_date << std::endl;
    std::cout << "Largest Loss: " << (*min_it) << "% on " << min_date << std::endl;


    return EXIT_SUCCESS;
}