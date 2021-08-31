// Ordered_Set.h
//
// This is now deprecated and unused
// Underlying data structure for storing scalars (or something else) in vectors, matrices etc
// Implemented as a linked list
//
// Hugo Sebesta 2021

#ifndef ORDERED_SET_H
#define ORDERED_SET_H

// Note that element assignment must be done with x() not with operator[]
#include "Node_T.h"

// A fresh ordered_set will be of the desired length but will not be initialised
// Values can be set but not read until they have been set.
// Setting a value copies its value. It is not necessary to retain an original if it is to be
// stored in an Ordered_Set.

template <class T>
class Ordered_Set
{
    public:
        // Initialisation
        Ordered_Set(int);
        Ordered_Set(int, T[]);

        virtual ~Ordered_Set();

        // Element access
        void x(int n, T);
        T x(int n) const;

        // For 1-3 dimensioned sets
        void y(T);
        T y() const;
        void z(T);
        T z() const;

        // Relevant operators
        void operator=(const Ordered_Set&);
        void operator=(const T);

        int dimension() const;

        // Safety checks
        bool initialised() const;

    protected:

    private:
        int dim;

        Node_T<T> *head;
};

#endif // ORDERED_SET_H
