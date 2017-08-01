#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**

冒泡排序的思路：
即每次排序，每一轮循环，都将数列中最大的数，通过两两对比，冒泡选出来，
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

//可用于中值快速排序的中值获取函数
//即选择出中值.....
//这一个冒泡是先排最大的，即，通过两两对比，每次外层循环，都将最大的通过两两比较冒泡出来
//https://baike.baidu.com/item/%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F/4602306?fr=aladdin
template<class T>
void BubbleSort_1(T a[],int n)
{
    //这里i可以小于n可以小于n-1，因为最后一个就可以不用排了.....
    for(int i=0;i<n;i++)
        for(int j=0;j<(n-i-1);j++)
            if(a[j]>a[j+1])
                Swap(a[j],a[j+1]);

}

//可用于中值快速排序的中值获取函数
//即选择出中值.....
//这一个冒泡是先排最小的，通过两两对比，每次外层循环，将最小的列出来
template<class T>
void BubbleSort_2(T a[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j])
                Swap(a[i],a[j]);
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
    BubbleSort_1(arrayInt,num);
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
