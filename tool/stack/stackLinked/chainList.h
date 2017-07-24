#ifndef CHAIN_LIST_H
#define CHAIN_LIST_H
#include<iostream>
using namespace std;

//这里学会对使用友元进行声明，声明并不会重复，注意，这里的template一定要加
template <class T>
class Chain;
template <class T>
class ChainIterator;
//注意这里，链表的结点和链表本身是不同的
//使用头结点first，来表示整个链表
//同样与linearlist相同，在初始化的时候，不指定 数据，但是在插入的时候，给数据即可
template <class T>
class ChainNode {
    friend Chain<T>; //这里使用ChainNode友元，表示，每一个点，可以获取链表的所有属性，即，友元表示，被友元修饰的
    //这里的chain被声明为chainNode的友元，即，chain可以使用chainNode的所有变量和方法，即，被声明的类，拥有在被声明处的所有权利，即里面有外面所有的权利
    //智能指针是通过这个方法实现的
    friend ChainIterator<T>;
private:
    T data;
    //最好能给一个初始化，因为最开始不一定值为0
    ChainNode<T> *link;
};


template<class T>
class Chain {
public:
    friend ChainIterator<T>;
    //C+=赋予指针空指针，直接给即可
    Chain() {first = 0;length = 0;
    cout<<"init chain"<<endl;
    }
    ~Chain( ) ;
    bool IsEmpty() const {return first == 0;}
    int Length() const;
    bool Find(int k, T& x) const;
    int Search(const T& x) const;
    Chain<T>& Delete(int k, T& x);
    Chain<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;
    void Erase();
    Chain<T>& Append(const T& x);

private:
    ChainNode<T> *first; // 指向第一个节点的指针
    int length;
} ;

//这里给一个链表遍历器的实现：
template<class T>
class ChainIterator{
public :
    T*Initialize(const Chain<T> &c)
    {
        //这里使用了局部变量，一定要声明为友元，不然的话，“not　name a type ”的错误
        location = c.first;
        if(location){
            return &location->data;
        }
        return 0;
    }
    T *Next()
    {
        if(!location){
            return 0;
        }
        location =location->link;
        if(location)
            return &location->data;
        return 0;
    }

private:
    ChainNode<T> *location;
};

#include "chainList.cpp"
#endif // CHAIN_LIST_H
