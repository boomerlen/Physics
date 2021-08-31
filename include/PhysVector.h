#ifndef PHYSVECTOR_H
#define PHYSVECTOR_H

#include "Scalar.h"
#include "Ordered_Set.h"

#include <complex>
#include <array>

namespace phys {

    class PhysVector
    {
        public:
            PhysVector(int n);
            PhysVector(int n, Scalar scalars[]);
            virtual ~PhysVector();

            PhysVector operator+(const PhysVector&) const;
            PhysVector operator-(const PhysVector&) const;
            std::complex operator*(const PhysVector&) const;
            PhysVector operator*(const Scalar&) const;

            // Object access using x(index, [val])
            &std::complex operator[](int);
            void 
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

            std::array<std::complex<double>> entries;
      };

} // namespace phys

#endif // PHYSVECTOR_H
