#ifndef PHYSVECTOR_H
#define PHYSVECTOR_H

#include "Scalar.h"

class PhysVector
{
    public:
        PhysVector(int n);
        PhysVector(int n, Scalar scalars[]);
        virtual ~PhysVector();

        PhysVector operator+(const &PhysVector);
        PhysVector operator-(const &PhysVector);
        Scalar operator*(const &PhysVector);
        PhysVector operator*(const &Scalar);

        &Scalar operator[](int i);
        const &Scalar operator[](int i) const;

        void operator=(const &PhysVector);
        void operator=(const &Scalar[]);
        void operator=(const &Scalar);

        int dimension() const;

        void make_empty();
    protected:

    private:
        int dim;

        Scalar entries[];
};

#endif // PHYSVECTOR_H
