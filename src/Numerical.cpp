// Numerical.cpp
//
// Implementation of some numerical computation functions
// Mostly for testing ideas about numerical computation
//
// Hugo Sebesta 2021

#include <cmath>

#include "Numerical.h"

double num_integral_sinx(double lower, double upper, double precision) {
    double integral = 0.0;

    for (double x = lower; x <= upper; x += precision) {
        integral = integral + (std::sin(x) * precision);
    }

    return integral;
}
