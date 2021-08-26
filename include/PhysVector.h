#ifndef PHYSVECTOR_H
#define PHYSVECTOR_H

#include "Scalar.h"
#include "Ordered_Set.h"

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

        // Object access using x(index, [val])
        Scalar x(int i) const;
        void x(int i, Scalar s);

        void operator=(const PhysVector&);
        void operator=(const Scalar[]);
        void operator=(const Scalar&);

        int dimension() const;
        bool check_init() const;

        void make_empty();

        void print() const;
    protected:

    private:
        int dim;
        bool initialised;

        Ordered_Set<Scalar> *entries;
};

#endif // PHYSVECTOR_H
