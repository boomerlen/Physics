// PhysVector.cpp
//
// Implementation of the PhysVector type
// A general complex-valued vector of dimension n
// Based on std::complex and std::array (the size of a vector is known without any doubt at all times)
//
// Hugo Sebesta 2021

#include <iostream>
#include <complex>
#include <array>

#include "PhysVector.h"

namespace phys {

    PhysVector::PhysVector(int n)
    {
        //ctor
        dim = n;

        entries = std::array<std::complex<double>, n>;

        initialised = false;
    }

    PhysVector::PhysVector(int n, std::complex<double> scalars[]) {
        // Passed an array of scalars to populate the vector
        // Conversion from array to PhysVector
        dim = n;

        entries = std::array<std::complex<double>, n>;

        for (int i = 0; i < n; i++) {
            entries[i] = scalars[i];
        }

        // TODO: Complain if scalars is not a full array
        initialised = true;
    }

    PhysVector::PhysVector(int n, std::complex<double> scalar) {
        dim = n;

        entries = std::array<std::complex<double>, n>

        entries.fill(scalar);

        initialised = true;
    }

    PhysVector::~PhysVector()
    {
        //dtor
    }

    PhysVector PhysVector::operator+(const PhysVector& vec) const {
        // check dimension matches
        if (vec.dimension() != dim) {
            // Chuck an exception or something. This isn't allowed.
            throw Dimension_Mismatch();
        }

        PhysVector new_vec(dim);

        // add element-wise
        for (int i = 0; i < dim; i++) {
            std::complex<double> new_s = entries[i] + vec[i];
            new_vec[i] = new_s;
        }

        new_vec.initialised = true;

        return new_vec;
    }

    PhysVector PhysVector::operator-(const PhysVector& vec) const {
        // check dimension matches
        if (vec.dimension() != dim) {
            // Chuck an exception or something. This isn't allowed.
            throw Dimension_Mismatch();
        }

        PhysVector new_vec(dim);

        // add element-wise
        for (int i = 0; i < dim; i++) {
            std::complex<double> new_s = entries[i] - vec[i];
            new_vec[i] = new_s;
        }

        new_vec.initialised = true;

        return new_vec;
    }

    std::complex<double> PhysVector::operator*(const PhysVector& vec) const {
        // Forget if I care about dimension

        std::complex<double> result;

        for (int i = 0; i < dim; i++) {
            result = result + (vec[i] * entries[i]);
        }

        return result;
    }

    std::complex& PhysVector::operator[](int index) const {
        return &entries[index];
    }

    void PhysVector::operator=(const PhysVector& vec) {
        if (vec.dimension() != dim) {
            throw Dimension_Mismatch();
            return;
        }

        for (int i = 0; i < dim; i++) {
            entries[i] = vec[i];
        }

        initialised = true;
        return;
    }

    // TODO: Throw an exception or something if the vec is too small
    void PhysVector::operator=(const std::complex<double> vec[]) {
        // Copies first dim entries only
        for (int i = 0; i < dim; i++) {
            entries[i] = vec[i];
        }

        initialised = true;
        return;
    }

    void PhysVector::operator=(const std::complex<double>& scalar) {
        for (int i = 0; i < dim; i++) {
            entries[i] = scalar;
        }

        initialised = true;
        return;
    }

    int PhysVector::dimension() const {
        return dim;
    }

    bool PhysVector::check_init() const {
        if (!initialised || entries->empty()) {
            return false;
        }

        return true;
    }

    void PhysVector::make_empty() {
        // puts 0 in every entry
        std::complex<double> zero = 0.0;
        entries.fill(zero)

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
            entries[i].print();
            if (i != (dim - 1)) {
                std::cout << ", ";
            }
        }

        std::cout << "]";

        return;
    }

} // namespace phys
