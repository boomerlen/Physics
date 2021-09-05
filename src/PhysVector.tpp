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
#include "PhysExcept.h"


namespace phys {

    template <int dim>
    PhysVector<dim>::PhysVector()
    {
        //ctor
        initialised = false;
    }

    template <int dim>
    PhysVector<dim>::PhysVector(std::complex<double> scalars[]) {
        // Passed an array of scalars to populate the vector
        // Conversion from array to PhysVector
        for (int i = 0; i < dim; i++) {
            entries[i] = scalars[i];
        }

        // TODO: Complain if scalars is not a full array
        initialised = true;
    }

    template <int dim>
    PhysVector<dim>::PhysVector(std::complex<double> scalar) {
        entries.fill(scalar);

        initialised = true;
    }

    template <int dim>
    PhysVector<dim>::~PhysVector()
    {
        //dtor
    }

    template <int dim>
    PhysVector<dim> PhysVector<dim>::operator+(const PhysVector& vec) const {
        // check dimension matches
        if (vec.dimension() != dim) {
            // Chuck an exception or something. This isn't allowed.
            throw Dimension_Mismatch();
        }

        PhysVector<dim> new_vec;

        // add element-wise
        for (int i = 0; i < dim; i++) {
            std::complex<double> new_s = entries[i] + vec[i];
            new_vec[i] = new_s;
        }

        new_vec.initialised = true;

        return new_vec;
    }

    template <int dim>
    PhysVector<dim> PhysVector<dim>::operator-(const PhysVector& vec) const {
        // check dimension matches
        if (vec.dimension() != dim) {
            // Chuck an exception or something. This isn't allowed.
            throw Dimension_Mismatch();
        }

        PhysVector<dim> new_vec;

        // add element-wise
        for (int i = 0; i < dim; i++) {
            std::complex<double> new_s = entries[i] - vec[i];
            new_vec[i] = new_s;
        }

        new_vec.initialised = true;

        return new_vec;
    }

    template <int dim>
    std::complex<double> PhysVector<dim>::operator*(const PhysVector& vec) const {
        // Forget if I care about dimension

        std::complex<double> result;

        for (int i = 0; i < dim; i++) {
            result = result + (vec[i] * entries[i]);
        }

        return result;
    }

    template <int dim>
    const std::complex<double>& PhysVector<dim>::operator[](int index) const {
        if (index < 0 || index >= dim) {
            throw Out_Of_Range();
        }
        return entries[index];
    }

    template <int dim>
    std::complex<double>& PhysVector<dim>::operator[](int index) {
        if (index < 0 || index >= dim) {
            throw Out_Of_Range();
        }

        return entries[index];
    }

    template <int dim>
    void PhysVector<dim>::operator=(const PhysVector& vec) {
        if (vec.dimension() != dim) {
            throw Dimension_Mismatch();
        }

        for (int i = 0; i < dim; i++) {
            entries[i] = vec[i];
        }

        initialised = true;
        return;
    }

    // TODO: Throw an exception or something if the vec is too small
    template <int dim>
    void PhysVector<dim>::operator=(const std::complex<double> vec[]) {
        // Copies first dim entries only
        for (int i = 0; i < dim; i++) {
            entries[i] = vec[i];
        }

        initialised = true;
        return;
    }

    template <int dim>
    void PhysVector<dim>::operator=(const std::complex<double>& scalar) {
        for (int i = 0; i < dim; i++) {
            std::cout << "Putting scalar into vector row " << i << std::endl;
            entries[i] = scalar;
        }

        initialised = true;
        return;
    }

    template <int dim>
    int PhysVector<dim>::dimension() const {
        return dim;
    }

    template <int dim>
    bool PhysVector<dim>::check_init() const {
        if (!initialised || entries.empty()) {
            return false;
        }

        return true;
    }

    template <int dim>
    void PhysVector<dim>::make_empty() {
        // puts 0 in every entry
        std::complex<double> zero = 0.0;
        entries.fill(zero);

        initialised = true;

        return;
    }

    template <int dim>
    void PhysVector<dim>::print() const {
        if (!initialised) {
            std::cout << "(empty vector)\n";
            return;
        }

        std::cout << "[";

        for (int i = 0; i < dim; i++) {
            std::cout << entries[i].real() << " + " << entries[i].imag() << "i";
            if (i != (dim - 1)) {
                std::cout << ", ";
            }
        }

        std::cout << "]";

        return;
    }

    // Instantisations
    // Problem - generating a class for each number is a waste of machine code!
    //template class PhysVector<2>;

} // namespace phys
