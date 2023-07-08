#include<iostream>
#include"../include/avl.h"

int AVL::height(Node* node) {
    if (node == nullptr)
        return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

int AVL::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

BST::Node* AVL::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    Node* temp = newRoot->left;

    newRoot->left = node;
    node->right = temp;

    return newRoot;
}

BST::Node* AVL::rotateRight(Node* node) {
    Node* newRoot = node->left;
    Node* temp = newRoot->right;

    newRoot->right = node;
    node->left = temp;

    return newRoot;
}

BST::Node* AVL::insertUtil(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insertUtil(node->left, key);
    else if (key > node->key)
        node->right = insertUtil(node->right, key);
    else
        return node; // Duplicate keys not allowed in AVL tree

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVL::insert(int key) {
    root = insertUtil(root, key);
}
