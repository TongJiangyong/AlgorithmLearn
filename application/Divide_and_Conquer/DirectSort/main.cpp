#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
插入排序
基本思路为：
直接插入排序(Insertion Sort)的基本思想是：每次将一个待排序的记录，按其关
键字大小插入到前面已经排好序的子序列中的适当位置， 直到全部记录插入完成
为止。
设数组为 a[0…n-1]。
1. 初始时，a[0]自成 1 个有序区，无序区为 a[1..n-1]。令 i=1
2. 将 a[i]并入当前的有序区 a[0…i-1]中形成 a[0…i]的有序区间。
3. i++并重复第二步直到 i==n-1。排序完成。

即插入排序的思想为：
将原数组分为两个部分，第一个部分只有一个元素，每次都向里面插入一个元素进行递增即可.....
即算法的实现也分为两个部分
1、分离原有数组，以数组下标为1为初始属猪，从数组游标为1的地方开始遍历，找到每一个遍历数组可以插入的位置
2、插入初始数组，并移动整个数组的位置
**/






//自己尝试理解后写的代码看上去可用
template<class T>
void InsertSort_1(T *a,int n)
{
    int length = 1;
    for(int i=1;i<n;i++)
    {
        int j=0;
        for(;j<length;j++)
        {
            if(a[i]<a[j])
                break;
        }
        T temp = a[i];
        for(int k=length;k>j;k--)
        {
            a[k]=a[k-1];
        }
        a[j]=temp;
        length++;
    }
}
//学习别人的代码，将搜索和数据移动放在同一代码段中为.....
//每次a[i]先和前面一个数据a[i-1]比较，如果a[i] > a[i-1]说明a[0…i]也是有序的，
//无须调整。否则就令j=i-1,temp=a[i]。然后一边将数据a[j]向后移动一边向前搜索，
//当有数据a[j]<a[i]时停止并将temp放到a[j + 1]处
//如果是从后向前移动，搜索和移动其实可以放在一起......
template<class T>
void InsertSort_2(T *a,int n)
{
    int i, j;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            int temp = a[i];
            for(j=(i-1);j>=0&&a[j]>temp;j--)
                a[j+1] = a[j];
            a[j+1] = temp;
        }
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
    InsertSort_2(arrayInt,num);
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
