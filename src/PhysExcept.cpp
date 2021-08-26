// PhysExcept.cpp
//
// Implements exceptions declared in PhysExcept.h
//
// Hugo Sebesta 2021

#include "PhysExcept.h"

virtual const char* Not_Initialised::what() const throw() {
    return "Variable not initialised";
}

virtual const char* List_Memleak_Warning::what() const throw() {
    return "Node_T still points to non-heap memory";
}
