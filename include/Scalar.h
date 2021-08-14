// A could-be complex scalar

#ifndef SCALAR_H
#define SCALAR_H


class Scalar
{
    public:
        Scalar(double a, double b = 0.0);
        Scalar(int a, int b = 0);
        // Less preferred but possible initialiser
        Scalar(int a[2]);
        Scalar(double a[2]);

        virtual ~Scalar();

        // Operators
        Scalar operator+(const Scalar&) const;
        Scalar operator+(int);
        Scalar operator+(double);

        Scalar operator-(const Scalar&) const;
        Scalar operator-(int);
        Scalar operator-(double);

        Scalar operator*(const Scalar&) const;
        Scalar operator*(int);
        Scalar operator*(double);

        void operator=(const Scalar&);
        void operator=(int[2]);
        void operator=(double[2]);
        void operator=(int);
        void operator=(double);


        // Complex
        double real() const;
        double imag() const;
        double abs() const;
        double argument() const;
        Scalar conj() const;
        bool purely_imaginary(double error = 0.0) const;

        // Debug
        void print() const;
    protected:

    private:
        double real_part;
        double imaginary_part;
};

#endif // SCALAR_H
