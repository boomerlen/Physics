#include <iostream>

#include "PhysVector.h"
#include "Scalar.h"

PhysVector::PhysVector(int n)
{
    //ctor
    dim = n;

    uninitialised = true;
}

PhysVector::PhysVector(int n, Scalar scalars[]) {
    // Passed an array of scalars to populate the vector
    // Conversion from array to PhysVector
    dim = n;

    for (int i = 0; i < n; i++) {
        entries[i] = scalars[i];
    }

    uninitialised = false;
}

PhysVector::~PhysVector()
{
    //dtor
}

PhysVector PhysVector::operator+(const PhysVector& vec) const {
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

PhysVector PhysVector::operator-(const PhysVector& vec) const {
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

Scalar PhysVector::operator*(const PhysVector& vec) const {
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

void PhysVector::operator=(const PhysVector& vec) {
    if (vec.dimension() != dim) {
        // no
        return;
    }

    for (int i = 0; i < dim; i++) {
        entries[i] = vec[i];
    }

    uninitialised = false;
    return;
}

// TODO: Throw an exception or something if the vec is too small
void PhysVector::operator=(const Scalar vec[]) {
    // Copies first dim entries only
    for (int i = 0; i < dim; i++) {
        entries.push_back(vec[i]);
        entries.erase(i);
    }

    uninitialised = false;
    return;
}

void PhysVector::operator=(const Scalar& scalar) {
    for (int i = 0; i < dim; i++) {
        entries[i] = scalar;
    }

    uninitialised = false;
    return;
}

int PhysVector::dimension() const {
    return dim;
}

void PhysVector::make_empty() {
    // puts 0 in every entry
    Scalar zero(0, 0);

    for (int i = 0; i < dim; i++) {
        entries[i] = zero;
    }

    uninitialised = false;
    return;
}

void PhysVector::print() const {
    if (uninitialised) {
        std::cout << "(empty vector)\n";
        return;
    }

    std::cout << "(";

    for (int i = 0; i < dim; i++) {
        entries[i].print();
        std::cout << ", ";
    }

    std::cout << ")";

    return;
}
