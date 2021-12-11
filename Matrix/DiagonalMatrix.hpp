//
// Created by d-qql on 11.12.2021.
//

#ifndef LABMATRIX_DIAGONALMATRIX_HPP
#define LABMATRIX_DIAGONALMATRIX_HPP

#include "Matrix.hpp"
class DiagonalMatrix: public Matrix{
DiagonalMatrix(int size, const std::vector<Triplet> &data);
explicit DiagonalMatrix(const std::vector<double>& data);
};


#endif //LABMATRIX_DIAGONALMATRIX_HPP
