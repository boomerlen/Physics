// Entry point

// First goal of this is to make it easier to implement eigen calculations in 3D
// i.e create ways of moving from 3D representations of coordinates to a 1D representation of a matrix
// Actually first goal is to have a working basic linear algebra package

#include <iostream>

#include "include/Scalar.h"
#include "include/PhysVector.h"


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
    vec3 = vec1 + vec2;

    vec3.print();

    return;
}

int main() {
    test_scalars();

    test_vectors();
    return 0;
}
