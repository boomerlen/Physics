// Node_T.h
//
// Header file for Node_T datatype
// Nodes for use in a linked list
// Templated type, implementation file contains the instantisations
//
// Hugo Sebesta 2021

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
        T get_data() const;

        Node_T *next;

        // safety
        bool check_init() const;

    private:
        bool initialised;
        T data;
};

#endif // NODE_T_H
