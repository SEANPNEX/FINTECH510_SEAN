#include <fstream>
#include <iostream>
#include <Eigen/Dense>
#include <string>
using namespace Eigen;
using namespace std;



Eigen::MatrixXd read_from_file(std::string filename) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Unable to open " << filename << std::endl;
        exit(EXIT_FAILURE);  // since we are in function, return would go back to main
    }

    int nrows, ncols = 0;
    input >> nrows;
    input >> ncols;

    Eigen::MatrixXd M(nrows,ncols);

    //std::cout << "nrows:" << nrows << "\n";
    //std::cout << "ncols:" << ncols << "\n";

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            input >>  M(i,j);
        }
    }
    
    input.close();

    //std::cout << M << "\n";

    return M;
}

int main(int argc, char* argv[]){
    if (argc !=3) {
        std::cerr << "Usage: ./gaussian A.txt B.txt\n";
		return EXIT_FAILURE;
    }
    std::string A_filename = argv[1];
    std::string B_filename = argv[2];
    MatrixXd A = read_from_file(A_filename);
    MatrixXd B_mat = read_from_file(B_filename);


    MatrixXd reshaped_B = B_mat.reshaped(B_mat.cols(), 1);
    VectorXd B = reshaped_B.col(0);
    VectorXd x = A.colPivHouseholderQr().solve(B);
    MatrixXd x_mat = x.transpose();
    std::cout << x_mat.rows() << " " << x_mat.cols() << std::endl;
    std::cout << x_mat << std::endl;

}