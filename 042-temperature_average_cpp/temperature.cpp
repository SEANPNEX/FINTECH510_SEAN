#include <iostream>
#include <vector>     
#include <algorithm> 
#include <iomanip>
#include <string>
#include <numeric>
using std::string;
using std::vector;
using namespace std;

#include <fstream>

ifstream openFile(std::string name) { // abstract into a function
    std::ifstream in(name);
    if (!in.is_open()) {
        std::cerr << "Unable to open " << name << std::endl;
        exit(EXIT_FAILURE);  
    }
    return in;
}

void print_receipt(int min, int max, double avg){
    cout << "Minimum Temperature:"  << setw(6) << min  << endl;
    cout << "Maximum Temperature:" << setw(6) << max << endl;
    cout << "Max Temp as octal:  "   << setw(6) << oct << max << endl;
    cout << "Max Temp as hex:    "   << setw(6) << hex << max << endl;
    cout << "Average Temperature:"  << setw(6) << fixed << setprecision(2)  << avg << endl;
}

double calculate_avg(vector<double> vec){
    double sum = 0;
    double n = vec.size();
    for(double i:vec){
        sum += i;
    }
    return sum/n;
}

int main(int argc, char* argv[]) {
    if(argc<2){
        cerr << "No filename got" << endl;
        exit(EXIT_FAILURE);
    }
    string filename = argv[1];
    ifstream in = openFile(filename);
    vector<double> lines;
    string line;
    while (getline(in, line)){
        double tmp = stod(line);
        lines.push_back(tmp);
    }
    double min = *min_element(lines.begin(), lines.end());
    double max = *max_element(lines.begin(), lines.end());
    double avg = calculate_avg(lines);
    print_receipt(min, max, avg);
}
