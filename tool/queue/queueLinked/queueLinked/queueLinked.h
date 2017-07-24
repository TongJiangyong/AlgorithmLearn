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
// FIFO����
public:
    LinkedQueue() {front = rear = 0;} // ���캯�� ,C++��0��Ϊ��ָ��
    ~LinkedQueue(); // ��������
    bool IsEmpty() const
    {return ((front) ? false : true);}
    bool IsFull() const;
    T First() const; // ���ص�һ��Ԫ��
    T Last() const; // �������һ��Ԫ��
    LinkedQueue<T>& Add(const T& x);
    LinkedQueue<T>& Delete(T& x);
private:
    Node<T> *front; // ָ���һ���ڵ�
    Node<T> *rear; //ָ�����һ���ڵ�
};
#include"queueLinked.cpp"
#endif // QUEUE_LINKED_H
