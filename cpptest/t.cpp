#include <iostream>

class MemoryBlock {
public:
    MemoryBlock(size_t size = 10): _size(size) {
        _data = new char[size];
    }
    
    ~MemoryBlock() {
        delete[] _data;
    }

private:
    char* _data;
    size_t _size;

};

int main() {
    MemoryBlock b1(100);
    MemoryBlock b2;
    b2 = b1;
}