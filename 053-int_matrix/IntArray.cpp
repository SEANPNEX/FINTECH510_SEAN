#include "IntArray.hpp"
#include <assert.h>
#include <ostream>
#include <iostream>
using namespace std;

IntArray::IntArray() {
    data = nullptr;
    numElements = 0;
}
IntArray::IntArray(int n) {
    numElements = n;
    data = new int[numElements];
}

IntArray::IntArray(const IntArray & rhs) : numElements(rhs.numElements) {
    data = new int[numElements];
    std::copy(rhs.data, rhs.data + numElements, data);
}

IntArray::~IntArray() {
    delete[] data;
}

IntArray & IntArray::operator=(const IntArray & rhs) {
    if (this != &rhs) {
        IntArray temp(rhs); 
        std::swap(data, temp.data);  
        std::swap(numElements, temp.numElements);
    }
    return *this;
}


const int & IntArray::operator[](int index) const {
    if (index < 0 || index >= numElements){
        throw std::out_of_range("INdedx out of bounds");
    }
    return data[index];
}
int & IntArray::operator[](int index) {
    if (index < 0 || index >= numElements){
        throw std::out_of_range("INdedx out of bounds");
    }
    return data[index];
}

int IntArray::size() const {
    return numElements;
}

bool IntArray::operator==(const IntArray & rhs) const {
    if (numElements != rhs.size()) return false;
    return std::equal(data, data + numElements, rhs.data);
}

bool IntArray::operator!=(const IntArray & rhs) const {
    return !(*this == rhs);
}

std::ostream & operator<<(std::ostream & s, const IntArray & rhs) {
    s << "{" << "";
    for (int i = 0; i<rhs.size(); ++i){
        s << rhs[i]<<"";
        if (i != rhs.size()-1) {
            s << ","<<" ";
        }
    }
    s << "}";
    return s;
}
