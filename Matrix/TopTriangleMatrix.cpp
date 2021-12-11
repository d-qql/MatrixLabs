//
// Created by d-qql on 11.12.2021.
//

#include "TopTriangleMatrix.hpp"

TopTriangleMatrix::TopTriangleMatrix(int size, const std::vector<Triplet> &data): Matrix(size, size) {
    try {
        for (const auto &elm: data) {
            if (elm.i > elm.j) throw std::runtime_error("Данные не соответствуют верхне-треугольной матрице");
            int index = elm.i * this->getSizeJ() + elm.j;
            elements[index] = elm.value;
        }
    } catch (std::exception &exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
    }
}
