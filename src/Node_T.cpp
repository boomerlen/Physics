#include "Node_T.h"

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
        // problem
        // TODO finish this
        // This should throw an exception
    }
}

template <class T>
void Node_T<T>::set_data(T d) {
    data = d;
    initialised = true;
}

template <class T>
T Node_T<T>::get_data() {
    return data;
}
