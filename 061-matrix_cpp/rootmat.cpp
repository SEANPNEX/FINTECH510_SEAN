#include <iostream>
#include <Eigen/Dense>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include "printmat.h"
using namespace std;



int main(){
    int rows, cols;
    cin >> rows >> cols;
    Eigen::MatrixXd m(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> m(i, j);
            m(i, j)=sqrt(m(i, j));
        }
    }
    printmat(rows, cols, m);
}
