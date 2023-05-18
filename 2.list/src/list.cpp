/**
 * *file name: list.cpp
 * *author: lihuax
 * *version: 0.1
 * !description:
 */
#include"../include/header.h"
#include "../include/list.h"
#define INT_SIZE 4

List::List()
    :m_size(1),m_length(0){
        m_list = (int*)malloc(INT_SIZE*m_size);
}
List::List(int size)
    :m_size(size),m_length(0){
        m_list = (int*)malloc(INT_SIZE*m_size);
}
List::~List(){
    free(m_list);
}

void List::Exchange(int id_1, int id_2){
    *(this->m_list+id_1) = *(this->m_list+id_1) ^ *(this->m_list+id_2);
    *(this->m_list+id_2) = *(this->m_list+id_2) ^ *(this->m_list+id_1);
    *(this->m_list+id_1) = *(this->m_list+id_1) ^ *(this->m_list+id_2);
}
void List::Change(int id, int num){
    *(this->m_list+id) = num;
}
int List::SearchById(int id){
    return *(this->m_list+id);
}
bool List::is_full(){
    if(m_size <= m_length)
        return 1;
    else return 0;
}
bool List::is_empty(){
    if(m_length == 0)
        return 1;
    else return 0;
}
int List::size(){
    return m_size;
}
int List::length(){
    return m_length;
}
std::ostream& operator << (std::ostream& os, const List& list){
    std::cout << "*******list*******" << std::endl;
    for(int i = 0; i < list.m_length; ++i){
        std::cout << *(list.m_list+i) << " ,";
    }
    std::cout << std::endl;
    return os;
}

//==============================================
int* List::begin(){
    return m_list;
}
int* List::end(){
    return m_list+m_length;
}
// (backward) begin ------> end (forward)
void List::forwardMove(int id){
    for(int i = 0; i < m_length - id ; ++i){
        *(m_list + m_length - i + 1) = *(m_list + m_length - i); 
    }
}
void List::backwardMove(int id){
    for(int i = 0; i < m_length - id; ++i){
        *(m_list + id + i) = *(m_list + id + i +1);
    }
}
//=========================================
bool List::Insert(int id, int num){
    if(is_full()){
        std::cout << "ERROR!!! full and could not insert" << std::endl;
        return 0;
    }
    *end() = num;
    ++m_length;
    return 1;
}
bool List::Delete(int id){
    if(is_empty()){
        std::cout << "empty, nothing to delete." << std::endl;
        return 0;
    }
    backwardMove(id);
    --m_length;
    return 1;
}
std::vector<int> List::SearchByNum(int num){
    std::vector<int> result;
    for(int i = 0; i < m_length; ++i){
        if(*(m_list + i) == num){
            result.push_back(i);
        }
    }
    return result;
}
std::istream& operator >> (std::istream& is , List& list){
    std::cout << list;
    int insert_max = list.size() - list.length();
    int numbers[10] = {0};
    if(insert_max > 10){
        std::cout << "you can only input top 10 numbers" << std::endl;
        insert_max = 10;
    }
    else
        std::cout << "you can insert no more than " << insert_max << " numbers" << std::endl;
    std::cout << "start input numbers:" << std::endl;
    for(int i = 0; i < insert_max; ++i){
        std::cout << "[" << i+1 <<"]" << "\t";
    }
    std::cout << std::endl;
    for(int i = 0; i < insert_max; ++i){
        std::cin >> numbers[i];
    }
    for(int i = 0; i < insert_max; ++i){
        list.Insert(list.length(),numbers[i]);
    }
    return is;
    
}