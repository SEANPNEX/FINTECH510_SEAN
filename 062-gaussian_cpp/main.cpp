#include <fstream>
#include <iostream>
#include <Eigen/Dense>

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


}
