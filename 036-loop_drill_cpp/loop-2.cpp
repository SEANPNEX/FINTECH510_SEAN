#include <iostream>
using namespace std;

int main() {

    std::cout << "Enter two integer values separated by a space (followed by 'Enter'):\n";

    int val1, val2;
    while (std::cin >> val1 >> val2)  {
        if (val1 < val2){
            std::cout << "the smaller value is: " << val1 << std::endl;
            std::cout << "the larger value is: " << val2 << std::endl;
        }
        else{
            std::cout << "the smaller value is: " << val2 << std::endl;
            std::cout << "the larger value is: " << val1 << std::endl;
        }

    }

    return 0;
}