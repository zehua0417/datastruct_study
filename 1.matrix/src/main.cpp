#include<iostream>
#include"../include/matrix.hpp"

int main(){
Matrix<int> matrix(3,3);
std::cin >> matrix;
std::cout << matrix << std::endl;

    return 0;
}