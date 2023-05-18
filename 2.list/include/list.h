/**
 * *file name: list.h
 * *author: lihuax
 * *version: 0.1
 * !description:
 */
#include"../include/header.h"
#ifndef _LIHUAX_LIST_
#define _LIHUAX_LIST_

class List{
private:
    int* m_list;//todo head location of the list
    int m_size;//todo size of the list
    int m_length;//todo length of the list
    /**
     * @brief make the numbers in list move forward from id
     * ! dangerous function
     * @param id 
     * ! need judge is_full() before using!
     * * begin ------> end (forward)
     */
    void forwardMove(int);
    /**
     * @brief make the numbers in list move backward from id
     * ! dangerous function
     * @param id 
     * ! number id will be lost!
     * * (backward) begin <------ end
     */
    void backwardMove(int);
    /**
     * @brief get head location
     */
    int* begin();
    /**
     * @brief get tail location
     */
    int* end();
    /**
     * ?not realize yet
     */
    void foreachInRange(int, int, void(*)());
    /**
     * ?not realize yet
     */
    void foreachInRangeReverse(int, int, void(*)());

public:
    //============== 重构与析构函数===============//
    List();
    List(int);
    ~List();

    /**
     * @brief 在id处插入num
     * @return 1 插入成功
     *         0 插入失败
     * @param id 插入处的序号
     * @param num 要插入的数字
     */
    bool Insert(int, int);
    /**
     * @brief 删除id处的数字
     * @return 删除成功
     * 
     * @param id 要删除的序号
     */
    bool Delete(int);
    //void Delete();
    /**
     * @brief 交换id_1, id_2两处的数字
     * 
     * @param id_1 ~
     * @param id_2 ~
     */
    void Exchange(int, int);//
    /**
     * @brief 将id处的数字换成num
     * 
     * @param id 要更改的数字序号
     * @param num 换完的数字
     */
    void Change(int, int);//
    /**
     * @brief 通过id进行查找
     * 
     * @param id ~
     */
    int SearchById(int);//
    /**
     * @brief 通过数字进行查找
     * @return 数据为num的id向量
     * 
     * @param num 要查找的数字
     */
    std::vector<int> SearchByNum(int);
    /**
     * @brief 判断list是否已满
     * @return 1 full
     * @return 0 not full
     */
    bool is_full();//
    /**
     * @brief whether the list is empty
     * @return 1 empty
     * @return 0 not empty
     */
    bool is_empty();//
    /**
     * @brief get the size of list
     * @return m_size
     */
    int size();//
    /**
     * @brief get the length of the list
     * @return m_length
     */
    int length();//
    /**
     * @brief to print the list better 
     */
    friend std::ostream& operator << (std::ostream& , const List&);//
    /**
     * @brief to input the numbers better
     */
    friend std::istream& operator >> (std::istream& , List&);//
};

#endif