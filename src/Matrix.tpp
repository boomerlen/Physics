// Matrix.cpp
//
// Implementations of the Matrix class (and some non-member functions associated)
//
// Hugo Sebesta 2021

#include <complex>
#include <vector>
#include <iostream>

#include "Matrix.h"
#include "PhysExcept.h"

namespace phys {

    // Non-member functions

    // Returns the given matrix after row reductions
    template <int rows, int cols>
    Matrix<rows, cols> row_echelon_form(const Matrix<rows, cols> &in_matrix);

    // Returns the identity matrix of the given dimension
    template <int n>
    Matrix<n, n> identity_matrix() {
        Matrix<n, n> id_matrix;

        for (int i = 0; i < n; i++) {
            id_matrix[i][i] = 1.0;
        }

        return id_matrix;
    }

    // Member functions

    template <int rows, int cols>
    Matrix<rows, cols>::Matrix() {
        num_cols = cols;

        inverse = nullptr;
        transpose = nullptr;
        eigenvectors = nullptr;
        eigenvalues = nullptr;

        // Fill columns with 0ed physvectors
        std::complex<double> zero = 0.0;

        for (int i = 0; i < cols; i++) {
            columns.push_back(zero);
        }
    }

    template <int rows, int cols>
    Matrix<rows, cols>::~Matrix() {
        // dtor
        if (inverse != nullptr) {
            delete inverse;
        }

        if (transpose != nullptr) {
            delete transpose;
        }

        if (eigenvectors != nullptr) {
            delete eigenvectors;
        }

        if (eigenvalues != nullptr) {
            delete eigenvalues;
        }
    }


    // Column operations
    template <int rows, int cols>
    const PhysVector<rows>& Matrix<rows, cols>::operator[](int index) const {
        if (index < 0 || index >= num_cols) {
            throw Out_Of_Range();
        }

        return columns[index];
    }

    template <int rows, int cols>
    PhysVector<rows>& Matrix<rows, cols>::operator[](int index) {
        if (index < 0 || index >= num_cols) {
            throw Out_Of_Range();
        }

        return columns[index];
    }

    // Computes the transpose of the matrix. Stores it in tranpose*
    template <int rows, int cols>
    void Matrix<rows, cols>::compute_transpose() {
        if (cols != num_cols) {
            // This may not be a huge issue in which case I will skip this
            throw Matrix_Glue_Failure();
        }

        // Make a new matrix with opposite rows and cols
        Matrix<cols, rows> *transposed_matrix = new Matrix<cols, rows>();

        // Grab column vectors by iterating along original matrix cols
        for (int i = 0; i < num_cols; i++) {
            for (int j = 0; j < rows; j++) {
                transposed_matrix[i][j] = columns[j][i];
            }
        }

        transpose = transposed_matrix;
    }

    template <int rows, int cols>
    Matrix<cols, rows> *Matrix<rows, cols>::get_transpose() const {
        if (transpose == nullptr) {
            throw Not_Initialised();
        }

        return transpose;
    }

    // Prints the matrix
    // Will throw Not_Initialised if a transpose has not yet been computed.
    template <int rows, int cols>
    void Matrix<rows, cols>::print() const {
        // Ensure on new line
        std::cout << std::endl;

        // Get transposed version of this matrix
        Matrix<cols, rows> *matrix_transposed = get_transpose();

        // Print each vector of the transposed matrix on their own line (row vectors)
        for (int i = 0; i < num_cols; i++) {
            matrix_transposed[i].print();
            std::cout << std::endl;
        }
    }

    // Makes the matrix into the identity of the correct dimension
    // Only for square matrix - will throw Dimension_Mismatch() otherwise
    template <int rows, int cols>
    void Matrix<rows, cols>::identity() {
        if (rows != num_cols) {
            // bad
            throw Dimension_Mismatch();
        }

        // Use = operator
        *this = identity_matrix<rows>(); // probably will cause error
    }
}
