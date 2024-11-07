#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector> 
#include <algorithm>
using std::string;
using std::vector;
using namespace std;

vector<string> rotate(vector<string> matrix){
    
    vector<string> result = matrix;
    // transpose
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            result[j][i]=matrix[i][j];
        }
    }
    
    for(int i=0;i<10;++i){
        reverse(result[i].begin(),result[i].end());
    }

    return result;
}

void printMatrix(const vector<string>& matrix) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    ifstream in;

    if (argc != 2) {
        cerr << "Usage: rotateMatrix inputFileName\n";
        return EXIT_FAILURE;
    }

    in.open(argv[1], std::ifstream::in);
    if (!in.is_open()) {
        cerr << "Unable to open input file: " << argv[1] << "\n";
        return EXIT_FAILURE;
    }
    vector<string> lines;
    string line;
    while (getline(in, line)){
        if (!line.empty() && (line.back() == '\n' || line.back() == '\r')) {
            line.erase(line.length() - 1);
        }
        if (!line.empty() && line.back() == '\r') {
            line.erase(line.length() - 1);
        }
        if(line.length()!=10){
            cerr << "Not 10*10 matrix" << endl;
            return EXIT_FAILURE;
        }
        lines.push_back(line);
    }
    if (lines.size()!=10){
        cerr << "Not 10*10 matrix" << endl;
        return EXIT_FAILURE;
    }
    vector<string> rotatedMatrix = rotate(lines);
    printMatrix(rotatedMatrix);
    in.close();
    return EXIT_SUCCESS;
}
