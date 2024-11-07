#include "IntMatrix.hpp"

IntMatrix::IntMatrix(){
    numRows = 0;
    numColumns = 0;
    rows = nullptr;
}
IntMatrix::IntMatrix(int r, int c) {
    numRows = r;
    numColumns = c;
    rows = new IntArray*[r];
    for (int i = 0; i < r; ++i){
        rows[i] = new IntArray
    }

}
IntMatrix::IntMatrix(const IntMatrix & rhs)  {

}
IntMatrix::~IntMatrix() {

}
IntMatrix &IntMatrix::operator=(const IntMatrix & rhs) {

}
int IntMatrix::getRows() const {

}
int IntMatrix::getColumns() const {

}
const IntArray & IntMatrix::operator[](int index) const {

}
IntArray & IntMatrix::operator[](int index){

}



bool IntMatrix::operator==(const IntMatrix & rhs) const {

}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {

}

std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
}
