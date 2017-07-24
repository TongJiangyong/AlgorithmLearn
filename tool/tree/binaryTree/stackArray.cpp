#ifndef STACK_ARRAY_CPP
#define STACK_ARRAY_CPP
#include "stackArray.h"
#include <stdio.h>
#include "except.h"

template<class T>
StackArray<T>::StackArray(int MaxStackSize)
{// Stack �๹�캯��
    MaxTop = MaxStackSize - 1;
    stack = new T[MaxStackSize];
    top = -1;
}
template<class T>
T StackArray<T>::Top() const
{// ����ջ��Ԫ��
    if (IsEmpty()) throw OutOfBounds();
    else return stack[top];
}
template<class T>
StackArray<T>& StackArray<T>::Add(const T& x)
{ //���Ԫ��x
    if (IsFull()) throw NoMem();
    stack[++top] = x;
    return *this;
}
template<class T>
StackArray<T>& StackArray<T>::Delete(T& x)
{// ɾ��ջ��Ԫ�أ����������� x
    if (IsEmpty()) throw OutOfBounds();
    x = stack[top--];
    return *this;
}
#endif // STACK_ARRAY_CPP
