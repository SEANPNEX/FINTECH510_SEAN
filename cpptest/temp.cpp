#include <iostream>

template <typename T>
T rateOfReturn(T initialValue, T currentValue) {
    T rate = (currentValue - initialValue) / initialValue * 100;
    return rate;
}

int main() {
    double initialValue = 1.0;
    double currentValue = 1.5;
    double rate = rateOfReturn(initialValue, currentValue);

    std::cout << "Rate of Return: " << rate << "%" << std::endl;
    return 0;
}
