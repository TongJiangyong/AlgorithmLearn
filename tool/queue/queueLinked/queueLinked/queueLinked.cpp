#ifndef QUEUE_LINKED_CPP


#define QUEUE_LINKED_CPP
#include "queueLinked.h"
#include <stdio.h>
#include "except.h"

template<class T>
LinkedQueue<T>:: ~LinkedQueue( )
{// ��������������ɾ�����нڵ�
    Node<T> *next;
    while (front) {
        next = front->link;
        delete front;
        front = next;
    }
}
template<class T>
bool LinkedQueue<T>::IsFull() const
{// �ж϶����Ƿ�����
    Node<T> *p;
    try {p = new Node<T>;
    delete p;
    return false;}
    catch (NoMem) {return true;}
}
template<class T>
T LinkedQueue<T>::First() const
{// ���ض��еĵ�һ��Ԫ��
// �������Ϊ�գ��������쳣 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return front->data;
}
template<class T>
T LinkedQueue<T>::Last() const
{// ���ض��е����һ��Ԫ��
// �������Ϊ�գ��������쳣 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    return rear->data;
}


template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{// �� x ��ӵ����е�β��
    // ����������� n e w������NoMem �쳣
    // Ϊ��Ԫ�ش�������ڵ�
    Node<T> *p = new Node<T>;
    p->data = x;
    p->link = 0;
    // �ڶ���β������½ڵ�
    if (front) rear->link = p; //���в�Ϊ��
    else front = p; // ����Ϊ��
    rear = p;
    return *this;
}
template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{
    // ɾ����һ��Ԫ�أ���������� x
    // �������Ϊ�գ��������쳣 O u t O f B o u n d s
    if (IsEmpty()) throw OutOfBounds();
    //�����һ���ڵ��е�Ԫ��
    x = front->data;
    // ɾ����һ���ڵ�
    Node<T> *p = front;
    front = front->link;
    delete p;
    return *this;
}

#endif // QUEUE_LINKED_CPP
