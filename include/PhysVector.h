#ifndef PHYSVECTOR_H
#define PHYSVECTOR_H

#include <vector>

#include "Scalar.h"

class PhysVector
{
    public:
        PhysVector(int n);
        PhysVector(int n, Scalar scalars[]);
        virtual ~PhysVector();

        PhysVector operator+(const PhysVector&) const;
        PhysVector operator-(const PhysVector&) const;
        Scalar operator*(const PhysVector&) const;
        PhysVector operator*(const Scalar&) const;

        // Array-like object access
        Scalar& operator[](int i);
        const Scalar& operator[](int i) const;

        void operator=(const PhysVector&);
        void operator=(const Scalar[]);
        void operator=(const Scalar&);

        int dimension() const;

        void make_empty();

        void print() const;
    protected:

    private:
        int dim;
        bool uninitialised;

        std::vector<Scalar> entries;
};

#endif // PHYSVECTOR_H
