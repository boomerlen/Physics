// Node_T.cpp
//
// Linked list - underlying data structure for an Ordered_Set
// Contains basic node methods
//
// Hugo Sebesta 2021

#include "Node_T.h"
#include "PhysExcept.h"
#include "Scalar.h"

template <class T>
Node_T<T>::Node_T()
{
    next = nullptr;
    initialised = false;
}

// Should throw an exception if it still points to something
template <class T>
Node_T<T>::~Node_T()
{
    //dtor
    if (next != nullptr) {
        // Sadly cannot throw an exception here since we are in the destructor
        // Would like to though, this just needs more sanitisation externally
        // std::cout << "Next is not null!" << std::endl;
        // Just need to have faith I think, error messages clog up the cases where this isn't an issue
    }
}

template <class T>
void Node_T<T>::set_data(T d) {
    data = d;
    initialised = true;
}

template <class T>
T Node_T<T>::get_data() const {
    if (!initialised) {
        throw Not_Initialised();
    }
    return data;
}

template <class T>
bool Node_T<T>::check_init() const {
    return initialised;
}



// Instantisations
template class Node_T<int>;
template class Node_T<Scalar>;
