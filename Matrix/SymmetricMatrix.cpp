//
// Created by d-qql on 11.12.2021.
//

#include "SymmetricMatrix.hpp"

SymmetricMatrix::SymmetricMatrix(int size, const std::vector<Triplet> &data) : Matrix(size, size) {
    try {
        for (const auto &elm: data) {
            int index = elm.i * this->getSizeJ() + elm.j;
            elements[index] = elm.value;
        }
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (elements[i * size + j] != elements[j * size + i])
                    throw std::runtime_error("Данные не соответствуют симметричной матрице");
            }
        }
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
}
