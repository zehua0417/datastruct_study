#ifndef STACK_H_
#define STACK_H_
#include"../include/header.h"

class Stack{
private:
    struct Node{
        std::string data;
        Node *next;
    };
    Node *head;
    int top;
    const int size;
public:
    Stack();
    Stack(int size);
    ~Stack();

    bool push(std::string data);
    bool pop();
    bool pop(int n);
    bool isEmpty();

    friend std::ostream& operator<<(std::ostream& out, const Stack& stack);
    friend std::istream& operator>>(std::istream& in, Stack& stack);

};

#endif
