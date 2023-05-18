#include"../include/header.h"
#include"../include/stack.h"


Stack::Stack(int size):size(size),top(0), head(NULL){
    std::cout<<"Stack created with size: "<<size<<std::endl;
}

Stack::Stack():size(10),top(0), head(NULL){
    std::cout<<"Stack created with size: "<<size<<std::endl;
}

Stack::~Stack(){
    std::cout<<"Stack destroyed"<<std::endl;
}

bool Stack::push(std::string data){
    if(top == size){
        std::cout<<"Stack is full"<<std::endl;
        return false;
    }
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    top++;
    return true;
}

bool Stack::pop(){
    if(top == 0){
        std::cout<<"Stack is empty"<<std::endl;
        return false;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    top--;
    return true;
}

bool Stack::pop(int n){
    if(top == 0){
        std::cout<<"Stack is empty"<<std::endl;
        return false;
    }
    if(n > top){
        std::cout<<"Stack doesn't have that many elements"<<std::endl;
        return false;
    }
    for(int i = 0; i < n; i++){
        Node *temp = head;
        head = head->next;
        delete temp;
        top--;
    }
    return true;
}

bool Stack::isEmpty(){
    if(top == 0){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Stack& stack){
    std::cout << "**********all data:**********" << std::endl;
    Stack::Node *temp = stack.head;
    while(temp != NULL){
        std::cout <<  "*** ";
        out<<temp->data<<std::endl;
        temp = temp->next;
    }
    std::cout << "*****************************" << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Stack& stack){
    std::cout << "*** remaining positions: " << (stack.size - stack.top) << std::endl;
    std::cout << "*** Enter data: ";
    std::string data;
    do{
        std::cin.putback('\n');
        std::cin >> data;
        stack.push(data);
    }while(std::cin.get()!='\n');
    //q:std::cin.putback('\n');是干嘛的？
    //a:因为在main.cpp中，输入完一个命令后，会有一个getchar()，这个getchar()会把回车符吃掉，所以这里要把回车符放回去


    return in;
}