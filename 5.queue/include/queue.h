#ifndef QUEUE_H
#define QUEUE_H

const int MAX_SIZE = 100; // 定义队列的最大长度

class Queue {
public:
    Queue(); // 构造函数，初始化队列
    void enqueue(int value); // 入队操作
    int dequeue(); // 出队操作
    bool isEmpty(); // 判断队列是否为空
    bool isFull(); // 判断队列是否已满
    void print(); // 打印队列中的所有元素
private:
    int front; // 队首索引
    int rear; // 队尾索引
    int data[MAX_SIZE]; // 存储队列元素的数组
};

#endif
