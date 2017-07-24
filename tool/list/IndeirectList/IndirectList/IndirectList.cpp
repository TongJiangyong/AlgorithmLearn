#ifndef INDIRECT_LIST_CPP
#define INDIRECT_LIST_CPP
#include"except.h"
#include"IndirectList.h"
#include<iostream>
using namespace std;

template<class T>
IndirectList<T>::IndirectList(int MaxListSize){
    this->MaxListSize = MaxListSize;
    table = new T* [MaxListSize];
    length = 0;
}
template<class T>
IndirectList<T>::~IndirectList()
{
    for(int i = 0;i<length;i++)
    {
        //删除每一个table的数据
        delete table[i];
    }
    //删除table自身
    delete[] table;
}

//即 find必须要从1开始
template<class T>
bool IndirectList<T>::Find(int k, T& x) const
{
    //取第k个元素至x
//如果不存在第 k个元素，函数返回f a l s e，否则返回 true
    if (k < 1 || k > length)
        return false; // 不存在第k个元素
    x = *table[k-1];  //获取table所指向的值
    return true;
}

//3-26
template<class T>
IndirectList<T>&  IndirectList<T>::Insert(int k, const T& x)
{
    if (k < 0 || k > length) throw OutOfBounds(); // 不存在第k个元素
    if (length == MaxListSize) throw NoMem();
    //注意这里的length，实际就是数量
    //插入的 步骤分为两步：
    //1、插入原来的地方
    //2、处理新的数据
    for(int i = length-1;i>=k;i--)
    {
        //这里首先将数据移动位置
        table[i+1] =table[i];
    }
    //注意在间接链表中，table存储的是指针 ，所以新建立一个指针即可
    table[k] = new T ; //注意这里的new本身就是指针！！！
    * table[k] =x;
    length ++;
    return *this; //返回数据本身
}

//即 DELETE必须要从1开始
//3-25
template<class T>
IndirectList<T>& IndirectList<T>::Delete(int k, const T& x)
{
    if (k < 1 || k > length) throw OutOfBounds(); // 不存在第k个元素
    //所限找到那个数
    //free掉那个数
    //然后重新排序
    if(Find(k, x)){
        delete table[k-1];
        for(int i =k;i<length;i++){
            table[i-1] = table[i];
        }
        length --;
        return *this;
    }

}




#endif // INDIRECT_LIST_CPP
