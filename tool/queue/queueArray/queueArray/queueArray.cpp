#ifndef QUEUE_ARRAY_CPP


#define QUEUE_ARRAY_CPP
#include "queueArray.h"
#include <stdio.h>
#include "except.h"

template<class T>
QueueArray<T>::QueueArray(int MaxQueueSize)
{// 创建一个容量为 M a x Q u e u e S i z e的空队列
    //默认最大值加1
    MaxSize = MaxQueueSize + 1;
    queue = new T[MaxSize];
    front = rear = 0;
}

template<class T>
T QueueArray<T>::First() const
{// 返回队列的第一个元素
// 如果队列为空，则引发异常 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return queue[(front + 1) % MaxSize];
}

template<class T>
T QueueArray<T>::Last() const
{// 返回队列的最后一个元素
    // 如果队列为空，则引发异常 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return queue[rear];
}

template<class T>
QueueArray<T>& QueueArray<T>::Add(const T& x)
{// 把 x 添加到队列的尾部
    // 如果队列满，则引发异常 NoMem
    if (IsFull()) throw NoMem();
    rear = (rear + 1) % MaxSize;
    queue[rear] = x;
    return *this;
}
template<class T>
QueueArray<T>& QueueArray<T>::Delete(T& x)
{// 删除第一个元素，并将其送入 x
    // 如果队列为空，则引发异常 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    front = (front + 1) % MaxSize;
    x = queue[front];
    return *this;
}


#endif // QUEUE_ARRAY_CPP
