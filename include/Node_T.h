#ifndef NODE_T_H
#define NODE_T_H

#include <iostream>

template <class T>
class Node_T
{
    public:
        Node_T();
        virtual ~Node_T();

        void set_data(T);
        T get_data();

        Node_T *next;

    private:
        bool initialised;
        T data;
};

#endif // NODE_T_H

// Implementations

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
T Node_T<T>::get_data() {
    return data;
}
