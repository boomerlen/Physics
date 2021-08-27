// PhysVector.cpp
//
// Implementation of the PhysVector type
// A general complex-valued vector of dimension n
//
// Hugo Sebesta 2021

#include <iostream>

#include "PhysVector.h"
#include "Ordered_Set.h"
#include "Scalar.h"

PhysVector::PhysVector(int n)
{
    //ctor
    dim = n;

    entries = new Ordered_Set<Scalar>(n);

    initialised = false;
}

PhysVector::PhysVector(int n, Scalar scalars[]) {
    // Passed an array of scalars to populate the vector
    // Conversion from array to PhysVector
    dim = n;

    entries = new Ordered_Set<Scalar>(dim, scalars);

    // TODO: Complain if scalars is not a full array

    initialised = true;
}

PhysVector::~PhysVector()
{
    //dtor
    delete entries;
}

PhysVector PhysVector::operator+(const PhysVector& vec) const {
    // check dimension matches
    if (vec.dimension() != dim) {
        // Chuck an exception or something. This isn't allowed.
    }

    PhysVector new_vec(dim);

    // add element-wise
    for (int i = 0; i < dim; i++) {
        Scalar new_s = entries->x(i) + vec.x(i);
        new_vec.x(i, new_s);
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
        Scalar new_s = entries->x(i) - vec.x(i);
        new_vec.x(i, new_s);
    }

    return new_vec;
}

Scalar PhysVector::operator*(const PhysVector& vec) const {
    // Forget if I care about dimension

    Scalar result;

    for (int i = 0; i < dim; i++) {
        result = result + (vec.x(i) * entries->x(i));
    }

    return result;
}

Scalar PhysVector::x(int i) const {
    return entries->x(i);
}

void PhysVector::x(int i, Scalar s) {
    entries->x(i, s);
    return;
}

void PhysVector::operator=(const PhysVector& vec) {
    if (vec.dimension() != dim) {
        // no
        // TODO: chuck an exception
        return;
    }

    for (int i = 0; i < dim; i++) {
        entries->x(i, vec.x(i));
    }

    initialised = true;
    return;
}

// TODO: Throw an exception or something if the vec is too small
void PhysVector::operator=(const Scalar vec[]) {
    // Copies first dim entries only
    for (int i = 0; i < dim; i++) {
        entries->x(i, vec[i]);
    }

    initialised = true;
    return;
}

void PhysVector::operator=(const Scalar& scalar) {
    for (int i = 0; i < dim; i++) {
        entries->x(i, scalar);
    }

    initialised = true;
    return;
}

int PhysVector::dimension() const {
    return dim;
}

void PhysVector::make_empty() {
    // puts 0 in every entry
    Scalar zero(0, 0);

    for (int i = 0; i < dim; i++) {
        entries->x(i, zero);
    }

    initialised = true;
    return;
}

void PhysVector::print() const {
    if (!initialised) {
        std::cout << "(empty vector)\n";
        return;
    }

    std::cout << "[";

    for (int i = 0; i < dim; i++) {
        entries->x(i).print();
        if (i != (dim - 1)) {
            std::cout << ", ";
        }
    }

    std::cout << "]";

    return;
}
