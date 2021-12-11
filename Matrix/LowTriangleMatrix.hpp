//
// Created by d-qql on 11.12.2021.
//

#ifndef LABMATRIX_LOWTRIANGLEMATRIX_HPP
#define LABMATRIX_LOWTRIANGLEMATRIX_HPP

#include "Matrix.hpp"
class LowTriangleMatrix: public Matrix {
public:
    LowTriangleMatrix(int size, const std::vector<Triplet> &data);
};


#endif //LABMATRIX_LOWTRIANGLEMATRIX_HPP
