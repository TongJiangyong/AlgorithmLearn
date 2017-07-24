#ifndef QUEUE_ARRAY_CPP


#define QUEUE_ARRAY_CPP
#include "queueArray.h"
#include <stdio.h>
#include "except.h"

template<class T>
QueueArray<T>::QueueArray(int MaxQueueSize)
{// ����һ������Ϊ M a x Q u e u e S i z e�Ŀն���
    //Ĭ�����ֵ��1
    MaxSize = MaxQueueSize + 1;
    queue = new T[MaxSize];
    front = rear = 0;
}

template<class T>
T QueueArray<T>::First() const
{// ���ض��еĵ�һ��Ԫ��
// �������Ϊ�գ��������쳣 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return queue[(front + 1) % MaxSize];
}

template<class T>
T QueueArray<T>::Last() const
{// ���ض��е����һ��Ԫ��
    // �������Ϊ�գ��������쳣 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return queue[rear];
}

template<class T>
QueueArray<T>& QueueArray<T>::Add(const T& x)
{// �� x ��ӵ����е�β��
    // ������������������쳣 NoMem
    if (IsFull()) throw NoMem();
    rear = (rear + 1) % MaxSize;
    queue[rear] = x;
    return *this;
}
template<class T>
QueueArray<T>& QueueArray<T>::Delete(T& x)
{// ɾ����һ��Ԫ�أ����������� x
    // �������Ϊ�գ��������쳣 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    front = (front + 1) % MaxSize;
    x = queue[front];
    return *this;
}


#endif // QUEUE_ARRAY_CPP
