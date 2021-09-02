// Matrix.h
//
// Generic matrix with generic operations
// Probably will be rather complicated in the end lol
//
// Hugo Sebesta 2021

// TODO refactor like PhysVector (the more c++ like style)

#ifndef MATRIX_H
#define MATRIX_H

// STL
#include <complex>
#include <vector>

// My includes
#include "PhysVector.h"

namespace phys {

    struct Algebraic_Op {
        int row;
        std::complex<double> scalar;
    };

    struct Row_Operation {
        int outrow;
        std::vector<struct Algebraic_Op> operations;
    };

    template <int rows, int cols>
    class Matrix
    {
        public:
            Matrix();
            virtual ~Matrix();
            // Basic arithmetic
            Matrix operator+(const Matrix&);
            Matrix operator-(const Matrix&);
            Matrix operator*(const std::complex<double>&);

            // Problem: don't know size of output matrix at compile-time
            Matrix operator*(const Matrix&);

            // Column operations using [] operator
            const PhysVector& operator[](int) const;
            PhysVector& operator[](int);

            // Row operations
            PhysVector row(int) const;
            void row(int, const PhysVector&);

            /* I believe that all this can be done using [][] as [] will return an object that can have [] applied to it..?
            // Element operations
            std::complex<double> x(int, int) const;
            void x(int, int, const std::complex<double>&);
            */

            // Assignment
            void operator=(const Matrix&);
            void operator=(const PhysVector&);
            void operator=(const std::complex<double>&);

            // Gluing matrices together
            Matrix operator|(const Matrix&);
            Matrix operator|(const PhysVector&);

            // Dimension
            int get_rows() const;
            int get_cols() const;

            // More complicated matrix operations
            void compute_inverse();
            Matrix *get_inverse();

            std::complex determinant();

            void eigensolve();
            void sort_eigensolutions();

            PhysVector *get_eigenvalues();
            Matrix *get_eigenvectors();

            void row_operation(const struct Row_Operation &row_op);

            void to_row_echelon();

            void print() const;

            void identity();
        protected:

        private:
            // Basic
            int num_cols; // Since we can add vectors easily

            std::vector<PhysVector<rows>> columms;

            // More complicated functions
            void algebraic_operation(const stuct Algebraic_Op &alg_op);

            Matrix *inverse;

            Matrix *eigenvectors;
            Matrix *eigenvalues;
    };

    // Functions which produce Matrices (non-member functions)
    Matrix row_echelon_form(const Matrix&);
    Matrix identity_matrix(int);


} // namespace phys

#include "../src/Matrix.tpp"

#endif // MATRIX_H
