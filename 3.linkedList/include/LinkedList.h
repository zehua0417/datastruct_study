#include<iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insert(int value);
    void insert_index(int value, int index);
    bool remove_number(int value);
    bool remove_index(int index);
    bool search(int value);
    int get(int index);
    void modify(int oldValue, int newValue);
    friend std::istream &operator>>(std::istream &in, LinkedList &list);
    friend std::ostream &operator<<(std::ostream &out, const LinkedList &list);
    void display();
    int size();

private:
    struct Node {
        int value;
        Node* next;
    };
    Node* head;
    Node* tail;

    void clear();
};

#endif
