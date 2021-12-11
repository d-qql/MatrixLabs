#include <iostream>
#include "Vector/Vector.hpp"
#include "Matrix/Matrix.hpp"
#include "Overloads/Overloads.hpp"

int main() {
    std::vector<Triplet> input = {{0, 0, 1},
                                  {0, 1, 3},
                                  {1, 0, 2},
                                  {1, 1, 10}};
    std::vector<Triplet> input1 = {{0, 0, 1},
                                   {0, 1, 3},
                                   {0, 2, 1},
                                   {1, 0, 2},
                                   {1, 1, 10},
                                   {1, 2, 1},
};
    Matrix matrix2(2, 3, input1);
    std::vector<double> vecData = {1, 2};
    Matrix matrix1(2, 2, input);
    Vector vector(vecData);
//    std::cout << matrix1 * matrix1;
//    std::cout << vector;
//    std::cout << matrix1 * 2 << 2 * matrix1;
//    std::cout << matrix1 * vector;
//    std::cout << vector * 2;
//    std::cout << vector - vector * 2;
//    std::cout << matrix1 - matrix1 * 2;
//    std::cout << matrix1.adamarProduct(matrix1);
//    std::cout << Matrix::buildIdentityMatrix(3);
//    std::cout << ' ' << matrix2.rank();
//    std::cout << vector.euclidianNorm() << " " << vector * vector <<std::endl;
//    std::cout << vector.angle(vector) << std::endl;
//    std::cout<<matrix1.reverseMatrix();
Matrix m("/home/d-qql/CLionProjects/lab1forStepan/data.txt");
std::cout<<m << m.rank() << m.transpose();
    return 0;
}
