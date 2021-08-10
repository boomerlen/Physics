// Generic matrix with generic operations

#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
    public:
        Matrix(int m, int n);
        virtual ~Matrix();

        Matrix operator+(const &Matrix);
        Matrix operator-(const &Matrix);
        Matrix operator*(const &Scalar);



    protected:

    private:
};

#endif // MATRIX_H
