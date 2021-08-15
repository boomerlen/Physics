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

    PhysVector new_vec(2);
    new_vec.print();

    Scalar scalar1(1, 2);
    Scalar scalar2(2, 0);

    Scalar scalars[2] = {scalar1, scalar2};

    std::cout << "Scalars: ";
    scalar1.print();
    std::cout << std::endl;
    scalar2.print();

    new_vec = scalars;

    std::cout << "line 52";

    new_vec.print();

    return;
}

int main() {
    test_scalars();

    test_vectors();
    return 0;
}
