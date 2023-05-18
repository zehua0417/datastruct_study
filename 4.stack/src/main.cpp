#include"../include/header.h"
#include"../include/stack.h"

int main(void){
    std::cout << "****************************" << std::endl;
    std::cout << "Welcome to the Stack program" << std::endl;
    std::cout << "****************************" << std::endl;
    std::cout << "Enter the size of the stack: ";
    int size;
    std::string cmd;
    std::cin >> size;
    Stack stack(size);
    while(true){
        std::cout << "****************************" << std::endl;
        std::cout << "***  please input your cmd" << std::endl;
        std::cout << "***  1. input" << std::endl;
        std::cout << "***  2. output" << std::endl;
        std::cout << "***  3. push" << std::endl;
        std::cout << "***  4. pop" << std::endl;
        std::cout << "***  5. empty?" << std::endl;
        std::cout << "***  6. exit" << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << ">_@ ~$ ";
        std::cin >> cmd;
        getchar();

        if(cmd=="input"){
            std::cout << "****************************" << std::endl;
            std::cin >> stack;
        }else if(cmd=="output"){
            std::cout << "****************************" << std::endl;
            std::cout << stack;
        }else if(cmd=="push"){
            std::cout << "****************************" << std::endl;
            std::cout << "Enter the data: ";
            std::string data;
            std::cin >> data;
            stack.push(data);
        }else if(cmd=="pop"){
            std::cout << "****************************" << std::endl;
            std::cout << "Enter the number of elements to pop: ";
            int n;
            std::cin >> n;
            stack.pop(n);
        }else if(cmd=="empty?"){
            std::cout << "****************************" << std::endl;
            if(stack.isEmpty()){
                std::cout << "Stack is empty" << std::endl;
            }else{
                std::cout << "Stack is not empty" << std::endl;
            }
        }else if(cmd=="exit"){
            std::cout << "****************************" << std::endl;
            std::cout << "Bye!" << std::endl;
            break;
        }else{
            std::cout << "****************************" << std::endl;
            std::cout << "Invalid command!" << std::endl;
        }

    }

    return 0;
}