#ifndef AVL_H
#define AVL_H

#include "../include/bst.h"

class AVL : public BST {
private:
    int height(Node* node);
    int getBalance(Node* node);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    Node* insertUtil(Node* node, int key);

public:
    void insert(int key);
};

#endif
