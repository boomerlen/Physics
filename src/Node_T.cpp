// Important bit is that this contains not just implementations but also the instantisations of the template type


#include "Node_T.h"
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
        // problem
        // TODO finish this
        // This should throw an exception
    }
}

template <class T>
void Node_T<T>::set_data(T d) {
    std::cout << "setting data in NOde_T.h" << std::endl;
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
