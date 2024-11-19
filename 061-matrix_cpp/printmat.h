#ifndef __PRINTMAT_H__
#define __PRINTMAT_H__
    #include <iostream>
    #include <Eigen/Dense>
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include <cmath>
    #include <vector>
    using namespace std;
    void printmat(int rows, int cols, Eigen::MatrixXd m){
    cout << rows << " "<< cols << endl;
    cout << m << endl;
}
#endif