// main.cpp
//
// Entry point
// This is a small physics package I am attempting to write
//
// Hugo Sebesta 2021

// First goal of this is to make it easier to implement eigen calculations in 3D
// i.e create ways of moving from 3D representations of coordinates to a 1D representation of a matrix
// Actually first goal is to have a working basic linear algebra package

// STL
#include <iostream>
#include <complex>

// My includes
#include "PhysVector.h"
#include "PhysExcept.h"
#include "Numerical.h"

// To use 1.0i e.g. as the imaginary unit
using namespace std::complex_literals;

void test_vectors() {
    std::cout << "Vectors" << std::endl;

    // Make some scalars
    std::complex<double> scalars1[2];
    scalars1[0] = 1.0 + 2.0i;
    scalars1[1] = 2.0;

    std::cout << "Scalar 1 defined" << std::endl;

    std::complex<double> scalars2[2];
    scalars2[0] = 3.0 + 4.0i;
    scalars2[1] = 0.0 + 2.0i;

    std::cout << "Scalar 2 defined" << std::endl;

    phys::PhysVector<2> vec1(scalars1);
    phys::PhysVector<2> vec2(scalars2);

    std::cout << "Vectors 1 and 2 defined" << std::endl;

    phys::PhysVector<2> vec3;
    std::cout << "66" << std::endl;
    vec3 = vec1 + vec2;
    vec1.print();
    std::cout << " + ";
    vec2.print();
    std::cout << " = ";
    vec3.print();
    std::cout << std::endl;

    return;
}

int main() {
    // Tests
    test_vectors();

    std::cout << "Integral of sinx from 0 to pi: " << num_integral_sinx(0.0, 3.14159, 0.001) << std::endl;
    return 0;
}
