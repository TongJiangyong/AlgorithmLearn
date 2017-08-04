#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
希尔排序思路（分组插入排序）
基本思想是：先将整个待排元素序列分割成若干个子序列（由相隔某个
“增量”的元素组成的）分别进行直接插入排序，然后依次缩减增量再进行排序，
待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插
入排序
即在所有的元素基本有序的情况下，使用直接插入排序比较高效

即，希尔排序可以看做是直接插入排序的改进方法：
利用了插入排序的两个特点：
1、对组内元素较少的时候，排序效率较高
2、对组内大致排序完成的情况，排序效率较高
http://www.cnblogs.com/jingmoxukong/p/4303279.html
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

/**
这里是对希尔排序理解算法的实现.....
1、每次将步长减半，步长即，同一组中，间隔的数据

**/
template<class T>
void ShellSort_1(T a[],int n)
{
    int i,j=0,gap;
    //gap 初始为n，每次减半，这里gap/2每次都最后都能大于1
    for(gap = n/2;gap>0;gap/=2)
    {
        //分组后每次都按组来
        for(i=0;i<gap;i++)
        {
            for(j=i+gap;j<n;j+=gap)
            {
                if(a[j]<a[j-gap])
                {
                    int temp = a[j];
                    int k = j-gap;
                    while(k>=0&&a[k]>temp)
                    {
                        a[k+gap]=a[k];
                        k-=gap;
                    }
                    a[k+gap] = temp;
                }
            }
        }
    }
}


/**
这里是对希尔排序的精简实现

**/




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
    ShellSort_1(arrayInt,num);
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
