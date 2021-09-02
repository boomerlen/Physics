// Matrix.cpp
//
// Implementations of the Matrix class (and some non-member functions associated)
//
// Hugo Sebesta 2021

#include <complex>
#include <vector>

#include "Matrix.h"
#include "PhysExcept.h"

namespace phys {

    // Non-member functions

    // Returns the given matrix after row reductions
    Matrix row_echelon_form(const Matrix &in_matrix);

    // Returns the identity matrix of the given dimension
    Matrix identity_matrix(int n) {
        Matrix<n, n> id_matrix;

        for (int i = 0; i < n; i++) {
            id_matrix[i][i] = 1.0;
        }

        return id_matrix;
    }

    // Member functions

    template <int rows, int cols>
    Matrix<rows, cols>::Matrix()
    {
        num_cols = cols;

        // Put aa 0ed PhysVector in each col
        for (int i = 0; i < n; i++) {
            columns[i] = PhysVector<rows>(0.0)
        }
    }

    template <int rows, int cols>
    Matrix<rows, cols>::~Matrix()
    {
        //dtor
        delete inverse;
        delete eigenvectors;
        delete eigenvalues;
    }

    // Basic arithmetic

    // Adds elementwise. Only for equally sized matrices
    Matrix Matrix::operator+(const Matrix& matrix) {
        if (n != matrix.get_cols() || m != matrix.get_rows()) {
            throw Dimension_Mismatch();
        }

        // Add each element
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

            }
        }
    }

    // Column operations (easy)
    PhysVector Matrix::col(int col) const {
        // Returns the PhysVector corresponding to that column
        if (col > n) {
            throw Out_Of_Range();
        }

        return cols.x(col);
    }

    // Assigns a new column
    void Matrix::col(int col, const PhysVector &new_col) {
        if (col > n) {
            throw Out_Of_Range();
        }

        cols.x(col, new_col);

        return;
    }

    // Row operations (hardest)

    // Element operations (harder)
    Scalar Matrix::x(int row, int col) const {
        // Returns the element at the rowth row and colth col
        if (row > m || col > n || row < 0 || col < 0) {
            throw Out_Of_Range();
        }

        // Get colth columns
        PhysVector *col_ptr = cols.x(col);
        // We have our issue.....
        // Will require some farily major refactoring at this point.

    }

    // Makes the matrix into the identity of the correct dimension
    // Only for square matrix - will throw Dimension_Mismatch() otherwise
    void Matrix::identity() {
        if (m != n) {
            // bad
            throw Dimension_Mismatch();
        }

        // Use = operator
        *this = identity_matrix(n);
    }
}
