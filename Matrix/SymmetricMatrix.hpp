//
// Created by d-qql on 11.12.2021.
//

#ifndef LAB1FORSTEPAN_SYMMETRICMATRIX_HPP
#define LAB1FORSTEPAN_SYMMETRICMATRIX_HPP

#include "Matrix.hpp"

class SymmetricMatrix: public Matrix{
    SymmetricMatrix(int size, const std::vector<Triplet> &data);
};


#endif //LAB1FORSTEPAN_SYMMETRICMATRIX_HPP
