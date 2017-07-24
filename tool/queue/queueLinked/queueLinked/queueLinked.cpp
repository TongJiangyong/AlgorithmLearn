#ifndef QUEUE_LINKED_CPP


#define QUEUE_LINKED_CPP
#include "queueLinked.h"
#include <stdio.h>
#include "except.h"

template<class T>
LinkedQueue<T>:: ~LinkedQueue( )
{// 队列析构函数，删除所有节点
    Node<T> *next;
    while (front) {
        next = front->link;
        delete front;
        front = next;
    }
}
template<class T>
bool LinkedQueue<T>::IsFull() const
{// 判断队列是否已满
    Node<T> *p;
    try {p = new Node<T>;
    delete p;
    return false;}
    catch (NoMem) {return true;}
}
template<class T>
T LinkedQueue<T>::First() const
{// 返回队列的第一个元素
// 如果队列为空，则引发异常 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return front->data;
}
template<class T>
T LinkedQueue<T>::Last() const
{// 返回队列的最后一个元素
// 如果队列为空，则引发异常 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return rear->data;
}


template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{// 把 x 添加到队列的尾部
    // 不捕获可能由 n e w引发的NoMem 异常
    // 为新元素创建链表节点
    Node<T> *p = new Node<T>;
    p->data = x;
    p->link = 0;
    // 在队列尾部添加新节点
    if (front) rear->link = p; //队列不为空
    else front = p; // 队列为空
    rear = p;
    return *this;
}
template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{
    // 删除第一个元素，并将其放入 x
    // 如果队列为空，则引发异常 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    //保存第一个节点中的元素
    x = front->data;
    // 删除第一个节点
    Node<T> *p = front;
    front = front->link;
    delete p;
    return *this;
}

#endif // QUEUE_LINKED_CPP
