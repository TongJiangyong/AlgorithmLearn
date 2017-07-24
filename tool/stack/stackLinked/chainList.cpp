#ifndef CHAIN_LIST_CPP
#define CHAIN_LIST_CPP
#include "chainList.h"
#include <stdio.h>
#include "except.h"



template<class T>
Chain< T >::~Chain()
{// 链表的析构函数，用于删除链表中的所有节点
ChainNode<T> *next; // 下一个节点
    while (first) {
        next = first->link;
        delete first;
        first = next;
        length--;
    }
}
template<class T>
int Chain<T>::Length()const
{
    return length;
}
//这里为获取元素，k不能为0
template<class T>
bool Chain<T>::Find(int k,T&x) const
{
    if(k<1||k>length)return false;
    ChainNode<T> *current = first;
    while(k>1&&current){
        current = current->link;
        k--;
    }
    if(current){
        x = current->data;
        return true;
    }
    return false;
}
template<class T>
int Chain<T>::Search(const T& x) const
{// 寻找x，如果发现x，则返回x的地址
//如果x不在链表中，则返回 0
    ChainNode<T> *current = first;
    int index = 1; // current的索引
    while (current && current->data != x) {
        current = current->link;
        index++;
}
    if (current) return index;
        return 0;
}

template<class T>
void Chain<T>::Output(ostream& out) const
{// 将链表元素送至输出流
    ChainNode<T> *current;
    //这里要确保最后一个指向为空
    for (current = first; current; current = current->link)
        out << current->data << " ";
}
//重载< <
template <class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
    x.Output(out); return out;
}

//3-14
//这里是插入到底几个元素中，k不可以为0
//所以这里的插入会有多种写法
template <class T>
Chain<T> &Chain<T>::Delete(int k,T&x)
{
    //首先判断k是不是有效值
    if(k<1||k>length) throw OutOfBounds();
    //处理特殊的情况
    ChainNode<T> *q = first;
    //注意这里的赋值，表示，q和first是不同的指针了，只不过指向的地方是同一个位置，
    if(k==1)
    {
        x = q->data;
        first = first->link; //这里，即将0付给了first，因为first的后面一个即为0
    }else{
        //将k移动是需要的地方
        for(int index =1;index<(k-1)&&q;index++)
            q=q->link;
        x = q->link->data;
//TJY:这里一定要注意，体会为什么，q->link要指向这个位置.....，如果是使用后删除 位置，则会乱序
//也可以在这里先建立一个缓存的结点，用于存储，q->link,然后删除这个位置即可
//delete并不消除指针本身的内容
        delete q->link;
        q->link =q->link->link;
        //delete q->link;
    }
    length--;
    //printf("x:is %d\n",x);
    return *this;
}


//这里是插入到底几个元素中，k可以为0
//所以这里的插入会有多种写法
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{// 在第k个元素之后插入x
    //如果不存在第K个元素，则引发outofBounds异常
    if(k<0||k>length) throw OutOfBounds();
    //将P指向第k个结点：
    ChainNode<T> *p = first;
    //找到P，并在p后插入
    for(int index = 1;index<k&&p;index++){
        p = p->link;
    }
    ChainNode<T> *y = new ChainNode<T>;
    y->data = x;
    if(k){
        y->link = p->link;
        p->link = y;
    }else{
        //可以看到，是不是一个循环的指针，头结点被覆盖了，即头结点并不特殊,这里自然的将0(first)付给了最后一个指针
        y->link = first;
        first =y;
    }
        length++;
        return *this;
}

template<class T>
void Chain<T>::Erase(){
    ChainNode<T> *next ;
    while(first){
        next = first->link;
        delete first;
        first = next;
    }
}

template<class T>
Chain<T> & Chain<T>::Append(const T&x)
{
//TJY：这里注意this和java不同，是指针
    return this->Insert(this->length,x);

}

#endif // CHAIN_LIST_CPP
