#include "../include/LinkedList.h"
#include <iostream>

int main()
{
    LinkedList list;
    std::cout << "List has initialized successfully!!!\nEnter your cmd to continue" << std::endl;
    std::string cmd;
    while (1)
    {
        cmd = "";
        std::cout << "***********************************" << std::endl;
        std::cout << "*** insert                        *" << std::endl;
        std::cout << "*** get                           *" << std::endl;
        std::cout << "*** size                          *" << std::endl;
        std::cout << "*** search                        *" << std::endl;
        std::cout << "*** echo                          *" << std::endl;
        std::cout << "*** rm_num                        *" << std::endl;
        std::cout << "*** rm_index                      *" << std::endl;
        std::cout << "*** motify                        *" << std::endl;
        std::cout << "*** exit                          *" << std::endl;
        std::cout << "***********************************" << std::endl;
        std::cout << "Please enter your cmd: " << std::endl;
        std::cin >> cmd;
        getchar();

        std::cout << "your cmd is: \"" << cmd << "\"" << std::endl;
        if (cmd == "insert"){
            std::cin >> list;
            std::cout << "insert successfully" << std::endl;
        }else if (cmd == "get"){
            int index;
            std::cin >> index;
            std::cout << list.get(index) << std::endl;
        }else if(cmd == "size"){
            std::cout << "size: " << list.size() << std::endl;
        }else if(cmd == "search"){
            int value;
            std::cin >> value;
            std::cout << (list.search(value) ? "Yes" : "No") << std::endl;
        }else if (cmd == "echo"){
            std::cout << list;
        }else if (cmd == "rm_num"){
            int value;
            std::cin >> value;
            std::cout << (list.remove_number(value) ? "success" : "fail") << std::endl;
        }else if (cmd == "rm_index"){
            int index;
            std::cin >> index;
            std::cout << (list.remove_index(index) ? "success" : "fail") << std::endl;
        }else if (cmd == "motify"){
            int oldValue, newValue;
            std::cin >> oldValue >> newValue;
            list.modify(oldValue, newValue);
        }else if(cmd == "exit"){
            break;
        }else{
            std::cout << "Invalid cmd" << std::endl;
        }
    }

    return 0;
}
