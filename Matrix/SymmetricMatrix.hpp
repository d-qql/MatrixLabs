//
// Created by d-qql on 11.12.2021.
//

#ifndef LABMATRIX_SYMMETRICMATRIX_HPP
#define LABMATRIX_SYMMETRICMATRIX_HPP

#include "Matrix.hpp"

class SymmetricMatrix: public Matrix{
    SymmetricMatrix(int size, const std::vector<Triplet> &data);
};


#endif //LABMATRIX_SYMMETRICMATRIX_HPP
