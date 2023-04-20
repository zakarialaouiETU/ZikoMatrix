#ifndef MATRIX_H
#define MATRIX_H

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <iostream>
#endif

template <int rows = 0, int cols = rows , typename T=int>
class Matrix {
private:
  int _rows=rows;
  int _cols=cols;
  T data[rows][cols]={};
public:
  Matrix(T (*arr)[cols]) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j] = arr[i][j];
      }
    }
  }
  
  Matrix<rows, cols , T>(const T (&arr)[rows * cols]) {
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < cols; j++) {
        data[i][j] = arr[i * cols + j];
      }
    }
  }
  ~Matrix<rows,cols,T>() {
    
  }
  Matrix<rows, cols , T> clone() const {
    Matrix< rows, cols , T > result = *this;
    return result;
  }
  T* operator[](int i) {
    return data[i];
  }

  T& operator()(int row, int col) {
    return data[row][col];
  }
  const T& operator()(int row, int col) const {
    return data[row][col];
  }
   static Matrix<rows,cols>id(){
       int arr[rows][rows] = {};
       for (int i = 0; i < rows; i++) {
           for (int j = 0; j < rows; j++) {
               arr[i][j] = (i == j) ? 1 : 0;
           }
       }
       return Matrix<rows, rows , T>(arr);
   }
   static Matrix<rows, cols,T> zeros() {
    T arr[rows][cols] = {};
    return Matrix<rows, cols , T>(arr);
  }
  static Matrix<rows, cols , T> ones() {
    int arr[rows][cols] = {};
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        arr[i][j] = 1;
      }
    }
    return Matrix<rows, cols , T>(arr);
  }
  void transpose() {
      _cols=rows;
      _rows=cols;
  T temp[cols][rows];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      temp[j][i] = data[i][j];
    }
  }
  // Copy the transpose matrix back to the original matrix
  for (int i = 0; i < _rows; i++) {
    for (int j = 0; j < _cols; j++) {
      data[i][j] = temp[i][j];
    }
  }
}
  Matrix< rows, cols ,T > operator+(const Matrix<rows, cols , T >& other) const {
    Matrix< rows, cols , T > result = this->clone();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result.data[i][j] += other.data[i][j];
      }
    }
    return result;
  }
  Matrix< rows, cols ,T > operator-(const Matrix<rows, cols , T >& other) const {
    Matrix< rows, cols , T > result = this->clone();
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        result.data[i][j] -= other.data[i][j];
      }
    }
    return result;
  }
  Matrix< rows, cols , T >& operator+=(const Matrix< rows, cols , T >& other) {
    *this = *this + other;
    return *this;
  }
  Matrix< rows, cols , T >& operator-=(const Matrix< rows, cols , T >& other) {
    *this = *this - other;
    return *this;
  }
  bool isSquare(){
      return rows==cols;
  }
  template <int cols2>
void hstack(const Matrix<rows, cols2, T>& other) {
  int new_cols = cols + cols2;
  T temp[rows][new_cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      temp[i][j] = data[i][j];
    }
    for (int j = 0; j < cols2; j++) {
      temp[i][j + cols] = other.data[i][j];
    }
  }
  
  _cols = new_cols;
}
  void print() const {
#if defined(ARDUINO)
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        Serial.print(data[i][j]);
        Serial.print(' ');
      }
      Serial.println();
    }
#else
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        std::cout << data[i][j] << ' ';
      }
      std::cout << '\n';
    }
#endif
  }
};

#endif // MATRIX_H
