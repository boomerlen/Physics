// A could-be complex scalar

#include <cmath>
#include <iostream>

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

Scalar::Scalar(int a[2]) {
    real_part = double(a[0]);
    imaginary_part = double(a[1]);
}

Scalar::Scalar(double a[2]) {
    real_part = a[0];
    imaginary_part = a[1];
}

Scalar::~Scalar()
{
    //dtor
}

// Operators
Scalar Scalar::operator+(const Scalar& s) {
    double new_r = real_part + s.real();
    double new_i = imaginary_part + s.imag();

    Scalar sum = Scalar(new_r, new_i);

    return sum;
}

Scalar Scalar::operator+(int a) {
    double new_r = real_part + double(a);

    Scalar sum = Scalar(new_r, imaginary_part);

    return sum;
}
Scalar Scalar::operator+(double a) {
    double new_r = real_part + a;

    Scalar sum = Scalar(new_r, imaginary_part);

    return sum;
}

Scalar Scalar::operator-(const Scalar& s) {
    double new_r = real_part - s.real();
    double new_i = imaginary_part - s.imag();

    Scalar result = Scalar(new_r, new_i);

    return result;
}

Scalar Scalar::operator-(int a) {
    double new_r = real_part - double(a);

    Scalar result = Scalar(new_r, imaginary_part);

    return result;
}

Scalar Scalar::operator-(double a) {
    double new_r = real_part - a;

    Scalar result = Scalar(new_r, imaginary_part);

    return result;
}

Scalar Scalar::operator*(const Scalar& s) {
    double new_r = (s.real() * real_part) - (s.imag() * imaginary_part);
    double new_i = (s.imag() * real_part) + (s.real() * imaginary_part);

    Scalar result = Scalar(new_r, new_i);

    return result;
}
Scalar Scalar::operator*(int a) {
    Scalar result = Scalar(real_part * a, imaginary_part * a);

    return result;
}
Scalar Scalar::operator*(double a) {
    Scalar result = Scalar(real_part * a, imaginary_part * a);

    return result;
}

void Scalar::operator=(const Scalar& s) {
    real_part = s.real();
    imaginary_part = s.imag();

    return;
}

void Scalar::operator=(int a) {
    real_part = double(a);
    imaginary_part = 0.0;

    return;
}
void Scalar::operator=(double a) {
    real_part = a;
    imaginary_part = 0.0;

    return;
}

void Scalar::operator=(int a[2]) {
    real_part = double(a[0]);
    imaginary_part = double(a[1]);
}

void Scalar::operator=(double a[2]) {
    real_part = a[0];
    imaginary_part = a[1];
}

// Complex
double Scalar::real() const {
    return real_part;
}

double Scalar::imag() const {
    return imaginary_part;
}

double Scalar::abs() const {
    double result = sqrt(real_part * real_part + imaginary_part * imaginary_part);

    return result;
}

double Scalar::argument() const {
    return atan(imaginary_part / real_part);
}

Scalar Scalar::conj() const {
    return Scalar(real_part, -1 * imaginary_part);
}

bool Scalar::purely_imaginary(double error) const {
    if ((imaginary_part <= error) && (imaginary_part >= (-1 * error))) {
        return true;
    }
    return false;
}

void Scalar::print() const {
    std::cout << real_part << " + " << imaginary_part << "i\n";
    return;
}
