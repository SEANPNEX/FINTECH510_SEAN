#include <iostream>

// Code From
// Programming: Principles and Practice Using C++ (2nd Edition)
// Bjarne Stroustrup

using namespace std;

int main() {
    try {
        int i=0; 
        int j=10;
        while (i<10) {
            ++j;
            i += 9;
        }
        if (j<i) {
            cout << "Success!\n";
        }
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}