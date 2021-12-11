//
// Created by d-qql on 11.12.2021.
//

#include "Vector.hpp"
#include <iostream>


Vector::Vector(int size, const std::vector<std::pair<int, double>> &data) : size(size),
                                                                            Matrix(size, 1,
                                                                                   tripletVecFromPairVec(data)) {
}

double Vector::operator*(const Vector &vector) const {
    return Matrix::operator*(vector)(0, 0);
}

double Vector::operator()(int i) const {
    return operator()(i, 0);
}

Vector Vector::operator+(const Vector &vector) const {
    return Matrix::operator*(vector);
}

Vector::Vector(const std::vector<double> &vector) : Matrix(static_cast<int>(vector.size()), 1),
                                                    size(static_cast<int>(vector.size())) {
    for (int i = 0; i < vector.size(); ++i) {
        this->elements[i] = vector[i];
    }
}

Vector::Vector(int size) : size(size), Matrix(size, 1) {

}

Vector Vector::operator-(const Vector &vector) const {
    return Matrix::operator-(vector);
}

Vector::Vector(const Matrix &matrix) : Matrix(matrix), size(matrix.getSizeI()) {
}

int Vector::getSize() const {
    return size;
}

double Vector::euclidianNorm() const {
    double sum = 0;
    for (auto elm: this->elements) sum += elm * elm;
    return std::sqrt(sum);
}

double Vector::maxNorm() const {
    double max = std::abs(elements[0]);
    for(auto elm: elements){
        if(std::abs(elm) > max) max = std::abs(elm);
    }
    return max;
}

double Vector::angle(const Vector &vector) const {
    return std::acos(this->operator*(vector) / this->euclidianNorm() / vector.euclidianNorm());
}

