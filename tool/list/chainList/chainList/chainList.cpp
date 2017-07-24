#ifndef CHAIN_LIST_CPP
#define CHAIN_LIST_CPP
#include "chainList.h"
#include <stdio.h>
#include "except.h"



template<class T>
Chain< T >::~Chain()
{// �������������������ɾ�������е����нڵ�
ChainNode<T> *next; // ��һ���ڵ�
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
//����Ϊ��ȡԪ�أ�k����Ϊ0
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
{// Ѱ��x���������x���򷵻�x�ĵ�ַ
//���x���������У��򷵻� 0
    ChainNode<T> *current = first;
    int index = 1; // current������
    while (current && current->data != x) {
        current = current->link;
        index++;
}
    if (current) return index;
        return 0;
}

template<class T>
void Chain<T>::Output(ostream& out) const
{// ������Ԫ�����������
    ChainNode<T> *current;
    //����Ҫȷ�����һ��ָ��Ϊ��
    for (current = first; current; current = current->link)
        out << current->data << " ";
}
//����< <
template <class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
    x.Output(out); return out;
}

//3-14
//�����ǲ��뵽�׼���Ԫ���У�k������Ϊ0
//��������Ĳ�����ж���д��
template <class T>
Chain<T> &Chain<T>::Delete(int k,T&x)
{
    //�����ж�k�ǲ�����Чֵ
    if(k<1||k>length) throw OutOfBounds();
    //������������
    ChainNode<T> *q = first;
    //ע������ĸ�ֵ����ʾ��q��first�ǲ�ͬ��ָ���ˣ�ֻ����ָ��ĵط���ͬһ��λ�ã�
    if(k==1)
    {
        x = q->data;
        first = first->link; //�������0������first����Ϊfirst�ĺ���һ����Ϊ0
    }else{
        //��k�ƶ�����Ҫ�ĵط�
        for(int index =1;index<(k-1)&&q;index++)
            q=q->link;
        x = q->link->data;
//TJY:����һ��Ҫע�⣬���Ϊʲô��q->linkҪָ�����λ��.....�������ʹ�ú�ɾ�� λ�ã��������
//Ҳ�����������Ƚ���һ������Ľ�㣬���ڴ洢��q->link,Ȼ��ɾ�����λ�ü���
//delete��������ָ�뱾�������
        delete q->link;
        q->link =q->link->link;
        //delete q->link;
    }
    length--;
    //printf("x:is %d\n",x);
    return *this;
}


//�����ǲ��뵽�׼���Ԫ���У�k����Ϊ0
//��������Ĳ�����ж���д��
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{// �ڵ�k��Ԫ��֮�����x
    //��������ڵ�K��Ԫ�أ�������outofBounds�쳣
    if(k<0||k>length) throw OutOfBounds();
    //��Pָ���k����㣺
    ChainNode<T> *p = first;
    //�ҵ�P������p�����
    for(int index = 1;index<k&&p;index++){
        p = p->link;
    }
    ChainNode<T> *y = new ChainNode<T>;
    y->data = x;
    if(k){
        y->link = p->link;
        p->link = y;
    }else{
        //���Կ������ǲ���һ��ѭ����ָ�룬ͷ��㱻�����ˣ���ͷ��㲢������,������Ȼ�Ľ�0(first)���������һ��ָ��
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
//TJY������ע��this��java��ͬ����ָ��
    return this->Insert(this->length,x);

}

#endif // CHAIN_LIST_CPP
