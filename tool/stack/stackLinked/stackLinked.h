#ifndef STACK_LINKED_H
#define STACK_LINKED_H
#include <stdio.h>
#include "except.h"
//#define USE_CHAINlIST
#ifdef USE_CHAINlIST
#include "chainList.h"
template<class T>
class StackLinked : private Chain<T> {
public:
    //��ΪC++ ֧�� ���ؼ̳У�����super()�޷���� ���� ����һ������ ��ͬ��������
    //��ô �� ��� ���أ�
    //ֻ�� �� ������::������ �����������ˡ�
    StackLinked(int maxTop):Chain<T>() {
        this->maxTop = maxTop;
    };
    //~StackLinked:~Chain<T>() {}//��̬�����һ��Ҫ�ͷ�
    bool IsEmpty() const {return Chain<T>::IsEmpty();}
    bool IsFull() const {
        return Chain<T>::length == this->maxTop ;
    }
    T Top() const{
        if(IsEmpty())throw OutOfBounds();
        T x;
        Chain<T>::Find(1,x);
        return x;
    };
    StackLinked<T>& Add(const T& x){
        Chain<T>::Insert(0, x);
        return *this;
    }
    StackLinked<T>& Delete(T& x){
        Chain<T>::Delete(1,x);
        return *this;
    }
private :
    int maxTop;
};
#else

//ջ������Ĵ���ʵ������ʹ��һ��ָ�룬ʼ��ָ��ͷ�������������е�һ������
template<class T>
class StackLinked;

template<class T>
class Node{
    friend class StackLinked<T>;
private:
    T data;
    Node <T>* link;
};

template<class T>
class StackLinked{
public:
    StackLinked () {top = 0;}
    ~ StackLinked( ) ;
    bool IsEmpty() const {return top==0;}
    bool IsFull() const;
    T Top() const;
    StackLinked<T>& Add(const T& x);
    StackLinked<T>& Delete(T& x);
private:
    Node<T> *top; // ָ��ջ���ڵ�
};







#include"stackLinked.cpp"

#endif // USE_CHAINlIST
#endif // STACK_LINKED_H
