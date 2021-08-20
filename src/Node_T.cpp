#include "Node_T.h"

template <typename T>
Node_T<T>::Node_T()
{
    next = nullptr;
    initialised = false;
}

// Should throw an exception if it still points to something
template <typename T>
Node_T<T>::~Node_T()
{
    //dtor
    if (next != nullptr) {
        // problem
        // TODO finish this
        // This should throw an exception
    }
}

template <typename T>
void Node_T<T>::set_data(T d) {
    data = d;
    initialised = true;
}

template <typename T>
T Node_T<T>::get_data() {
    return data;
}
