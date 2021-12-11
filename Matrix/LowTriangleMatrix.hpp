//
// Created by d-qql on 11.12.2021.
//

#ifndef LAB1FORSTEPAN_LOWTRIANGLEMATRIX_HPP
#define LAB1FORSTEPAN_LOWTRIANGLEMATRIX_HPP

#include "Matrix.hpp"
class LowTriangleMatrix: public Matrix {
public:
    LowTriangleMatrix(int size, const std::vector<Triplet> &data);
};


#endif //LAB1FORSTEPAN_LOWTRIANGLEMATRIX_HPP
