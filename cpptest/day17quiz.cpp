#include <iostream>
using std::cout;

class Point {

public:
    int x;
    int y;
};

void g() {
    cout << "g: " << std::hex << (size_t) &g << "\n";
    int a = 20;
    int b = 21;
    Point p;
    p.x = 5;
    cout << "a: " << a << ", b: " << b << ", p.x: " <<p.x << "\n";
    cout << "&a: " << &a <<  "\n";
    cout << "&b: " << &b << "\n";
    cout << "&p: " << &p << "\n";
    cout << "&p.x: " << &p.x << "\n";
    cout << "&p.y: " << &p.y << "\n";
}

void f(int c) {
    cout << "f: " << std::hex << (size_t) &f << "\n";
    g();
    int x[c];
    int a = 10;
    int b = 11;
    cout << "a: " << a << ", b: " << b << "\n";
    cout << "&a: " << &a <<  "\n";
    cout << "&b: " << &b << "\n";
    cout << "&x: " << &x << "\n";
}

int main() {
    cout << "main: " << std::hex << (size_t) &main << "\n";
    int a = 5;
    int b = 6;
    std::string pet = "cat";
    std::string pet2 = "dog";
    f(a);
    cout << "a: " << a << ", b: " << b << "\n";
    cout << "&a: " << &a << "\n";
    cout << "&b: " << &b << "\n";
    cout << "&pet: " << &pet << "\n";
    cout << "&pet2: " << &pet2 << "\n";
    cout << "pet2-pet1: " << &pet-&pet2 << "\n";
    
    cout << "main: " << std::hex << (size_t) &main << "\n";
    cout << "f: " << std::hex << (size_t) &f << "\n";
    cout << "g: " << std::hex << (size_t) &g << "\n";
}
