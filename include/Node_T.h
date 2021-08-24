#ifndef NODE_T_H
#define NODE_T_H

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
