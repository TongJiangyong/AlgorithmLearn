#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
/**
二分法查找/折半查找
用于查找线性表比较好.....
而且线性表要是递增的比较好.....

折半查找的前提条件是需要有序表顺序存储，对于静态查找表，一次排序后不再变化，折半查找能得到不错的效率。
但对于需要频繁执行插入或删除操作的数据集来说，维护有序的排序会带来不小的工作量，那就不建议使用

**/

template <class T>

int getArrayLen(T& array)

{
    //数组作为参数传给函数时传的是指针而不是数组，传递的是数组的首地址
    //如果这里不是引用，则永远都是1，一定要注意即可....
    return (sizeof(array) / sizeof(array[0]));
}
//在C/C++中，如果传递到是指针，则一般无法计算数组长度，strlen是例外.....清楚原理即可....
int BinarySearch_1(int a[],int value,int n)
{
    int low ,high,mid;
    low = 0;
    high =n-1;
    //这里low和high在不断变化
    while(low<=high)
    {
        //二分法需要先计算middle的值
        mid=(low+high)/2;
        if(a[mid]==value)
        {
             return mid;
        }
        else if(a[mid]>value)
        {
             high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}

//使用递归实现二分法
//关键是计算出low and hight即可.....
int BinarySearch_2(int a[], int value, int low, int high)
{
    int mid = low+(high-low)/2;
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return BinarySearch2(a, value, low, mid-1);
    if(a[mid]<value)
        return BinarySearch2(a, value, mid+1, high);
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
cout<<BinarySearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
