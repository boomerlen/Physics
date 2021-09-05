// PhysExcept.cpp
//
// Implements exceptions declared in PhysExcept.h
//
// Hugo Sebesta 2021

#include "PhysExcept.h"

namespace phys {

    const char* Not_Initialised::what() const throw() {
        return "Variable not initialised";
    }

    const char* List_Memleak_Warning::what() const throw() {
        return "Node_T still points to non-heap memory";
    }

    const char *Dimension_Mismatch::what() const throw() {
        return "Dimension mismatch";
    }

    const char *Out_Of_Range::what() const throw() {
        return "Out of range";
    }

    const char *Matrix_Glue_Failure::what() const throw() {
        return "Warning: operating must use originally sized matrix. Behaviour for matrices with added columns is undefined.";
    }
} // namespace phys
