#ifndef INDIRECT_LIST_h
#define INDIRECT_LIST_h

#include<iostream>
using namespace std;

//ʹ�ü��Ѱַ���Ļ������ڣ���������޸ģ����ܶ�̬�����ӳ���
//���Ҳ�������Ĳ���
template<class T>
class IndirectList{
public:
    IndirectList(int MaxListSize = 10);
    ~IndirectList();
    bool IsEmpty()const{return length;}
    bool Find(int k, T& x) const;
    int GetLength(){return length;};
    int Search(const T& x) const;
    IndirectList<T>& Delete(int k, const T& x);
    IndirectList<T>& Insert(int k, const T& x);
    void Output(ostream& out) const;
private:
    int length;
    int MaxListSize;
    T **table; //һά�����ָ��
};


#include"IndirectList.cpp"

#endif // INDIRECT_LIST_h
