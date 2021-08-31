#ifndef PHYSVECTOR_H
#define PHYSVECTOR_H

#include <complex>
#include <array>

// TODO: Change the way the dimension is set to with a templated thing like std::array

namespace phys {
    template <int dim>
    class PhysVector
    {
        public:
            PhysVector();
            PhysVector(std::complex<double> scalars[]);
            PhysVector(std::complex<double> scalar);
            virtual ~PhysVector();

            PhysVector operator+(const PhysVector&) const;
            PhysVector operator-(const PhysVector&) const;
            std::complex<double> operator*(const PhysVector&) const;
            PhysVector operator*(const std::complex<double>&) const;

            // Object access using [] operator]
            const std::complex<double>& operator[](int) const; // Least sure about this one
            std::complex<double>& operator[](int);

            void operator=(const PhysVector&);
            void operator=(const std::complex<double>[]);
            void operator=(const std::complex<double>&);

            int dimension() const;
            bool check_init() const;

            void make_empty();

            void print() const;
        protected:

        private:
            bool initialised;

            std::array<std::complex<double>, dim> entries;
      };

} // namespace phys

#endif // PHYSVECTOR_H
