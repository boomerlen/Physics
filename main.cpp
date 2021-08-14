// Entry point

// First goal of this is to make it easier to implement eigen calculations in 3D
// i.e create ways of moving from 3D representations of coordinates to a 1D representation of a matrix


#include <iostream>

#include "Scalar.h"


int main() {
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

    return 0;
}
