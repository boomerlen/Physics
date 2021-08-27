// Matrix.h
//
// Generic matrix with generic operations
// Probably will be rather complicated in the end lol
//
// Hugo Sebesta 2021

#ifndef MATRIX_H
#define MATRIX_H

#include "Scalar.h"
#include "PhysVector.h"

struct Algebraic_Op {
    int row;
    Scalar scalar;
};

struct Row_Operation {
    int outrow;
    struct Algebraic_Op operations[];
};

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
        void sort_eigensolutions();

        PhysVector *get_eigenvalues();
        Matrix *get_eigenvectors();

        void row_operation(struct Row_Operation row_op);

        void to_row_echelon();

        void print();

        void identity();
    protected:

    private:
        // Basic
        int dim;

        PhysVector cols[];

        // More complicated functions
        void algebraic_operation(stuct Algebraic_Op alg_op);

        Matrix eigenvectors;
        Matrix eigenvalues;
};

// Functions which produce Matrices (non-member functions)
Matrix row_echelon_form(Matrix);
Matrix identity_matrix(int);

#endif // MATRIX_H
