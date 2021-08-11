#include "PhysVector.h"
#include "Scalar.h"

PhysVector::PhysVector(int n)
{
    //ctor
    dim = n;
}

PhysVector::PhysVector(int n, Scalar scalars[]) {
    // Passed an array of scalars to populate the vector
    // Conversion from array to PhysVector
    dim = n;

    for (int i = 0; i < n; i++) {
        entries[i] = scalars[i];
    }
}

PhysVector::~PhysVector()
{
    //dtor
}

PhysVector PhysVector::operator+(const &PhysVector vec) {
    // check dimension matches
    if (vec.dimension() != dim) {
        // Chuck an exception or something. This isn't allowed.
    }

    PhysVector new_vec(dim);

    // add element-wise
    for (int i = 0; i < dim; i++) {
        new_vec[i] = entries[i] + vec[i];
    }

    return new_vec;
}

PhysVector PhysVector::operator-(const &PhysVector vec) {
    // check dimension matches
    if (vec.dimension() != dim) {
        // Chuck an exception or something. This isn't allowed.
    }

    PhysVector new_vec(dim);

    // add element-wise
    for (int i = 0; i < dim; i++) {
        new_vec[i] = entries[i] - vec[i];
    }

    return new_vec;
}

Scalar operator*(const &PhysVector vec) {
    // Forget if I care about dimension

    Scalar result;

    for (int i = 0; i < dim; i++) {
        result = result + (vec[i] * entries[i]);
    }

    return result;
}

Scalar &PhysVector::operator[](int i) {
    return entries[i];
}

const Scalar &PhysVector::operator[](int i) const {
    return entries[i];
}
