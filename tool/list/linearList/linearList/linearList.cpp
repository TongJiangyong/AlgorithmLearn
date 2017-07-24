#ifndef LIST_CPP
#define LIST_CPP
#include"linearList.h"
#include"except.h"
#include "iostream"
using namespace std;
//����һ�������쳣����
//3-2

//��������������������󳤶ȣ����ƶ����ȣ����Ա������
//3-3
template<class T>
LinearList<T>::LinearList(int MaxListSize){
    MaxSize = MaxListSize;
    element = new  T[MaxSize];
    length = 0;
}

template<class T>
bool LinearList<T>::Find(int k,T&x) const{
    if (k < 1 || k > length) return false; // �����ڵ�k��Ԫ��
    x = element[k - 1];
    return true;
}


template<class T>
int LinearList<T>::Search(const T& x) const
{// ����x������ҵ����򷵻�x���ڵ�λ��
// ���x���ڱ��У��򷵻�0
    for (int i = 0; i < length; i++){
        if (element[i] == x)
            return ++i;
    }
    return 0;
}
//3-4
template<class T>
LinearList<T> & LinearList<T>::Delete(int k,T&x){

// ��������ڵ�k��Ԫ�أ��������쳣O u t O f B o u n d s
    if (Find(k, x)) {// ��Ԫ�� k+l, ...��ǰ�ƶ�һ��λ��
        for (int i = k; i < length; i++)
            element[i-1] = element[i];
        length-- ;
        return *this; //���ض�����thisֻ�ܱ�ʾָ�룬Ȼ���*����ʾ������
    }else throw OutOfBounds();
}
//3-5
//����һ���µ�Ԫ��
template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{// �ڵ�k��Ԫ��֮�����x
// ��������ڵ�k��Ԫ�أ��������쳣O u t O f B o u n d s
// ������Ѿ������������쳣 N o M e m
    if (k < 0 || k > length)
        throw OutOfBounds();
    if (length == MaxSize)
        throw NoMem();
    //����ƶ�һ��λ��
    for (int i = length-1; i >= k; i--)
        element[i+1] = element[i];
    element[k] = x;
    length++ ;
    return *this;
}

//3-6
template<class T>
void LinearList<T>::Output(ostream& out) const
{ //�ѱ������������
    for (int i = 0; i < length; i++)
        out << element[i] << " ";
}

//ע��������غ������������κεط�
//���� < <
template <class T>
ostream& operator<<(ostream& out, const LinearList<T>& x){
    x.Output(out); return out;
}
#endif

