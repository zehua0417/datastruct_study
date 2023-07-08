#ifndef BST_H
#define BST_H

class BST {
public:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertUtil(Node* node, int key);
    Node* searchUtil(Node* node, int key);
    void inorderUtil(Node* node);

    BST();
    void insert(int key);
    bool search(int key);
    void inorder();

};

#endif
