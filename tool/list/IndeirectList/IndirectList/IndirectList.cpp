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
        //ɾ��ÿһ��table������
        delete table[i];
    }
    //ɾ��table����
    delete[] table;
}

//�� find����Ҫ��1��ʼ
template<class T>
bool IndirectList<T>::Find(int k, T& x) const
{
    //ȡ��k��Ԫ����x
//��������ڵ� k��Ԫ�أ���������f a l s e�����򷵻� true
    if (k < 1 || k > length)
        return false; // �����ڵ�k��Ԫ��
    x = *table[k-1];  //��ȡtable��ָ���ֵ
    return true;
}

//3-26
template<class T>
IndirectList<T>&  IndirectList<T>::Insert(int k, const T& x)
{
    if (k < 0 || k > length) throw OutOfBounds(); // �����ڵ�k��Ԫ��
    if (length == MaxListSize) throw NoMem();
    //ע�������length��ʵ�ʾ�������
    //����� �����Ϊ������
    //1������ԭ���ĵط�
    //2�������µ�����
    for(int i = length-1;i>=k;i--)
    {
        //�������Ƚ������ƶ�λ��
        table[i+1] =table[i];
    }
    //ע���ڼ�������У�table�洢����ָ�� �������½���һ��ָ�뼴��
    table[k] = new T ; //ע�������new�������ָ�룡����
    * table[k] =x;
    length ++;
    return *this; //�������ݱ���
}

//�� DELETE����Ҫ��1��ʼ
//3-25
template<class T>
IndirectList<T>& IndirectList<T>::Delete(int k, const T& x)
{
    if (k < 1 || k > length) throw OutOfBounds(); // �����ڵ�k��Ԫ��
    //�����ҵ��Ǹ���
    //free���Ǹ���
    //Ȼ����������
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
