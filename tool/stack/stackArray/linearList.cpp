#ifndef LIST_CPP
#define LIST_CPP
#include"linearList.h"
#include"except.h"
#include "iostream"
using namespace std;
//定义一个处理异常的类
//3-2

//基本操作函数：给定最大长度，并制定长度，线性表的特征
//3-3
template<class T>
LinearList<T>::LinearList(int MaxListSize){
    MaxSize = MaxListSize;
    element = new  T[MaxSize];
    length = 0;
}

template<class T>
bool LinearList<T>::Find(int k,T&x) const{
    if (k < 1 || k > length) return false; // 不存在第k个元素
    x = element[k - 1];
    return true;
}


template<class T>
int LinearList<T>::Search(const T& x) const
{// 查找x，如果找到，则返回x所在的位置
// 如果x不在表中，则返回0
    for (int i = 0; i < length; i++){
        if (element[i] == x)
            return ++i;
    }
    return 0;
}
//3-4
template<class T>
LinearList<T> & LinearList<T>::Delete(int k,T&x){

// 如果不存在第k个元素，则引发异常O u t O f B o u n d s
    if (Find(k, x)) {// 把元素 k+l, ...向前移动一个位置
        for (int i = k; i < length; i++)
            element[i-1] = element[i];
        length-- ;
        return *this; //返回对象本身，this只能表示指针，然后加*，表示对象本身
    }else throw OutOfBounds();
}
//3-5
//插入一个新的元素
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{// 在第k个元素之后插入x
// 如果不存在第k个元素，则引发异常O u t O f B o u n d s
// 如果表已经满，则引发异常 N o M e m
    if (k < 0 || k > length)
        throw OutOfBounds();
    if (length == MaxSize)
        throw NoMem();
    //向后移动一个位置
    for (int i = length-1; i >= k; i--)
        element[i+1] = element[i];
    element[k] = x;
    length++ ;
    return *this;
}

//3-6
template<class T>
void LinearList<T>::Output(ostream& out) const
{ //把表输送至输出流
    for (int i = 0; i < length; i++)
        out << element[i] << " ";
}

//注意这个重载函数，可以在任何地方
//重载 < <
template <class T>
ostream& operator<<(ostream& out, const LinearList<T>& x){
    x.Output(out); return out;
}
#endif

