// Node_T.cpp
//
// Linked list - underlying data structure for an Ordered_Set
// Contains basic node methods
//
// Hugo Sebesta 2021

#include "Node_T.h"
#include "PhysExcept.h"
//#include "Scalar.h"

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
        List_Memleak_Warning ex;
        throw ex;
    }
}

template <class T>
void Node_T<T>::set_data(T d) {
    data = d;
    initialised = true;
}

template <class T>
T Node_T<T>::get_data() const {
    return data;
}

template <class T>
bool Node_T<T>::check_init() const {
    return initialised;
}



// Instantisations
template class Node_T<int>;
//template class Node_T<Scalar>;
