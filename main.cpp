// main.cpp
//
// Entry point
// This is a small physics package I am attempting to write
//
// Hugo Sebesta 2021

// First goal of this is to make it easier to implement eigen calculations in 3D
// i.e create ways of moving from 3D representations of coordinates to a 1D representation of a matrix
// Actually first goal is to have a working basic linear algebra package

#include <iostream>

#include "Scalar.h"
#include "PhysVector.h"
#include "Ordered_Set.h"
#include "PhysExcept.h"

#include "Numerical.h"


void test_scalars() {
    // Do some scalar operations
    Scalar scalar1(1, 2);
    scalar1.print();

    Scalar scalar2(3, 4);
    scalar2.print();

    Scalar scalar3 = scalar1 + scalar2;

    scalar3.print();

    // Do some other cool stuff
    std::cout << "With magnitude: " << scalar3.abs() << std::endl;
    std::cout << "And conjugate: ";
    scalar3.conj().print();
    std::cout << "And argument: " << scalar3.argument() << std::endl;

    return;
}



void test_vectors() {
    std::cout << "Vectors" << std::endl;

    // Make some scalars
    Scalar scalars1[2];
    scalars1[0] = Scalar(1, 2);
    scalars1[1] = Scalar{2, 0};

    std::cout << "Scalar 1 defined" << std::endl;

    Scalar scalars2[2];
    scalars2[0] = Scalar(3, 4);
    scalars2[1] = Scalar(0, 2);

    std::cout << "Scalar 2 defined" << std::endl;

    PhysVector vec1(2, scalars1);
    PhysVector vec2(2, scalars2);

    std::cout << "Vectors 1 and 2 defined" << std::endl;

    PhysVector vec3(2);
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



void test_sets() {
    std::cout << "Calling test_Sets" << std::endl;
    Ordered_Set<int> s1(4);

    std::cout << "71" << std::endl;

    int ints[4] = {1, 2, 3, 4};
    Ordered_Set<int> s2(4, ints);
    for (int i = 0; i < 4; i++) {
        std::cout << "s2: " << i << "th entry: " << s2.x(i) << std::endl;
    }

    std::cout << "76" << std::endl;

    s1.x(1, 200);
    std::cout << s1.x(1) << std::endl;

    s1 = s2;
    std::cout << "82" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << s1.x(i) << std::endl;
    }
    std::cout << "89" << std::endl;
    s1 = 10;

    for (int i = 0; i < 4; i++) {
        std::cout << s1.x(i) << std::endl;
    }

    std::cout << "Dimesions: " << s1.dimension() << std::endl;
} 

int main() {
    // Tests
    test_scalars();
    test_vectors();
    test_sets();

    std::cout << "Integral of sinx from 0 to pi: " << num_integral_sinx(0.0, 3.14159, 0.001) << std::endl;
    return 0;
}
