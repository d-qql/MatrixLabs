//
// Created by d-qql on 10.12.2021.
//

#include "Matrix.hpp"
#include <iostream>
#include "../Overloads/Overloads.hpp"

Matrix::Matrix(int i_size, int j_size, const std::vector<Triplet> &data) : size_i(i_size), size_j(j_size) {

    elements.resize(size_i * size_j, 0);
    try {
        for (const auto &elm: data) {
            int index = elm.i * size_j + elm.j;
            if (index >= elements.size()) throw std::runtime_error("Число элементов больше заданного размера");
            elements[index] = elm.value;
        }
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
}

double Matrix::operator()(int i, int j) const {
    int index = i * size_j + j;
    try {
        if (index >= elements.size()) throw std::runtime_error("Индекс выходит за границы матрицы");
        return elements[index];
    }
    catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
    return 0;
}

Matrix Matrix::operator*(const Matrix &matrix) const {
    try {
        if (this->size_j != matrix.size_i) throw std::runtime_error("Размеры матриц непригодны для перемножения");
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
    Matrix res(size_i, matrix.size_j);
//    std::vector<Triplet> data;
    for (int i = 0; i < size_i; ++i) {
        for (int j = 0; j < matrix.size_j; ++j) {
            double sum = 0;
            for (int k = 0; k < size_j; ++k) {
                sum += elements[i * size_j + k] * matrix(k, j);
            }
//            data.push_back({i, j, sum});
            res.elements[i * matrix.size_j + j] = sum;
        }
    }
//    return Matrix{size_i, matrix.size_j, data};
    return res;
}

Matrix Matrix::operator+(const Matrix &matrix) const {
    try {
        if (this->size_j != matrix.size_j || this->size_i != matrix.size_i)
            throw std::runtime_error("Размеры матриц непригодны для сложения");
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
    std::vector<Triplet> data;
    for (int i = 0; i < size_i; ++i) {
        for (int j = 0; j < size_j; ++j) {
            data.push_back({i, j, this->operator()(i, j) + matrix(i, j)});
        }
    }
    return Matrix{size_i, size_j, data};
}

Matrix::Matrix(int i, int j) : size_i(i), size_j(j) {
    elements.resize(i * j);
}

Matrix Matrix::operator*(double k) const {
    Matrix res = *this;
    for (auto &elm: res.elements) elm *= k;
    return res;
}

int Matrix::getSizeI() const {
    return size_i;
}

int Matrix::getSizeJ() const {
    return size_j;
}

Matrix Matrix::operator-(const Matrix &matrix) const {
    return this->operator+(matrix * -1);
}

Matrix Matrix::adamarProduct(const Matrix &matrix) const {
    try {
        if (this->size_j != matrix.size_i) throw std::runtime_error("Размеры матриц непригодны для перемножения");
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
    Matrix res(size_i, size_j);
    for (int i = 0; i < size_i; ++i) {
        for (int j = 0; j < size_j; ++j) {
            res.elements[i * size_j + j] = this->operator()(i, j) * matrix(i, j);
        }
    }
    return res;
}

Matrix Matrix::buildIdentityMatrix(int size) {
    Matrix res(size, size);
    for (int i = 0; i < size; ++i) {
        res.elements[i * size + i] = 1;
    }
    return res;
}

void Matrix::swap_rows(int first, int second) {
    for (int j = 0; j < size_j; ++j) {
        std::swap(elements[first * size_j + j], elements[second * size_j + j]);
    }
}

int Matrix::triangulation() {
    int swapCount = 0;
    int min_size;
    if (size_i < size_j) min_size = size_i;
    else min_size = size_j;
    for (int i = 0; i < min_size - 1; ++i) {
        int iNonZero = colNonZero(i);
        if (std::abs(this->operator()(iNonZero, i)) > 1e-7) {
            swap_rows(i, iNonZero);
            ++swapCount;
        } else { continue; }
        for (int k = i + 1; k < min_size; ++k) {
            double coef = this->operator()(k, i) / this->operator()(i, i);
            for (int j = 0; j < min_size; ++j) {
                elements[k * size_j + j] -= this->operator()(i, j) * coef;
            }
        }
    }
    return swapCount;
}

int Matrix::colNonZero(int col) const {

    if (std::abs(this->operator()(col, col)) > 1e-7) return col;
    else {
        for (int i = col + 1; i < size_i; ++i) {
            if (std::abs(this->operator()(i, col)) > 1e-7) return i;

        }
    }
    return col;
}

double Matrix::trace() const {
    try {
        if (size_j != size_i) throw std::runtime_error("Матрица не квадратная");
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
    double trace = 0;
    for (int i = 0; i < size_i; ++i) {
        trace += this->operator()(i, i);
    }
    return trace;
}

double Matrix::determinant() const {
    try {
        if (size_j != size_i) throw std::runtime_error("Матрица не квадратная");
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
    Matrix matrix = *this;
    int swaps_count = matrix.triangulation();
    double determinant = 1;
    for (int i = 0; i < size_i; ++i) {
        determinant *= matrix(i, i);
    }
    return determinant;
}

double Matrix::frobeniusNorm() const {
    Matrix matrix = this->operator+(*this);
    double trace = matrix.trace();
    return std::sqrt(trace);
}

int Matrix::rank() const {
    Matrix matrix = *this;
    int swaps_count = matrix.triangulation();
    int rank = 0;
    int max_size = size_i < size_j ? size_i : size_j;
    for (int i = 0; i < max_size; ++i) {
        if (std::abs(matrix(i, i)) > 1e-7)
            ++rank;
    }
    return rank;
}

Matrix Matrix::transpose() const {
    Matrix res(size_j, size_i);
    for (int i = 0; i < size_i; ++i) {
        for (int j = 0; j < size_j; ++j) {
            res.elements[j * size_i + i] = this->operator()(i, j);
        }
    }
    return res;
}

Matrix Matrix::reverseMatrix() const {
    double det = this->determinant();
    try {
        if (std::abs(det) < 1e-7) throw std::runtime_error("Обратная матрица не существует, определитель равен 0");
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
    Matrix A(size_i, size_j);
    Matrix M(size_i - 1, size_j - 1);
    for (int i = 0; i < size_i; ++i) {
        for (int j = 0; j < size_j; ++j) {
            int i_index = 0;
            for(int k = 0; k < size_i; ++k){
                if(k == i) continue;
                int j_index = 0;
                for(int l = 0; l < size_j; ++l){
                    if(l == j) continue;
                    M.elements[i_index * (size_j - 1) + j_index] = this->operator()(k, l);
                    ++j_index;
                }
                ++i_index;
            }
            A.elements[i * size_j + j] = M.determinant() * std::pow(-1, i + j);
        }
    }
    A = A.transpose();
    return A * (1. / det);
}




