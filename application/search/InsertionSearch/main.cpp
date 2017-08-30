#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
/**
插值查找法
插值查找=找适合于存储结构为顺序存储或链接存储的线性表。
是一种对二分法的改进...

即，将二分之一的插值，改进为,与值相关的插值
　　mid=(low+high)/2, 即mid=low+1/2*(high-low);
　　通过类比，我们可以将查找的点改进为如下：
　　mid=low+(key-a[low])/(a[high]-a[low])*(high-low)，
充分利用了排位和值的比值关系....

**/

template <class T>

int getArrayLen(T& array)

{
    //数组作为参数传给函数时传的是指针而不是数组，传递的是数组的首地址
    //如果这里不是引用，则永远都是1，一定要注意即可....
    return (sizeof(array) / sizeof(array[0]));
}
//在C/C++中，如果传递到是指针，则一般无法计算数组长度，strlen是例外.....清楚原理即可....
//插值查找使用的是递归的方法实现
//这个递归实际上是单路的，即，会沿着一路一直递归下去，直到返回.....
int insertionSearch(int a[],int value,int low,int high)
{
    //这里是异常终止条件
    if(low>=high){
        return -1;
    }
    int mid =low+(value-a[low])/(a[high]-a[low])*(high-low);
    //这里是正常终止条件
    if(a[mid]==value)
    {
        return mid;
    }
    else if(a[mid]>value)
    {
        return insertionSearch(a,value,low,mid-1);

    }
    else if(a[mid]<value)
    {
        return insertionSearch(a,value,mid+1,high);
    }

}

int InsertionSearch(int a[],int value,int n)
{
    int high = n-1;
    int low =0;
    return insertionSearch(a,value,low,high);
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
cout<<InsertionSearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
