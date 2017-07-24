#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
//#include "linearList.h"
//#define USE_ARRAY_LIST_H
//采用继承的方法定义stack：
//这里学习一下继承的 使用方法
#ifdef USE_ARRAY_LIST_H
template<class T>
class StackArray:public LinearList<T>{
// LIFO 对象
public:
    StackArray(int MaxStackSize = 10):LinearList<T>(MaxStackSize) {}
    bool IsEmpty() const
    {
        return LinearList<T>::IsEmpty();
    }
    bool IsFull() const
    {
        return (LinearList<T>::Length() == GetMaxSize());
    }
    T Top() const
    {
        if (IsEmpty()) throw OutOfBounds();
        T x;
        LinearList<T>::Find(LinearList<T>::Length(), x);
        return x;
    }
    StackArray<T>& Add(const T& x)
    {
        LinearList<T>::Insert(LinearList<T>::Length(), x);
        return *this;
    }
    StackArray<T>& Delete(T& x)
    {
        LinearList < T >::Delete(LinearList<T>::Length(), x);
        return *this;
    }
    int GetMaxSize(){
        return LinearList<T>::MaxStackSize;
    }
} ;

#else
//自定义的stack
template<class T>
class StackArray{
// LIFO 对象
public:
    StackArray(int MaxStackSize = 10);
    ~StackArray () {delete [] stack;} //动态分配的一定要释放
    bool IsEmpty() const {return top == -1;}
    bool IsFull() const {return top == MaxTop ; }
    T Top() const;
    StackArray<T>& Add(const T& x);
    StackArray<T>& Delete(T& x);
private:
    int top; // 栈顶 //Top在这里为实际的指针
    int MaxTop; // 最大的栈顶值
    T *stack; // 堆栈元素数组 //注意指针可以代表整个数组
} ;

#include"stackArray.cpp"
#endif // USE_ARRAY_LIST_H



#endif // STACK_ARRAY_H
