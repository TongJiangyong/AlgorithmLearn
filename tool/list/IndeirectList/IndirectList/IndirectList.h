#ifndef INDIRECT_LIST_h
#define INDIRECT_LIST_h

#include<iostream>
using namespace std;

//使用间接寻址最大的坏处在于，如果不做修改，则不能动态的增加长度
//而且不能随意的插入
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
    T **table; //一维数组的指针
};


#include"IndirectList.cpp"

#endif // INDIRECT_LIST_h
