// Generic matrix with generic operations

#ifndef MATRIX_H
#define MATRIX_H

#include "Scalar.h"
#include "PhysVector.h"

class Matrix
{
    public:
        Matrix(int m, int n);
        virtual ~Matrix();

        Matrix operator+(const &Matrix);
        Matrix operator-(const &Matrix);
        Matrix operator*(const &Scalar);

        Matrix operator*(const &Matrix);

        PhysVector operator[](const &Matrix);
        Scalar operator[][](const &Matrix);

        void operator=(const &Matrix);
        void operator=(const &PhysVector);
        void operator=(const &Scalar);

        Matrix operator|(const &Matrix);
        Matrix operator|(const &PhysVector);

        // More complicated matrix operations
        void eigensolve();

        void print();

        void identity();
    protected:

    private:
        int dim;

        PhysVector cols[];

        Matrix reduced_form;
        Matrix eigenvectors;
        Matrix eigenvalues;
};

#endif // MATRIX_H
