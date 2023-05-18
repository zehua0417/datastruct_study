#include "../include/LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::insert(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::insert_index(int value, int index) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        Node* current = head;
        Node* previous = nullptr;
        int count = 0;

        while (current != nullptr) {
            if (count == index) {
                if (current == head) {
                    head = newNode;
                }
                else {
                    previous->next = newNode;
                }

                newNode->next = current;
                return;
            }

            previous = current;
            current = current->next;
            count++;
        }

        tail->next = newNode;
        tail = newNode;
    }
}

bool LinkedList::remove_number(int value) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->value == value) {
            if (current == head) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

bool LinkedList::remove_index(int index) {
    Node* current = head;
    Node* previous = nullptr;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            if (current == head) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            return true;
        }

        previous = current;
        current = current->next;
        count++;
    }

    return false;
}

bool LinkedList::search(int value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}

int LinkedList::get(int index) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return current->value;
        }

        count++;
        current = current->next;
    }

    return -1;
}

void LinkedList::modify(int oldValue, int newValue) {
    Node* current = head;

    while (current != nullptr) {
        if (current->value == oldValue) {
            current->value = newValue;
            return;
        }

        current = current->next;
    }
}

void LinkedList::display() {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

void LinkedList::clear() {
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
}

int LinkedList::size() {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

std::ostream &operator<<(std::ostream &out, const LinkedList &list){
    LinkedList::Node* current = list.head;

    while (current != nullptr) {
        out << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
    return out;
}
// 循环插入多个节点
std::istream &operator>>(std::istream &in, LinkedList &list){
    std::cout << "Please input the value of the node, end with -1" << std::endl;
    int value;
    while (std::cin >> value && value != -1) {
        list.insert(value);
    }
    return in;
    //int value;
    //while (in != -1) {
    //    in >> value;
    //    list.insert(value);
    //}
    //return in;
}
