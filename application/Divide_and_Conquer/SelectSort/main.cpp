#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
选择排序思路
直接选择排序和直接插入排序类似，都将数据分为有序区和无序区，所不同的是
直接插入排序是将无序区的第一个元素直接插入到有序区以形成一个更大的有
序区，
而直接选择排序是从无序区选一个最小的元素直接放到有序区的最开始的地方。
即直接插入排序：每次对有序区进行对比后再插入
选择排序：每次对无序区做选择后再插入


设数组为 a[0…n-1]。
4. 初始时，数组全为无序区为 a[0..n-1]。令 i=0
5. 在无序区 a[i…n-1]中选取一个最小的元素， 将其与 a[i]交换。 交换之后 a[0…i]
就形成了一个有序区。
6. i++并重复第二步直到 i==n-1。排序完成。
**/
//相当于指针移动
//相等的情况下，指针不会动.....
template<class T>
void Swap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void SelectSort(T a[],int n)
{
    int tempIndex;
    //遍历所有的数组
    for(int i=0;i<n;i++)
    {
        //每次选出第一个无序区的第一个元素做为参考数
        //对无序区进行处理......
        tempIndex = i;
        //这里给出了从一个数组中选出最小元素的代码.....
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[tempIndex])
                tempIndex = j;
        }
        //将选出的数，与无序区的第一个数进行交换
        Swap(a[i],a[tempIndex]);
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
    SelectSort(arrayInt,num);
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
