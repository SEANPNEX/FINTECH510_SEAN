#include <iostream>
#include <vector>

int main() {
    // Initialize a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use an iterator to traverse and print elements in the vector
    std::vector<int>::iterator it;
    for (it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the element
    }

    std::cout << std::endl;
    return 0;
}


