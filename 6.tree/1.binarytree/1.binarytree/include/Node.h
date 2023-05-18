#ifndef NODE_H
#define NODE_H

#include"../include/header.h"
template<typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data);
};

template<typename T>
Node<T>::Node(T data) : data(data), left(nullptr), right(nullptr) {}

#endif
