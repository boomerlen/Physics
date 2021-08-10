// A could-be complex scalar

#ifndef SCALAR_H
#define SCALAR_H


class Scalar
{
    public:
        Scalar(double a, double b = 0.0);
        Scalar(int a, int b = 0);
        virtual ~Scalar();

        // Operators
        Scalar operator+(const Scalar&);
        Scalar operator+(int);
        Scalar operator+(double);

        Scalar operator-(const Scalar&);
        Scalar operator-(int);
        Scalar operator-(double);

        Scalar operator*(const Scalar&);
        Scalar operator*(int);
        Scalar operator*(double);

        void operator=(const Scalar&);
        void operator=(int);
        void operator=(double);


        // Complex
        double real();
        double imag();
        double abs();
        double argument();
        Scalar conj();
        bool purely_imaginary(double error = 0.0);

        // Debug
        void print();
    protected:

    private:
        double real_part;
        double imaginary_part;
};

#endif // SCALAR_H
