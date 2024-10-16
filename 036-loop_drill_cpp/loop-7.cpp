#include <iostream>
#include <limits> 
using namespace std;
#include <string>
using std::string;

int main() {

    std::cout << "Enter a double value followed by a space then a unit (cm,m,in,ft)::\n";
    double val1, originVal;
    string unit;
    bool first_time = true;
    double smallest = std::numeric_limits<double>::max();
    double largest = std::numeric_limits<double>::min();
    double multiplier;  
    while (std::cin >> originVal >> unit )  {
        // std::cout << "number read: " << originVal << std::endl;
        // std::cout << "unit read: " << unit << std::endl;
        multiplier = 1;
        if (unit == "ft"){
            multiplier = 30.48;
        }
        else if (unit == "cm"){
            multiplier = 1;
        }
        else if (unit == "m"){
            multiplier = 100;
        }
        else if (unit == "in"){
            multiplier = 2.54;
        }
        val1 = originVal * multiplier;
        if (first_time){
            std::cout << originVal << unit << " smallest so far largest so far" << std::endl;
            smallest = val1;
            largest = val1;
            first_time = false;
            continue;
        }
        else if(val1 <= smallest ){
            smallest = val1;
            std::cout << originVal << unit << " smallest so far" << std::endl;
            continue;
        }
        else if(val1 >= largest){
            largest = val1;
            std::cout << originVal << unit << " largest so far" << std::endl;
            continue;
        }
        
    }

    return 0;
}