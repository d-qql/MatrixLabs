//
// Created by d-qql on 11.12.2021.
//

#ifndef LABMATRIX_VECTOR_HPP
#define LABMATRIX_VECTOR_HPP

#include "../Matrix/Matrix.hpp"

class Vector : public Matrix {
private:
    int size;

    Vector(const Matrix &matrix);

public:
    explicit Vector(int size);

    explicit Vector(const std::vector<double> &vector);

    Vector(int size, const std::vector<std::pair<int, double>> &data);
    using Matrix::operator*;

    double operator*(const Vector &vector) const;

    using Matrix::operator-;
    using Matrix::operator();

    double operator()(int i) const;

    Vector operator+(const Vector &vector) const;

    Vector operator-(const Vector &vector) const;

    int getSize() const;

    double euclidianNorm() const;
    double maxNorm() const;
    double angle(const Vector& vector) const;
};


#endif //LABMATRIX_VECTOR_HPP
