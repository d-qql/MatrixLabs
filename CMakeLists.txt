cmake_minimum_required(VERSION 3.21)
project(LABMATRIX)

set(CMAKE_CXX_STANDARD 14)

add_executable(LABMATRIX main.cpp Matrix/Matrix.cpp Matrix/Matrix.hpp Matrix/Triplet.hpp Vector/Vector.cpp Vector/Vector.hpp Overloads/Overloads.cpp Overloads/Overloads.hpp Matrix/TopTriangleMatrix.cpp Matrix/TopTriangleMatrix.hpp Matrix/LowTriangleMatrix.cpp Matrix/LowTriangleMatrix.hpp Matrix/DiagonalMatrix.cpp Matrix/DiagonalMatrix.hpp Matrix/SymmetricMatrix.cpp Matrix/SymmetricMatrix.hpp )
