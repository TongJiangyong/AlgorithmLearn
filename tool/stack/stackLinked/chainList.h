#ifndef CHAIN_LIST_H
#define CHAIN_LIST_H
#include<iostream>
using namespace std;

//����ѧ���ʹ����Ԫ���������������������ظ���ע�⣬�����templateһ��Ҫ��
template <class T>
class Chain;
template <class T>
class ChainIterator;
//ע���������Ľ����������ǲ�ͬ��
//ʹ��ͷ���first������ʾ��������
//ͬ����linearlist��ͬ���ڳ�ʼ����ʱ�򣬲�ָ�� ���ݣ������ڲ����ʱ�򣬸����ݼ���
template <class T>
class ChainNode {
    friend Chain<T>; //����ʹ��ChainNode��Ԫ����ʾ��ÿһ���㣬���Ի�ȡ������������ԣ�������Ԫ��ʾ������Ԫ���ε�
    //�����chain������ΪchainNode����Ԫ������chain����ʹ��chainNode�����б����ͷ������������������࣬ӵ���ڱ�������������Ȩ�������������������е�Ȩ��
    //����ָ����ͨ���������ʵ�ֵ�
    friend ChainIterator<T>;
private:
    T data;
    //����ܸ�һ����ʼ������Ϊ�ʼ��һ��ֵΪ0
    ChainNode<T> *link;
};


template<class T>
class Chain {
public:
    friend ChainIterator<T>;
    //C+=����ָ���ָ�룬ֱ�Ӹ�����
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
    ChainNode<T> *first; // ָ���һ���ڵ��ָ��
    int length;
} ;

//�����һ�������������ʵ�֣�
template<class T>
class ChainIterator{
public :
    T*Initialize(const Chain<T> &c)
    {
        //����ʹ���˾ֲ�������һ��Ҫ����Ϊ��Ԫ����Ȼ�Ļ�����not��name a type ���Ĵ���
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
