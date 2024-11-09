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
    for (int i = 0; i < r; ++i) {
        rows[i] = new IntArray(c); 
    }

}

IntMatrix::IntMatrix(const IntMatrix & rhs) : numRows(rhs.numRows), numColumns(rhs.numColumns) {
    rows = new IntArray*[numRows];
    for (int i = 0; i < numRows; ++i) {
        rows[i] = new IntArray(numColumns);
        for (int j = 0; j < numColumns; ++j) {
            (*rows[i])[j] = rhs[i][j];
        }
    }
}


IntMatrix::~IntMatrix() {
    if (rows != nullptr) {
        for (int i = 0; i < numRows; ++i) {
            if (rows[i] != nullptr) {
                delete rows[i];
            }
        }
        delete[] rows; 
        rows = nullptr; 
    }
}

IntMatrix &IntMatrix::operator=(const IntMatrix & rhs) {
    if (this != &rhs) {
        // Free old memory
        for (int i = 0; i < numRows; ++i) {
            delete rows[i];
        }
        delete[] rows;

        // Copy new data
        numRows = rhs.numRows;
        numColumns = rhs.numColumns;
        rows = new IntArray*[numRows];
        for (int i = 0; i < numRows; ++i) {
            rows[i] = new IntArray(numColumns);
            for (int j = 0; j < numColumns; ++j) {
                (*rows[i])[j] = rhs[i][j];
            }
        }
    }
    return *this;
}

int IntMatrix::getRows() const {
    return numRows;
}
int IntMatrix::getColumns() const {
    return numColumns;
}
const IntArray & IntMatrix::operator[](int index) const {
    if (index < 0 || index >= numRows){
        throw std::out_of_range("Indedx out of bounds");
    }
    return *rows[index];
}
IntArray & IntMatrix::operator[](int index){
    if (index < 0 || index >= numRows){
        throw std::out_of_range("Indedx out of bounds");
    }
    return *rows[index];
}



bool IntMatrix::operator==(const IntMatrix & rhs) const {
    if (numRows != rhs.getRows()) return false;
    if (numColumns != rhs.getColumns()) return false;
    for (int i = 0; i < numRows; ++i){
        if (*rows[i]==rhs[i]){
            continue;
        }
        return false;   
    }
    return true;
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {
    if (numRows != rhs.getRows() || numColumns != rhs.getColumns()) {
        throw std::invalid_argument("Dimensions do not match");
    }

    IntMatrix result(numRows, numColumns);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            result[i][j] = (*rows[i])[j] + rhs[i][j];
        }
    }

    return result;
}



std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
    s << "[" << " ";
    for (int i = 0; i < rhs.getRows(); ++i){
        s << rhs[i];
        if (i!=rhs.getRows()-1){
            s << ",\n" << "";
        }
    }
    s << " ]" << "";
    return s;
}
