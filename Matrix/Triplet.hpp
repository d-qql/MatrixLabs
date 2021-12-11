//
// Created by d-qql on 10.12.2021.
//

#ifndef LABMATRIX_TRIPLET_HPP
#define LABMATRIX_TRIPLET_HPP

#include <utility>
#include <vector>

struct Triplet{
    int i;
    int j;
    double value;
};
static std::vector<Triplet> tripletVecFromPairVec(const std::vector<std::pair<int, double>>& pairVec){
    std::vector<Triplet> result;
    result.reserve(pairVec.size());
    for(auto const& elm: pairVec){
        result.push_back({elm.first, 1, elm.second});
    }
    return result;
}
#endif //LABMATRIX_TRIPLET_HPP
