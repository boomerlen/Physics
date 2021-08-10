// A could-be complex scalar

#include <cmath>

#include "Scalar.h"

Scalar::Scalar(double a, double b)
{
    //ctor
    real_part = a;
    imaginary_part = b;
}

Scalar::Scalar(int a, int b)
{
    //ctor
    real_part = a;
    imaginary_part = b;
}

Scalar::~Scalar()
{
    //dtor
}

// Operators
Scalar Scalar::operator+(const Scalar& s) {
    double new_r = this->real_part + s.real();
    double new_i = imaginary_part + s.imag();

    Scalar sum = Scalar(new_r, new_i);

    return sum;
}

Scalar operator+(int a) {
    double new_r = real_part + double(a);

    Scalar sum = Scalar(new_r, imaginary_part);

    return sum;
}
Scalar operator+(double a) {
    double new_r = real_part + a;

    Scalar sum = Scalar(new_r, imaginary_part);

    return Sum;
}

Scalar operator-(const Scalar& s) {
    double new_r = real_part - s.real();
    double new_i = imaginary_part - s.imag();

    Scalar result = Scalar(new_r, new_i);

    return result;
}

Scalar operator-(int a) {
    double new_r = real_part - double(a);

    Scalar result = Scalar(new_r, imaginary_part);

    return result;
}

Scalar operator-(double a) {
    double new_r = real_part - a;

    Scalar result = Scalar(new_r, imaginary_part);

    return result;
}

Scalar operator*(const Scalar& s) {
    double new_r = (s.real() * real_part) - (s.imag() * imaginary_part);
    double new_i = (s.imag() * real_part) + (s.real() * imaginary_part);

    Scalar result = Scalar(new_r, new_i);

    return result;
}
Scalar operator*(int a) {
    Scalar result = Scalar(real_part * a, imaginary_part * a);

    return result;
}
Scalar operator*(double a) {
    Scalar result = Scalar(real_part * a, imaginary_part * a);

    return result;
}

void operator=(const Scalar& s) {
    real_part = s.real();
    imaginary_part = s.imag();

    return;
}

void operator=(int a) {
    real_part = double(a);
    imaginary_part = 0.0;

    return;
}
void operator=(double a) {
    real_part = a;
    imaginary_part = 0.0;

    return;
}


// Complex
double real() {
    return real_part;
}

double imag() {
    return imaginary_part;
}

double abs() {
    return (this * this.conj());
}

double argument() {
    return atan(imaginary_part / real_part);
}

Scalar conj() {
    return Scalar(real_part, -1 * imaginary_part);
}

bool purely_imaginary(double error = 0.0) {
    if ((imaginary_part <= error) && (imaginary_part >= (-1 * error))) {
        return true;
    }
    return false;
}

void print() {
    std::cout << real_part << " + " << imaginary_part << "i\n";
    return;
}
