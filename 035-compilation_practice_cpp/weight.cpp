#include <iostream>
using std::cin;
using std::cout;

// implements a BMI calculator: https://en.wikipedia.org/wiki/Body_mass_index
// note: three actual errors exist in this file (the compile may report more)

// cin represents "standard input", primarily used to receive input
// from the console.

int main() {
    double height;

    cout << "Enter a height in meters: ";
    cin >> height;

    cout << "Enter a weight in kilograms: ";
    cin >> weight;

    double bmi = weight / height * height);

    cout << "The BMI is: " << bmi;


    if (bmi < 18.5) {
        cout << ", underweight\n";
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << ", normal\n";
    } else if (bmi >= 25.0 && bmi < 29.9) {
        cout << ", overweight\n";
    } else {
        cout << ", obese\n";
    

    return 0;
}