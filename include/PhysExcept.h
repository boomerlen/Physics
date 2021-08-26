// PhysExcept.h
//
// Inherits and overrides std::exception to implement relevant exceptions for operating on physics things
//
// Hugo Sebesta 2021

#ifndef PHYSEXCEPT_H
#define PHYSEXCEPT_H

#include <exception>

// General
class Not_Initialised : public exception {
    virtual const char *what() const throw();
};

// Node exceptions
 class List_Memleak_Warning : public exception {
        virtual const char *what() const throw();
 };


#endif // PHYSEXCEPT_H
