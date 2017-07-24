//线性表的基本属性：
#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H
#include<iostream>
//#include"except.h"
using namespace std;
//注意，模板类不能分离编译.....

/*抽象数据类型LinearList {
实例
0或多个元素的有序集合
操作
C reate (): 创建一个空线性表
D e s t roy (): 删除表
I s E m p t y(): 如果表为空则返回 t r u e，否则返回false
Length (): 返回表的大小 (即表中元素个数)
Find (k,x): 寻找表中第k 个元素，并把它保存到 x 中；如果不存在，则返回f a l s e
S e a rch (x): 返回元素x在表中的位置；如果x 不在表中，则返回0
Delete (k,x): 删除表中第k 个元素，并把它保存到 x 中；函数返回修改后的线性表
I n s e rt (k,x): 在第k个元素之后插入x；函数返回修改后的线性表
Output (o u t): 把线性表放入输出流 out 之中
}*/

//一个数据结构的建立包括：
//1、基本数据方法的建立，//2、异常的处理 //3、结构的建立

//3-1
template<class T>
class LinearList{
public:
    LinearList(int MaxListSize = 10);
    ~LinearList(){delete[] element;}
    bool IsEmpty()const {return length == 0;} //这个 const表示不会去修改成员变量
    int Length()const {return length;}
    bool Find(int k,T&x) const; //这里可以看出，能使用引用，尽量使用引用，比较好一点
    int Search(const T&x) const ;
    LinearList<T> &Delete(int k,T&x);
    LinearList<T> &Insert(int k ,const T&x);
    void Output(ostream& out) const;
    //ostream& operator<<(ostream& out);
private:
    int length;
    int  MaxSize;
    T *element; //使用一维动态数组，表示链表即可
};
//注意，模板类不能分离编译，只能写在一起
#include "linearList.cpp"
#endif // LIST_ARRAY_H
