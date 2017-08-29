#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
/**
顺序查找法：
顺序查找适合于存储结构为顺序存储或链接存储的线性表。


**/

template <class T>

int getArrayLen(T& array)

{
    //数组作为参数传给函数时传的是指针而不是数组，传递的是数组的首地址
    //如果这里不是引用，则永远都是1，一定要注意即可....
    return (sizeof(array) / sizeof(array[0]));
}
//在C/C++中，如果传递到是指针，则一般无法计算数组长度，strlen是例外.....清楚原理即可....
int SequenceSearch(int a[],int value,int n)
{
    int i;
    for(i=0; i<n; i++)
        if(a[i]==value)
            return i;
    return -1;
}


int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int num;
cin>>num;
//注意这里可以知道，动态数组的长度，没法直接使用len的方式求得
//因为在C语言中，指针和数组是不同的....这一点还是要记住的.....
int *arrayInt = new int[num];
int test[] ={1,2,6,8};
for(int i=0;i<num;i++)
{
    cin>>arrayInt[i];
    cout<<arrayInt[i]<<" ";
}
cout<<endl;
int searchNum;
cin>>searchNum;
cout<<SequenceSearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
