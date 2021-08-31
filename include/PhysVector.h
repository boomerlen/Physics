#ifndef PHYSVECTOR_H
#define PHYSVECTOR_H

#include <complex>
#include <array>

// TODO: Change the way the dimension is set to with a templated thing like std::array

namespace phys {

    class PhysVector
    {
        public:
            PhysVector(int n);
            PhysVector(int n, std::complex<double> scalars[]);
            PhysVector(int n, std::complex<double> scalar);
            virtual ~PhysVector();

            PhysVector operator+(const PhysVector&) const;
            PhysVector operator-(const PhysVector&) const;
            std::complex<double> operator*(const PhysVector&) const;
            PhysVector operator*(const std::complex<double>&) const;

            // Object access using [] operator]
            std::complex<double>& operator[](int) const; // Least sure about this one

            void operator=(const PhysVector&);
            void operator=(const std::complex<double>[]);
            void operator=(const std::complex<double>&);

            int dimension() const;
            bool check_init() const;

            void make_empty();

            void print() const;
        protected:

        private:
            int dim;
            bool initialised;

            std::array<std::complex<double>, dim> entries;
      };

} // namespace phys

#endif // PHYSVECTOR_H
