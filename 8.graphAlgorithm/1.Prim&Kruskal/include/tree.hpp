//
// Created by Lihuax on 2023/5/31.
//
#include"../include/header.h"
#ifndef TREE_HPP
#define TREE_HPP

template<typename T>
class Tree {
private:
    class TreeNode{
    public:
        T data;
        std::vector<TreeNode*> children;

        explicit TreeNode(const T& value) : data(value) {}

        void addChild(TreeNode* child);
    };
    TreeNode* root;
    template<typename Func>
    void _depthFirstForeach(TreeNode* node, Func func) const; //深度优先遍历
    template<typename Func>
    void _breadthFirstForeach(TreeNode* node, Func func) const; //广度优先遍历

public:
    explicit Tree(const T& value) {
        root = new TreeNode(value);
    }
    Tree(){
        root = new TreeNode(T());
    }
    ~Tree() {
        deleteTree(root);
    }

    void deleteTree(TreeNode* node);
    void insert(const T& value); //插入节点
    bool insert(const T& value, const T& parent); //插入节点
    bool remove(const T& value); //删除节点
    void printTree() const; //打印树
    void depthFirstPrint() const; //深度优先遍历
    void breadthFirstPrint() const; //广度优先遍历
    bool ifExist(const T& value) const; //判断节点是否存在
    bool ifExist(const T& value, TreeNode* node) const; //判断节点是否存在
    TreeNode* find(const T& value) const; //查找节点
    TreeNode* find(const T& value, TreeNode* node) const; //查找节点
    TreeNode* findParent(const T& value) const; //查找父节点
    TreeNode* findParent(const T& value, TreeNode* node) const; //查找父节点
};

#include"../include/header.h"
#include"../include/tree.hpp"

template<typename T>
void Tree<T>::TreeNode::addChild(TreeNode* child) {
    children.push_back(child);
}

template<typename T>
template<typename Func>
void Tree<T>::_depthFirstForeach(TreeNode* node, Func func) const {
    func(node->data);
    for (auto child : node->children) {
        _depthFirstForeach(child, func);
    }
}

template<typename T>
template<typename Func>
void Tree<T>::_breadthFirstForeach(TreeNode* node, Func func) const {
    std::queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        func(cur->data);
        for (auto child : cur->children) {
            q.push(child);
        }
    }
}

template<typename T>
void Tree<T>::deleteTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    for (auto child : node->children) {
        deleteTree(child);
    }
    delete node;
}

template<typename T>
void Tree<T>::insert(const T& value) {
    root->addChild(new TreeNode(value));
}

template<typename T>
bool Tree<T>::insert(const T& value, const T& parent) {
    TreeNode* node = find(parent);
    if (node == nullptr) {
        return false;
    }
    node->addChild(new TreeNode(value));
    return true;
}

template<typename T>
bool Tree<T>::remove(const T& value) {
    TreeNode* node = find(value);
    if (node == nullptr) {
        return false;
    }
    TreeNode* parent = findParent(value);
    for (auto child : node->children) {
        parent->addChild(child);
    }
    parent->children.erase(std::remove(parent->children.begin(), parent->children.end(), node), parent->children.end());
    delete node;
    return true;
}

template<typename T>
void Tree<T>::printTree() const {
    std::cout << "Tree: " << std::endl;
    depthFirstPrint();
}

template<typename T>
void Tree<T>::depthFirstPrint() const {
    _depthFirstForeach(root, [](const T& value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;
}

template<typename T>
void Tree<T>::breadthFirstPrint() const {
    _breadthFirstForeach(root, [](const T& value) {
        std::cout << value << " ";
    });
    std::cout << std::endl;
}

template<typename T>
bool Tree<T>::ifExist(const T& value) const {
    return find(value) != nullptr;
}

template<typename T>
bool Tree<T>::ifExist(const T& value, TreeNode* node) const {
    if (node == nullptr) {
        return false;
    }
    if (node->data == value) {
        return true;
    }
    for (auto child : node->children) {
        if (ifExist(value, child)) {
            return true;
        }
    }
    return false;
}

template<typename T>
typename Tree<T>::TreeNode* Tree<T>::find(const T& value) const {
    return find(value, root);
}

template<typename T>
typename Tree<T>::TreeNode* Tree<T>::find(const T& value, TreeNode* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data == value) {
        return node;
    }
    for (auto child : node->children) {
        TreeNode* res = find(value, child);
        if (res != nullptr) {
            return res;
        }
    }
    return nullptr;
}

template<typename T>
typename Tree<T>::TreeNode* Tree<T>::findParent(const T& value) const {
    return findParent(value, root);
}

template<typename T>
typename Tree<T>::TreeNode* Tree<T>::findParent(const T& value, TreeNode* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    for (auto child : node->children) {
        if (child->data == value) {
            return node;
        }
        TreeNode* res = findParent(value, child);
        if (res != nullptr) {
            return res;
        }
    }
    return nullptr;
}

#endif //TREE_HPP