// QDot1D.h
//
// Basic 1D quantum dot simulation solver
// Takes relevant parameters and computes the simulation
// Actual computations need to inherit this and ovveride the potential function U(x)
//
// Hugo Sebesta 2021

#ifndef QDOT1D_H
#define QDOT1D_H

#include "Scalar.h"
#include "PhysVector.h"
#include "Matrix.h"

class Quantum_Dot_1D {
    public:
        Quantum_Dot_1D();
        virtual ~Quantum_Dot_1D();

        virtual void potential(double);
        virtual void 
    protected:

    private:
        // Simul parameters
        double max_x;
        double min_x;
        double step;

        Matrix Hamiltonian;
};



#endif
