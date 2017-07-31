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

这里也能看出归并排序和快速排序很不一样的地方：
归并排序是比较典型的分治算法，首先将大问题拆成小问题后，分成小问题，但是当前问题并没有解决，解决完没有小问题后，递归来解决大问题****
对快速排序算法
则也有分治算法的思想，但是和归并算法比起来不太典型，在分治前，每一次循环都做好了当前循环体的事情，然后再透过分治解决小区域的事情****

http://blog.csdn.net/robertcpp/article/details/51540976
http://blog.csdn.net/morewindows/article/details/7961256
**/






//这个函数是指对一个数组进行归并的过程
//即，刻意将一个数组分为两段，然后使用归并的思想进行归并
//通过控制游标，来控制数组的排序，其中，数组c为一个中间的数组
template<class T>
void mergeArray(T *a,int first,int mid,int last,T *c)
{
    int i = first,j=mid+1;
    int k=0;
    while(i<=mid&&j<=last)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
    {
        c[k++]= a[i++];
    }
    while(j<=last)
    {
        c[k++]= a[j++];
    }
    for(i = 0;i<k;i++)
        a[first+i] = c[i];
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
        mergeSort(a,first,middle,temp);     //左边设置为有序序列.....
        mergeSort(a,middle+1,last,temp);  //这里是由整除的特性引起的.....一般为一半，然后加1，即可
       //将有序数列并列...需要形象的去理解这个分化，然后合并的过程，合并的过程，是对数组a处理，通过控制游标的变化来移动数据，所以使用一个数组也是可以的
       //只要保证预备归并的两个数组是有序的即可......
        mergeArray(a,first,middle,last,temp);
    }

}
//可用于中值快速排序的中值获取函数
//即选择出中值.....
template<class T>
void MergeSort(T a[],int n)
{
    //归并排序的特点，需要传入一个新的数组用于中间使用的过程.......
    T *p = new T[n];
    if(p==NULL)
        return;
    //归并的过程也需要两个指针
    mergeSort(a,0,n-1,p);
    delete[] p;
}

//相当于指针移动
//相等的情况下，指针不会动.....
template<class T>
void mergeArrayTest(T *a,int m,T *b,int n,T *temp)
{
    int i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
            temp[k++]=a[i++];
        else
            temp[k++]=b[j++];
    }
    while(i<m)
    {
        temp[k++]= a[i++];
    }
    while(j<n)
    {
        temp[k++]= b[j++];
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
    MergeSort(arrayInt,num);
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
