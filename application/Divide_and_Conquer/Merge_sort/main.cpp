#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
归并排序思路
设两个有序的子序列(相当于输入序列)放在同一序列中相邻的位置上：array[low..m]，array[m + 1..high]，
先将它们合并到一个局部的暂存序列 temp (相当于输出序列)中，待合并完成后将 temp 复制回 array[low..high]中，从而完成排序。
在具体的合并过程中，设置 i，j 和 p 三个指针，其初值分别指向这三个记录区的起始位置。
合并时依次比较 array[i] 和 array[j] 的关键字，取关键字较小（或较大）的记录复制到 temp[p] 中，
然后将被复制记录的指针 i 或 j 加 1，以及指向复制位置的指针 p加 1。重复这一过程直至两个输入的子序列有一个已全部复制完毕(不妨称其为空)，
此时将另一非空的子序列中剩余记录依次复制到 array 中即可。

即要点为：
先"分割"再"合并"



**/

/**
快速排序的效率
**/

//可用于中值快速排序的中值获取函数
//即选择出中值.....
template<class T>
void MergeSort(T a[],int n)
{
    //归并排序的特点，需要传入一个新的数组
    T *p = new T[n];
    if(p==NULL)
        return;
    //归并的过程也需要两个指针
    mergeSort(a,0,n-1,p);
    delete[] p;
}

//归并排序的特点是需要先分再合并
//因此要多做处理的过程
template<class T>
void mergeSort(T *a,int first,int last,T *temp)
{
    if(first<last)
    {
        //递归到最终，实现了middle = first = last的条件
        int middle = (first+last)/2;
        mergeSort(a,first,middle,temp);
        mergeSort(a,middle+1,last,temp);  //这里是由整除的特性引起的.....一般为一半，然后加1，即可
        mergeArray(a,first,middle,last,temp); //将有序数列并列....
    }

}

template<class T>
void mergeArray(T *a,int first,int mid,int last,T *c)
{
    int i = first,j=mid+1;
    int k=0;
    while(i<=mid&&j<=last)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<=m)
    {
        c[k++]= a[i++];
    }
    while(j<=n)
    {
        c[k++]= b[j++];
    }
    for(i = 0;i<k;i++)
        a[first+i] = temp[i];
}


//相当于指针移动
//相等的情况下，指针不会动.....
template<class T>
void mergeArrayTest(T *a,int m,T *b,int n,T *c)
{
    int i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<m)
    {
        c[k++]= a[i++];
    }
    while(j<n)
    {
        c[k++]= b[j++];
    }
}


int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int num;
cin>>num;
int *arrayInt = new int[num];
for(int i=0;i<num;i++)
{
    cin>>arrayInt[i];
}
mergeSort(arrayInt,num);
//TODO add algorithm
//QuickSort(arrayInt,num);

for(int j=0;j<num;j++){
    cout<<arrayInt[j]<<" ";
}

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
