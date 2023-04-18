#ifndef MATRIX_H
#define MATRIX_H

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <iostream>
#endif

template <int rows = 0, int cols = 0 , typename T=int>
class Matrix {
private:
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
/*
  Matrix< rows, cols , T > operator-(const Matrix< rows, cols , T >& other) const {
    Matrix< rows, cols , T > result = this->clone();
    result -= other;
    return result;
  }
*/
  Matrix< rows, cols , T >& operator+=(const Matrix< rows, cols , T >& other) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j] += other.data[i][j];
      }
    }
    return *this;
  }

  Matrix< rows, cols , T >& operator-=(const Matrix< rows, cols , T >& other) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        data[i][j] -= other.data[i][j];
      }
    }
    return *this;
  }
  void print() const {
#if defined(ARDUINO)
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        Serial.print(data[i][j]);
        Serial.print(' ');
      }
      Serial.println();
    }
#else
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        std::cout << data[i][j] << ' ';
      }
      std::cout << '\n';
    }
#endif
  }
};

#endif // MATRIX_H
