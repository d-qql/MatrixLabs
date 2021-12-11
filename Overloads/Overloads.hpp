//
// Created by d-qql on 11.12.2021.
//

#ifndef LAB1FORSTEPAN_OVERLOADS_HPP
#define LAB1FORSTEPAN_OVERLOADS_HPP
#include "../Matrix/Matrix.hpp"
#include "../Vector/Vector.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Matrix& matrix);
Matrix operator*(double k, const Matrix& matrix);

#endif //LAB1FORSTEPAN_OVERLOADS_HPP
