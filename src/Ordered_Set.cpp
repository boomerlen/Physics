// Ordered_Set.cpp
//
// This is being replaced by std::array and std::vector ;(
// Now unused
// Implements the ordered_set class
// Used as an underlying container for vectors
//
// Hugo Sebesta 2021

#include "Ordered_Set.h"
#include "Scalar.h"
#include "PhysExcept.h"

#include <iostream>

// Constructor
template <class T>
Ordered_Set<T>::Ordered_Set(int n)
{
    //ctor
    dim = n;

    // Create the list of this length
    Node_T<T> *list_head = new Node_T<T>;
    Node_T<T> *current_node = list_head;

    for (int i = 0; i < (n - 1); i++) {
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
    Node_T<T> *current_node = list_head;
    Node_T<T> *prev_node = current_node;

    for (int i = 0; i < n; i++) {
        current_node->set_data(entries[i]);
        Node_T<T> *new_node = new Node_T<T>;

        current_node->next = new_node;
        prev_node = current_node;
        current_node = new_node;
    }

    delete current_node;
    prev_node->next = nullptr;

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

        delete current_node;

        current_node = next_node;
    }
}

// Element access methods
// Could throw: Dimension_Mismatch(), Not_Initialised() (from Node_T.h)

// Get the nth element (counting from 0)
template <class T>
T Ordered_Set<T>::x(int n) const {
    if (n >= dim) {
        // Should chuck an exception
        throw Dimension_Mismatch();
    }

    // Iterate
    Node_T<T> *current_node = head;
    for (int i = 0; i < n; i++) {
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
        throw Dimension_Mismatch();
    }

    Node_T<T> *current_node = head;
    for (int i = 0; i < n; i++) {
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
        throw Dimension_Mismatch();
    }

    // Check that s is initialised
    if (!s.initialised()) {
        throw Not_Initialised();
    }

    // Copy values
    Node_T<T> *current_node = head;

    for (int i = 0; i < dim; i++) {
        current_node->set_data(s.x(i));
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

template <class T>
bool Ordered_Set<T>::initialised() const {
    // Check each node element is initialised
    Node_T<T> *current_node = head;

    while (current_node != nullptr) {
        if (current_node->check_init() == false) {
            return false;
        }

        current_node = current_node->next;
    }

    return true;
}


// Instantisations
template class Ordered_Set<int>;
template class Ordered_Set<Scalar>;
