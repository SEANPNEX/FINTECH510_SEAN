#include "IntMatrix.hpp"

int main(void) {
    IntMatrix a(0,0);
    for (int i = 0; i < a.getRows(); i++) {
        for (int j = 0; j < a.getColumns(); j++) {
            a[i][j] = i+j;
        }
    }
    std::cout << "a is:\n" << a << std::endl;

    IntMatrix b(a);
    std::cout << "b is:\n" << a << std::endl;

    if (a == b) {
        std::cout << "a and b have the same contents" << std::endl;
    }
    else {
        std::cout << "a and b have different contents" << std::endl;
    }

    for (int i = 0; i < b.getRows(); i++) {
        for (int j = 0; j < b.getColumns(); j++) {
            b[i][j] += i*j;
        }
    }
    std::cout << "Now, b is:\n" << b << std::endl;
    if (a == b) {
        std::cout << "a and b have the same contents" << std::endl;
    }
    else {
        std::cout << "a and b have different contents" << std::endl;
    }

    IntMatrix c;
    std::cout << "c is:\n" << c << std::endl;
    c = a + b;

    std::cout << "this Line has problem" << std::endl;
    std::cout << c << std::endl;
    std::cout << "Now, c is:\n" << c << std::endl;
    
    return EXIT_SUCCESS;
}
