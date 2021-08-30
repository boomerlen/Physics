# Physics
I am considering reimplementing the vector and the matrix to be based on the standard library
I.e. using std::complex instead of my scalars (taking advantage of well written and probably computationally prefered complex number wrappers)
* std::array as the underlying data type for physvectors
* std::vector as the underlying data type for the matrices
And then continuing to implement all of the functionality myself.
I don't know if this would improve performance or make much of a meaningful difference to the complexity of the code, but I think that perhaps forcing myself to become more familiar with the STL is a good idea. 
So I think I might do that
I will keep the code for Ordered_Set just to show off that I can write a templated linked list. Even though who can't?
