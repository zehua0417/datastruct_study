#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "Node.h"

template<typename T>
class BinaryTree {
public:
    Node<T>* root;
    BinaryTree();
    ~BinaryTree();
    void insert(T data);
    void preOrderTraversal(Node<T>* node);
    void inOrderTraversal(Node<T>* node);
    void postOrderTraversal(Node<T>* node);
    void levelOrderTraversal(Node<T>* node);
};

template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    std::stack<Node<T>*> stack;
    Node<T>* node = root;
    while (node || !stack.empty()) {
        if (node) {
            stack.push(node);
            node = node->left;
        }
        else {
            node = stack.top();
            stack.pop();
            Node<T>* tmp = node->right;
            delete node;
            node = tmp;
        }
    }
}

template<typename T>
void BinaryTree<T>::insert(T data) {
    Node<T>* node = new Node<T>(data);
    if (!root) {
        root = node;
        return;
    }
    Node<T>* curr = root;
    while (true) {
        if (data < curr->data) {
            if (!curr->left) {
                curr->left = node;
                return;
            }
            curr = curr->left;
        }
        else {
            if (!curr->right) {
                curr->right = node;
                return;
            }
            curr = curr->right;
        }
    }
}

template<typename T>
void BinaryTree<T>::preOrderTraversal(Node<T>* node) {
    if (!node) {
        return;
    }
    std::cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template<typename T>
void BinaryTree<T>::inOrderTraversal(Node<T>* node) {
    if (!node) {
        return;
    }
    inOrderTraversal(node->left);
    std::cout << node->data << " ";
    inOrderTraversal(node->right);
}

template<typename T>
void BinaryTree<T>::postOrderTraversal(Node<T>* node) {
    if (!node) {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void BinaryTree<T>::levelOrderTraversal(Node<T>* node) {
    if (!node) {
        return;
    }
    std::queue<Node<T>*> queue;
    queue.push(node);
    while (!queue.empty()) {
        Node<T>* curr = queue.front();
        queue.pop();
        std::cout << curr->data << " ";
        if (curr->left) {
            queue.push(curr->left);
        }
        if (curr->right) {
            queue.push(curr->right);
        }
    }
}

#endif