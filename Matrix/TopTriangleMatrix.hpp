//
// Created by d-qql on 11.12.2021.
//

#ifndef LAB1FORSTEPAN_TOPTRIANGLEMATRIX_HPP
#define LAB1FORSTEPAN_TOPTRIANGLEMATRIX_HPP

#include "Matrix.hpp"

class TopTriangleMatrix: public Matrix{
public:
    TopTriangleMatrix(int size, const std::vector<Triplet> &data);
};


#endif //LAB1FORSTEPAN_TOPTRIANGLEMATRIX_HPP
