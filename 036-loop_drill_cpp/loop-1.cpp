#include <iostream>
using namespace std;

int main() {

    std::cout << "Enter two integer values separated by a space (followed by 'Enter'):\n";

    int val1, val2;
    while (std::cin >> val1 >> val2)  {
        std::cout << val1 << " " << val2 << std::endl;
    }

    return 0;
}