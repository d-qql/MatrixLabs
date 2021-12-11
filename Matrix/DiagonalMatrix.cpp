//
// Created by d-qql on 11.12.2021.
//

#include "DiagonalMatrix.hpp"

DiagonalMatrix::DiagonalMatrix(int size, const std::vector<Triplet> &data) : Matrix(size, size) {
    try {
        for (const auto &elm: data) {
            if (elm.i != elm.j) throw std::runtime_error("Данные не соответствуют диагональной матрице");
            int index = elm.i * this->getSizeJ() + elm.j;
            elements[index] = elm.value;
        }
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
}

DiagonalMatrix::DiagonalMatrix(const std::vector<double> &data) : Matrix(static_cast<int>(data.size()),
                                                                         static_cast<int>(data.size())) {
    for (int i = 0; i < data.size(); ++i) {
        elements[i * data.size() + i] = data[i];
    }
}
