//
// Created by d-qql on 10.12.2021.
//

#ifndef LAB1FORSTEPAN_MATRIX_HPP
#define LAB1FORSTEPAN_MATRIX_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include "Triplet.hpp"
#include <cmath>

class Matrix {
private:
    int size_i;
    int size_j;

    void swap_rows(int i, int j);

    int colNonZero(int col) const;

    int triangulation();


protected:
    std::vector<double> elements;

public:
//    Matrix() = default;
    Matrix(int i, int j);

    Matrix(int i, int j, const std::vector<Triplet> &data);

    double trace() const;

    double determinant() const;
    double frobeniusNorm() const;
    int rank() const;
    int getSizeI() const;

    int getSizeJ() const;

    double operator()(int i, int j) const;

    Matrix operator*(const Matrix &matrix) const;

    Matrix operator+(const Matrix &matrix) const;

    Matrix operator-(const Matrix &matrix) const;

    Matrix operator*(double k) const;

    Matrix adamarProduct(const Matrix &matrix) const;

    static Matrix buildIdentityMatrix(int size);

};


#endif //LAB1FORSTEPAN_MATRIX_HPP
