#include <iostream>
#include "../include/sequential_search.h"
#include "../include/binary_search.h"

void seqTest(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int index = sequentialSearch(arr, n, target);

    if (index != -1)
        std::cout << "Element found at index " << index << std::endl;
    else
        std::cout << "Element not found" << std::endl;

}

void binTest(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int index = binarySearch(arr, 0, n - 1, target);

    if (index != -1)
        std::cout << "Element found at index " << index << std::endl;
    else
        std::cout << "Element not found" << std::endl;
}

int main(void){
    seqTest();
    binTest();

    return 0;
}