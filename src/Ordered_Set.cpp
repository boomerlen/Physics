#include "Ordered_Set.h"

// Constructor
template <typename T>
Ordered_Set<T>::Ordered_Set(int n)
{
    //ctor
    dim = n;

    // Create the list of this length
    Node_T<T> *list_head = new Node_T<T>;
    Node_T<T> *current_node = head;

    for (int i = 0; i < n; i++) {
        Node_T<T> *new_node = new Node_T<T>;
        current_node->next = new_node;

        current_node = new_node;
    }

    head = list_head;
}

// Constructor with values
template <typename T>
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
template <typename T>
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
template <typename T>
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
template <typename T>
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
template <typename T>
void Ordered_Set<T>::y(T d) {
    x(1, d);
}

template <typename T>
T Ordered_Set<T>::y() const {
    return x(1);
}

// z = (n = 2)
template <typename T>
void Ordered_Set<T>::z(T d) {
    x(2, d);
}

template <typename T>
T Ordered_Set<T>::z() const {
    return x(2);
}

// Operators
template <typename T>
void Ordered_Set<T>::operator=(const Ordered_Set& s) {
    // Ensure dimensions match
    if (dim != s.dimension()) {
        // Should chuck some sort of exception
    }

    // Copy values
    Node_T<T> *current_node = head;

    for (int i = 0; i < dim; i++) {
        current_node->set_data(s.x(i));

        current_node = current_node->next;
    }
}

template <typename T>
void Ordered_Set<T>::operator=(const T d) {
    // Iterate through
    Node_T<T> *current_node = head;

    while (current_node != nullptr) {
        current_node->set_data(d);
        current_node = current_node->next;
    }
}

template <typename T>
int Ordered_Set<T>::dimension() const {
    return dim;
}


