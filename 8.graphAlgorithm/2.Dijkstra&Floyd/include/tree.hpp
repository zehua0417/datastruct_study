#ifndef TREE_HPP_
#define TREE_HPP_

#include "../include/header.h"

template<typename T>
class Tree; // 不完整声明

/**
 * @brief 树节点类
 * @tparam T
 */
template<typename T>
class Node {
private:
    int id; // 节点编号
    T data; // 节点数据
    std::vector<Node<T>*> children; // 子节点

public:
    Node() : id(0) {}
    explicit Node(T data) : id(0), data(data) {}
    explicit Node(int id, T data) : id(id), data(data) {}
    ~Node() = default;

    int getId() const {
        return id;
    }

    T getData() const {
        return data;
    }

    friend class Tree<T>;
};

/**
 * @brief 树类
 * @tparam T
 */
template<typename T>
class Tree {
private:
    Node<T>* root; // 根节点
    int num_nodes; // 节点数

public:
    // ===========================构造和析构函数=======================
    Tree() {
        root = nullptr;
        num_nodes = 0;
    }

    explicit Tree(T data) {
        root = new Node<T>(0, data);
        num_nodes = 1;
    }

    explicit Tree(std::vector<std::pair<int, T>> data) {
        root = new Node<T>(data[0].first, data[0].second);
        num_nodes = 1;

        for (int i = 1; i < data.size(); i++) {
            Node<T>* parent = findNode(root, data[i].first);
            if (parent == nullptr) {
                throw std::runtime_error("ERROR: parent node not found");
                return;
            }
            insertNode(parent, data[i].second);
        }
    }

    ~Tree() = default;

    // ===========================成员函数=======================
    // 获取根节点
    Node<T>* getRoot() const {
        return root;
    }

    // 设置根节点
    void setRoot(int data) {
        root = new Node<T>(0, data);
        num_nodes = 1;
    }

    // 获取节点数目
    int getNumNodes() const {
        return num_nodes;
    }

    //================================
    // 将子节点对象插入到父节点的子节点列表中
    void insertNode(Node<T>* parent, Node<T>* child) {
        parent->children.push_back(child);
        num_nodes++;
    }

    // 输入数据, 生成新节点对象, 搜索父节点, 并将其插入到父节点的子节点列表中
    void insertNode(int parentId, T data) {
        if(root == nullptr) {
            root = new Node<T>(0, data);
            num_nodes = 1;
        }
        Node<T>* parent = findNode(root, parentId);
        if (parent == nullptr) {
            throw std::runtime_error("ERROR: parent node not found");
            return;
        }
        insertNode(parent, data);
    }

    // 输入数据, 生成新节点对象, 并将其插入到父节点的子节点列表中
    void insertNode(Node<T>* parent, T data) {
        auto child = new Node<T>(num_nodes-1, data);
        insertNode(parent, child);
    }
    //
    void insertNode(std::vector<std::pair<int, T> > data) {
        for (int i = 0; i < data.size(); i++) {
            insertNode(data.first, data.second);
        }
    }

    Node<T>* findNode(Node<T>* node, int targetId) {
        if (node == nullptr) {
            std::cout << "ERROR: findNode, input node is nullptr!!!" << std::endl;
            return nullptr;
        }

        if (node->getId() == targetId)
            return node;

        for (Node<T>* child : node->children) {
            Node<T>* result = findNode(child, targetId);
            if (result != nullptr)
                return result;
        }

        std::cout << "ERROR: findNode, target node not found!!!" << std::endl;
        return nullptr;
    }

    void eraseNode(Node<T>* parent, Node<T>* child) {
        for (auto it = parent->children.begin(); it != parent->children.end(); it++) {
            if (*it == child) {
                parent->children.erase(it);
                num_nodes--;
                break;
            }
        }
    }

    void eraseNode(Node<T>* parent, T data) {
        for (auto it = parent->children.begin(); it != parent->children.end(); it++) {
            if ((*it)->getData() == data) {
                parent->children.erase(it);
                num_nodes--;
                break;
            }
        }
    }

    void outputAsMermaid() const {
        std::cout << "graph LR" << std::endl;
        generateMermaidSyntax(root, "");
    }

private:
    void generateMermaidSyntax(const Node<T>* node, const std::string& parentName) const {
        std::uintptr_t nodeId = reinterpret_cast<std::uintptr_t>(node);
        std::string nodeName = "N" + std::to_string(nodeId);
        std::cout << "  " << nodeName << "[" << node->getId() << ": " << node->getData() << "]" << std::endl;

        if (!parentName.empty()) {
            std::cout << "  " << parentName << " --> " << nodeName << std::endl;
        }

        for (const auto& child : node->children) {
            generateMermaidSyntax(child, nodeName);
        }
    }
};

#endif // TREE_HPP_
