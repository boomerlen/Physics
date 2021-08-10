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

    scalar3.print()

    return 0;
}
