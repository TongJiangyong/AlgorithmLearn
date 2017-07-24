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
    //因为C++ 支持 多重继承，所以super()无法获得 究竟 是那一个父类 的同名方法。
    //那么 该 如何 做呢？
    //只能 用 父类名::方法名 这样来调用了。
    StackLinked(int maxTop):Chain<T>() {
        this->maxTop = maxTop;
    };
    //~StackLinked:~Chain<T>() {}//动态分配的一定要释放
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

//栈对这个的处理，实际上是使用一个指针，始终指向头部，来代表所有的一链数据
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
    Node<T> *top; // 指向栈顶节点
};







#include"stackLinked.cpp"

#endif // USE_CHAINlIST
#endif // STACK_LINKED_H
