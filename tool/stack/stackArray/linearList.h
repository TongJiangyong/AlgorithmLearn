//���Ա�Ļ������ԣ�
#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H
#include<iostream>
//#include"except.h"
using namespace std;
//ע�⣬ģ���಻�ܷ������.....

/*������������LinearList {
ʵ��
0����Ԫ�ص����򼯺�
����
C reate (): ����һ�������Ա�
D e s t roy (): ɾ����
I s E m p t y(): �����Ϊ���򷵻� t r u e�����򷵻�false
Length (): ���ر�Ĵ�С (������Ԫ�ظ���)
Find (k,x): Ѱ�ұ��е�k ��Ԫ�أ����������浽 x �У���������ڣ��򷵻�f a l s e
S e a rch (x): ����Ԫ��x�ڱ��е�λ�ã����x ���ڱ��У��򷵻�0
Delete (k,x): ɾ�����е�k ��Ԫ�أ����������浽 x �У����������޸ĺ�����Ա�
I n s e rt (k,x): �ڵ�k��Ԫ��֮�����x�����������޸ĺ�����Ա�
Output (o u t): �����Ա��������� out ֮��
}*/

//һ�����ݽṹ�Ľ���������
//1���������ݷ����Ľ�����//2���쳣�Ĵ��� //3���ṹ�Ľ���

//3-1
template<class T>
class LinearList{
public:
    LinearList(int MaxListSize = 10);
    ~LinearList(){delete[] element;}
    bool IsEmpty()const {return length == 0;} //��� const��ʾ����ȥ�޸ĳ�Ա����
    int Length()const {return length;}
    bool Find(int k,T&x) const; //������Կ�������ʹ�����ã�����ʹ�����ã��ȽϺ�һ��
    int Search(const T&x) const ;
    LinearList<T> &Delete(int k,T&x);
    LinearList<T> &Insert(int k ,const T&x);
    void Output(ostream& out) const;
    //ostream& operator<<(ostream& out);
private:
    int length;
    int  MaxSize;
    T *element; //ʹ��һά��̬���飬��ʾ������
};
//ע�⣬ģ���಻�ܷ�����룬ֻ��д��һ��
#include "linearList.cpp"
#endif // LIST_ARRAY_H
