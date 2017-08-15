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
1、每次将步长减半，步长即，同一组中，间隔的数据,即，步长每次都逐渐变小，每组中的元素变多，但是排序变得容易，即步长grp也为组的个数
3、当每组长度变为1，即对整体进行插入排序了....
**/
template<class T>
void ShellSort_1(T a[],int n)
{
    int i,j=0,gap;
    //gap 初始为n，每次减半，这里gap/2每次都最后都能大于1
    for(gap = n/2;gap>0;gap/=2)
    {
        //分组后每次都按组来，这里是遍历每个组
        for(i=0;i<gap;i++)
        {
            //对每一组中的数据进行直接插入排序 ，即希尔排序改变了直接插入排序的做法....
            for(j=i+gap;j<n;j+=gap)   //这里实际上使用了，对一个数组进行分组后，遍历每个分组中数据的标准做法......
            {
                if(a[j]<a[j-gap]) //如果每一组发现一个后面的元素小于前面的元素
                {
                    T temp = a[j];  //保留后面的元素
                    int k = j-gap;    //保留前面元素的位置
                    while(k>=0&&a[k]>temp) //将前面所有的元素进行平移  可以理解的话，希尔排序相当于有4层循环
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


//这里是自己理解后，写的希尔排序算法
template<class T>
void ShellSort_2(T a[],int n)
{
    int gap,i,j,k;
    T temp;
    for(gap = n/2;gap > 0;gap = gap/2)//对每一轮循环进行分组
    {
        //遍历每个组
        for(i=0;i<gap;i++)
        {
            //直接插入排序，从序号为1开始，而不是0
            for(j=i+gap;j<n;j=j+gap) //对每个组内进行直接排序,下面是排序算法的实现，只不过之前排序算法的间隔为1，这里的间隔为gap即可.....，shell排序的思想即使如此
            {
                if(a[j]<a[j-gap])
                {
                    temp = a[j];
                    //对插入前，进行排序.....
                    for(k=j-gap;k>=0&&a[k]>temp;k=k-gap)
                        a[k+gap] = a[k];
                    a[k+gap] = temp;
                }

            }
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
    ShellSort_2(arrayInt,num);
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
