#ifndef ORDERED_SET_H
#define ORDERED_SET_H

// Used to store Scalars in a vector or columns (vectors) in a matrix
// Implemented as a linked list

// Note that element assignment must be done with x() not with operator[]
#include "Node_T.h"
#include <iostream>

template <class T>
class Ordered_Set
{
    public:
        // Initialisation
        Ordered_Set(int);
        Ordered_Set(int, T[]);

        virtual ~Ordered_Set();

        // Element access
        void x(int n, T);
        T x(int n) const;

        // For 1-3 dimensioned sets
        void y(T);
        T y() const;
        void z(T);
        T z() const;

        // Relevant operators
        void operator=(const Ordered_Set&);
        void operator=(const T);

        int dimension() const;

    protected:

    private:
        int dim;

        Node_T<T> *head;
};

#endif // ORDERED_SET_H

// Implementations

// Constructor
template <class T>
Ordered_Set<T>::Ordered_Set(int n)
{
    //ctor
    dim = n;

    // Create the list of this length
    Node_T<T> *list_head = new Node_T<T>;
    Node_T<T> *current_node = list_head;

    for (int i = 0; i < n; i++) {
        Node_T<T> *new_node = new Node_T<T>;
        current_node->next = new_node;

        current_node = new_node;
    }

    head = list_head;
}

// Constructor with values
template <class T>
Ordered_Set<T>::Ordered_Set(int n, T entries[]) {
    // Very similar but entries are filled not just created.
    dim = n;

    // Create the list of this length
    Node_T<T> *list_head = new Node_T<T>;
    Node_T<T> *current_node = head;

    for (int i = 0; i < n; i++) {
        // Create and fill
        Node_T<T> *new_node = new Node_T<T>;
        new_node->set_data(entries[i]);

        current_node->next = new_node;
        current_node = new_node;
    }

    head = list_head;
}

// Destructor (deletes the linked list)
template <class T>
Ordered_Set<T>::~Ordered_Set()
{
    // Delete the list
    // Iterate through
    Node_T<T> *current_node = head;
    for (int i = 0; i < dim; i++) {
        Node_T<T> *next_node = current_node->next;
        delete current_node; // This will throw an exception when configured properly

        current_node = next_node;
    }
}

// Element access methods

// Get the nth element (counting from 0)
template <class T>
T Ordered_Set<T>::x(int n) const {
    if (n >= dim) {
        // Should chuck an exception
    }

    // Iterate
    Node_T<T> *current_node = head;
    for (int i = 0; i <= n; i++) {
        current_node = current_node->next;
    }

    // At correct node
    return current_node->get_data();
}

// Edit the nth element
template <class T>
void Ordered_Set<T>::x(int n, T d) {
    // Get to desired element
    if (n >= dim) {
        // should chuck an exception
    }

    Node_T<T> *current_node = head;
    for (int i = 0; i <= n; i++) {
        current_node = current_node->next;
    }

    current_node->set_data(d);
}

// y = (n = 1)
template <class T>
void Ordered_Set<T>::y(T d) {
    x(1, d);
}

template <class T>
T Ordered_Set<T>::y() const {
    return x(1);
}

// z = (n = 2)
template <class T>
void Ordered_Set<T>::z(T d) {
    x(2, d);
}

template <class T>
T Ordered_Set<T>::z() const {
    return x(2);
}

// Operators
template <class T>
void Ordered_Set<T>::operator=(const Ordered_Set& s) {
    // Ensure dimensions match
    if (dim != s.dimension()) {
        // Should chuck some sort of exception
        std::cout << "error not same dimensions" << std::endl;
    }

    // Copy values
    Node_T<T> *current_node = head;

    for (int i = 0; i < dim; i++) {
        if (s.)
        std::cout << "about to set " << i << "th data to" << s.x(i) << std::endl;
        current_node->set_data(s.x(i));
        std::cout << "set the " << i << "th data" << std::endl;
        current_node = current_node->next;
    }
}

template <class T>
void Ordered_Set<T>::operator=(const T d) {
    // Iterate through
    Node_T<T> *current_node = head;

    while (current_node != nullptr) {
        current_node->set_data(d);
        current_node = current_node->next;
    }
}

template <class T>
int Ordered_Set<T>::dimension() const {
    return dim;
}



