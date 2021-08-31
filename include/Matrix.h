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

    class Matrix
    {
        public:
            Matrix(int, int);
            virtual ~Matrix();
            /* WIP: Needs the refactoring
            // Basic arithmetic
            Matrix operator+(const Matrix&);
            Matrix operator-(const Matrix&);
            Matrix operator*(const std::complex<double>&);

            Matrix operator*(const Matrix&);

            // Column operations
            PhysVector col(int) const;
            void col(int, const PhysVector&);

            // Row operations
            PhysVector row(int) const;
            void row(int, const PhysVector&);

            // Element operations
            std::complex<double> x(int, int) const;
            void x(int, int, const std::complex<double>&);

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
            int m; // an m x n matrix has m rows and n cols
            int n;

            std::vector<PhysVector> cols;

            // More complicated functions
            void algebraic_operation(const stuct Algebraic_Op &alg_op);

            Matrix *inverse;

            Matrix *eigenvectors;
            Matrix *eigenvalues;
            */
    };

    // Functions which produce Matrices (non-member functions)
    Matrix row_echelon_form(const Matrix&);
    Matrix identity_matrix(int);


} // namespace phys
#endif // MATRIX_H
