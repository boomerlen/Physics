#ifndef ORDERED_SET_H
#define ORDERED_SET_H

// Used to store Scalars in a vector or columns (vectors) in a matrix
// Implemented as a linked list

// Note that element assignment must be done with x() not with operator[]
#include "Node_T.h"

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

    protected:

    private:
        int dim;

        Node_T<T> *head;
};

#endif // ORDERED_SET_H
