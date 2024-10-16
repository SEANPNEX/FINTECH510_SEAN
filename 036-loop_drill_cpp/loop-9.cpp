#include <iostream>
#include <limits> 
#include <vector>     
using namespace std;
#include <string>
using std::string;
using std::vector;


int main() {

    std::cout << "Enter a double value followed by a space then a unit (cm,m,in,ft)::\n";
    double val1, originVal;
    string unit;
    bool first_time = true;
    double smallest = std::numeric_limits<double>::max();
    double largest = std::numeric_limits<double>::min();
    double multiplier;  
    int number = 0;
    vector<double> nums;
    while (std::cin >> originVal >> unit )  {
        // std::cout << "number read: " << originVal << std::endl;
        // std::cout << "unit read: " << unit << std::endl;
        multiplier = 1;
        if (unit == "ft"){
            multiplier = 0.3048;
        }
        else if (unit == "cm"){
            multiplier = 0.01;
        }
        else if (unit == "m"){
            multiplier = 1;
        }
        else if (unit == "in"){
            multiplier = 0.0254;
        }
        else{
            cout << "bad unit: " << unit << endl;
            continue;
        }
        val1 = originVal * multiplier;
        nums.push_back(val1);
        number += 1;

        if (first_time){
            std::cout << originVal << unit << " smallest so far largest so far" << std::endl;
            smallest = val1;
            largest = val1;
            first_time = false;
        }
        else if(val1 <= smallest ){
            smallest = val1;
            std::cout << originVal << unit << " smallest so far" << std::endl;
        }
        else if(val1 >= largest){
            largest = val1;
            std::cout << originVal << unit << " largest so far" << std::endl;
        }

    }
    double sum = 0;
    for (double value : nums) {
        sum += value;
    }
    std::cout << "smallest: " << smallest << std::endl;
    std::cout << "largest: " << largest << std::endl;
    std::cout << "number: " << number << std::endl;
    std::cout << "sum: " << sum << std::endl;

    return 0;
}