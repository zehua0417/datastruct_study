#include"../include/header.h"
#include"../include/list.h"


int main(void){
    std::cout << "*********init & input*********" <<std::endl;
    List demo(15);
    std::cin >> demo;
    std::cin >> demo;
    std::cout << demo << std::endl;

    std::cout << "*********change & exchange**********" << std::endl;
    demo.Exchange(3,6);
    demo.Change(0,666);
    std::cout << demo << std::endl;

    std::cout << "**********shearch**********" << std::endl;
    std::cout << "number[0]: " << demo.SearchById(0) << std::endl;
    std::cout << "number[13]: " << demo.SearchById(13) << std::endl << std::endl;

    std::cout << "**********delete***********" << std::endl;
    demo.Delete(13);
    std::cout << "Length: " << demo.length() << std::endl;
    std::cout << demo << std::endl;

    std::cout << "**********insert**********" << std::endl;
    if(demo.Insert(5,985))
        std::cout << demo << std::endl;

    std::cin.get();
    return 0;
}