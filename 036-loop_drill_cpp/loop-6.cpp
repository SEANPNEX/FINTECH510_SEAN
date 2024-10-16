#include <iostream>
#include <limits> 
using namespace std;

int main() {

    std::cout << "Enter a number:\n";

    double val1;
    bool first_time = true;
    double smallest = std::numeric_limits<double>::max();
    double largest = std::numeric_limits<double>::min();
    while (std::cin >> val1 )  {
        if (first_time){
            std::cout << val1 << " smallest so far largest so far" << std::endl;
            smallest = val1;
            largest = val1;
            first_time = false;
            continue;
        }
        else if(val1 <= smallest ){
            smallest = val1;
            std::cout << val1 << " smallest so far" << std::endl;
            continue;
        }
        else if(val1 >= largest){
            largest = val1;
            std::cout << val1 << " largest so far" << std::endl;
            continue;
        }
        
    }

    return 0;
}