#include <iostream>
#include "../include/bst.h"
#include "../include/avl.h"

void bstTest() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal of the BST: ";
    bst.inorder();
    std::cout << std::endl;

    int key = 40;
    if (bst.search(key))
        std::cout << "Key " << key << " found in the BST" << std::endl;
    else
        std::cout << "Key " << key << " not found in the BST" << std::endl;
}

void avlTest(){
    AVL avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(60);

    std::cout << "Inorder traversal of the AVL tree: ";
    avl.inorder();
    std::cout << std::endl;

    int key = 30;
    if (avl.search(key))
        std::cout << "Key " << key << " found in the AVL tree" << std::endl;
    else
        std::cout << "Key " << key << " not found in the AVL tree" << std::endl;

}

int main(void){
    bstTest();
    avlTest();

    return 0;
}
