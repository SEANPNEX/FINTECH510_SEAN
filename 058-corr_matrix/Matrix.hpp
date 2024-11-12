#ifndef __T_MATRIX_H__
#define __T_MATRIX_H__

#include <iostream>
#include <vector>
#include <stdexcept> // For std::out_of_range
#include <iomanip>

using namespace std;

// Matrix class template definition
template <typename T>
class Matrix {
private:
    int numRows;
    int numColumns;
    vector<vector<T>> rows;

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix & rhs);
    ~Matrix();
    Matrix & operator=(const Matrix & rhs);
    void pushBackRow(const vector<T> & newRow);
    int getRows() const;
    int getColumns() const; 
    const vector<T> & operator[](int index) const;
    vector<T> & operator[](int index);
    bool operator==(const Matrix & rhs) const;
    Matrix operator+(const Matrix & rhs) const;
};

// Template function implementations
template <typename T>
Matrix<T>::Matrix() : numRows(0), numColumns(0), rows(vector<vector<T>>()) {}

template <typename T>
Matrix<T>::Matrix(int r, int c) : numRows(r), numColumns(c) {
    rows = vector<vector<T>>(numRows, vector<T>(numColumns));
}

template <typename T>
Matrix<T>::Matrix(const Matrix & rhs) : numRows(rhs.numRows), numColumns(rhs.numColumns), rows(rhs.rows) {}

template <typename T>
Matrix<T>::~Matrix() {}

template <typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix & rhs) {
    if (this != &rhs) {
        numRows = rhs.numRows;
        numColumns = rhs.numColumns;
        rows = rhs.rows;
    }
    return *this;
}

template <typename T>
int Matrix<T>::getRows() const {
    return numRows;
}

template <typename T>
int Matrix<T>::getColumns() const {
    return numColumns;
}

template <typename T>
const vector<T> & Matrix<T>::operator[](int index) const {
    if (index < 0 || index >= numRows) {
        throw std::out_of_range("Index out of bounds");
    }
    return rows[index];
}

template <typename T>
vector<T> & Matrix<T>::operator[](int index) {
    if (index < 0 || index >= numRows) {
        throw std::out_of_range("Index out of bounds");
    }
    return rows[index];
}

template <typename T>
bool Matrix<T>::operator==(const Matrix & rhs) const {
    return (numRows == rhs.numRows && numColumns == rhs.numColumns && rows == rhs.rows);
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix & rhs) const {
    if (numRows != rhs.getRows() || numColumns != rhs.getColumns()) {
        throw std::invalid_argument("Dimensions do not match");
    }
    Matrix result(numRows, numColumns);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            result[i][j] = rows[i][j] + rhs.rows[i][j];
        }
    }
    return result;
}


template <typename T>
void transpose(Matrix<T> &b) {
    if (b.getRows() == 0)
        return;
    Matrix<T> trans_vec(b.getColumns(), b.getRows());

    for (int i = 0; i < b.getRows(); i++) {
        for (int j = 0; j < b.getColumns(); j++) {
            trans_vec[j][i] = b[i][j]; 
        }
    }

    b = trans_vec; 
}

template <typename T>
void Matrix<T>::pushBackRow(const vector<T> & newRow) {
    if (static_cast<int>(newRow.size()) != numColumns && numRows != 0) {
        throw std::invalid_argument("New row must have the same number of columns as existing rows");
    }
    if (numRows == 0) {
        
        numColumns = newRow.size();
    }
    rows.push_back(newRow);
    numRows++;
}


template<typename T>
std::ostream & operator<<(std::ostream & s, const vector<T> & rhs) {
    if(rhs[0]<0){
        s << "";
    }else{
        s << " ";
    }
    for (size_t i = 0; i < rhs.size(); ++i) {
        s << std::fixed << std::setprecision(4) << rhs[i]; 
        if ((i < rhs.size() -1) && (rhs[i+1] < 0)){
            s << ",";
            continue;
        }
        if (i != rhs.size() - 1) {
            s << ", ";
            
        }
    }
    s << "";
    return s;
}

template <typename T>
std::ostream & operator<<(std::ostream & s, const Matrix<T> & rhs) {
    s << "[";
    for (int i = 0; i < rhs.getRows(); ++i) {
        s << std::fixed << std::setprecision(4) << rhs[i]; // Use fixed for four decimal places
        if (i != rhs.getRows() - 1) {
            s << "\n ";
        }
    }
    s << "]";
    return s;
}

#endif // __T_MATRIX_H__
