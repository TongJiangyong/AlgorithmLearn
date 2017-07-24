#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H

template <class T>
class LinkedQueue;

template <class T>
class Node{
    friend LinkedQueue<T>;
private:
    T data;
    Node<T> *link;
};

template<class T>
class LinkedQueue {
// FIFO对象
public:
    LinkedQueue() {front = rear = 0;} // 构造函数 ,C++中0即为空指针
    ~LinkedQueue(); // 析构函数
    bool IsEmpty() const
    {return ((front) ? false : true);}
    bool IsFull() const;
    T First() const; // 返回第一个元素
    T Last() const; // 返回最后一个元素
    LinkedQueue<T>& Add(const T& x);
    LinkedQueue<T>& Delete(T& x);
private:
    Node<T> *front; // 指向第一个节点
    Node<T> *rear; //指向最后一个节点
};
#include"queueLinked.cpp"
#endif // QUEUE_LINKED_H
