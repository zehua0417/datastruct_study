#ifndef TREE_HPP_
#define TREE_HPP_
#include"../include/header.h"

template<typename T>
class Tree; // 不完整声明

template<typename T>
class Node{
private:
    T data;
    std::vector<Node<T>*> children;
public:
    Node() = default;
    explicit Node(T data) : data(data) {}
    ~Node() = default;

    T getData() const {
        return data;
    }

    friend class Tree<T>;
};

template<typename T>
class Tree{
private:
    Node<T>* root;
    int num_nodes;
public:
    Tree(){
        root = nullptr;
        num_nodes = 0;
    }
    explicit Tree(T data){
        root = new Node<T>(data);
        num_nodes = 1;
    }
    explicit Tree(std::vector<std::pair<int, T>> data) {
        root = new Node<T>(data[0].second);
        num_nodes = 1;

        for (int i = 1; i < data.size(); i++) {
            Node<T>* parent = findNode(root, data[i].first);
            if(parent == nullptr){
                throw std::runtime_error("ERROR: parent node not found");
                return;
            }
            insertNode(parent, data[i].second);
        }
    }

    ~Tree() = default;

    Node<T>* getRoot() const {
        return root;
    }

    void setRoot(int data){
        root = new Node<T>(data);
        num_nodes = 1;
    }

    int getNumNodes() const {
        return num_nodes;
    }

    void insertNode(Node<T>* parent, Node<T>* child){
        parent->children.push_back(child);
        num_nodes++;
    }

    void insertNode(Node<T>* parent, T data){
        Node<T>* child = new Node<T>(data);
        parent->children.push_back(child);
        num_nodes++;
    }

    Node<T>* findNode(Node<T>* node, int targetData) {
        if (node == nullptr)
            return nullptr;

        if (node->getData() == targetData)
            return node;

        for (Node<T>* child : node->children) {
            Node<T>* foundNode = findNode(child, targetData);
            if (foundNode != nullptr)
                return foundNode;
        }

        return nullptr;
    }


    void eraseNode(Node<T>* parent, Node<T>* child){
        for(auto it = parent->children.begin(); it != parent->children.end(); it++){
            if(*it == child){
                parent->children.erase(it);
                num_nodes--;
                break;
            }
        }
    }

    void eraseNode(Node<T>* parent, T data){
        for(auto it = parent->children.begin(); it != parent->children.end(); it++){
            if((*it)->data == data){
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
        std::cout << "  " << nodeName << "[" << node->getData() << "]" << std::endl;

        if (!parentName.empty()) {
            std::cout << "  " << parentName << " --> " << nodeName << std::endl;
        }

        for (const auto& child : node->children) {
            generateMermaidSyntax(child, nodeName);
        }
    }


};


#endif // TREE_HPP_