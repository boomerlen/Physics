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
            Matrix(); // Fills matrix with 0s so it is never uninitialised
            virtual ~Matrix();
            // Basic arithmetic
            Matrix operator+(const Matrix&);
            Matrix operator-(const Matrix&);
            Matrix operator*(const std::complex<double>&);

            // Problem: don't know size of output matrix at compile-time
            Matrix operator*(const Matrix&);

            // Column operations using [] operator
            const PhysVector<rows>& operator[](int) const;
            PhysVector<rows>& operator[](int);

            // Row operations - operate slightly differently to the [] operator - returns copies not referneces
            PhysVector<cols> row(int) const;
            void row(int, const PhysVector<cols>&);

            /* I believe that all this can be done using [][] as [] will return an object that can have [] applied to it..?
            // Element operations
            std::complex<double> x(int, int) const;
            void x(int, int, const std::complex<double>&);
            */

            // Assignment
            void operator=(const Matrix&);
            void operator=(const PhysVector<rows>&);
            void operator=(const std::complex<double>&);

            // Gluing matrices together
            void operator|(const Matrix&);
            void operator|(const PhysVector<rows>&);

            // Undoing gluing
            void split(int final_col, int first_col = 0);

            // Dimension
            int get_rows() const;
            int get_cols() const;

            // More complicated matrix operations
            void compute_inverse();
            Matrix *get_inverse() const;

            void compute_transpose();
            Matrix<cols, rows> *get_transpose() const;

            void compute_determinant();
            std::complex<double> get_determinant() const;

            void eigensolve();
            void sort_eigensolutions();

            PhysVector<rows> *get_eigenvalues();
            Matrix *get_eigenvectors();

            void row_operation(const struct Row_Operation &row_op);

            void to_row_echelon();

            void print() const ; 

            void identity();
        protected:

        private:
            // Basic
            int num_cols; // Since we can add vectors easily

            std::vector<PhysVector<rows>> columns;

            // More complicated functions
            void algebraic_operation(const struct Algebraic_Op &alg_op);

            Matrix *inverse;
            Matrix *transpose;

            Matrix *eigenvectors;
            Matrix *eigenvalues;
    };

    // Functions which produce Matrices (non-member functions)
    template <int rows, int cols>
    Matrix<rows, cols> row_echelon_form(const Matrix<rows, cols>&);

    template <int n>
    Matrix<n, n> identity_matrix(); // Unsure about this

} // namespace phys

#include "../src/Matrix.tpp"

#endif // MATRIX_H
