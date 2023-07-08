#include<iostream>
#include "../include/bst.h"

BST::BST() : root(nullptr) {}

BST::Node* BST::insertUtil(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insertUtil(node->left, key);
    else if (key > node->key)
        node->right = insertUtil(node->right, key);

    return node;
}

void BST::insert(int key) {
    root = insertUtil(root, key);
}

BST::Node* BST::searchUtil(Node* node, int key) {
    if (node == nullptr || node->key == key)
        return node;

    if (key < node->key)
        return searchUtil(node->left, key);
    else
        return searchUtil(node->right, key);
}

bool BST::search(int key) {
    Node* result = searchUtil(root, key);
    return result != nullptr;
}

void BST::inorderUtil(Node* node) {
    if (node == nullptr)
        return;

    inorderUtil(node->left);
    std::cout << node->key << " ";
    inorderUtil(node->right);
}

void BST::inorder() {
    inorderUtil(root);
}
