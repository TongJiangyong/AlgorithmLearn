#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
//#include "linearList.h"
//#define USE_ARRAY_LIST_H
//���ü̳еķ�������stack��
//����ѧϰһ�¼̳е� ʹ�÷���
#ifdef USE_ARRAY_LIST_H
template<class T>
class StackArray:public LinearList<T>{
// LIFO ����
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
//�Զ����stack
template<class T>
class StackArray{
// LIFO ����
public:
    StackArray(int MaxStackSize = 10);
    ~StackArray () {delete [] stack;} //��̬�����һ��Ҫ�ͷ�
    bool IsEmpty() const {return top == -1;}
    bool IsFull() const {return top == MaxTop ; }
    T Top() const;
    StackArray<T>& Add(const T& x);
    StackArray<T>& Delete(T& x);
private:
    int top; // ջ�� //Top������Ϊʵ�ʵ�ָ��
    int MaxTop; // ����ջ��ֵ
    T *stack; // ��ջԪ������ //ע��ָ����Դ�����������
} ;

#include"stackArray.cpp"
#endif // USE_ARRAY_LIST_H



#endif // STACK_ARRAY_H
