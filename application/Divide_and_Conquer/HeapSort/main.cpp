#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
堆排序思路
基本概念：
二叉堆的定义
二叉堆是完全二叉树或者是近似完全二叉树。
二叉堆满足二个特性：
1．父结点的键值总是大于或等于（小于或等于）任何一个子节点的键值。
2．每个结点的左子树和右子树都是一个二叉堆（都是最大堆或最小堆）。
当父结点的键值总是大于或等于任何一个子节点的键值时为最大堆。当父结点的键值总是小于或等于任何一个子节点的键值时为最小堆。下图展示一个最小堆：
这里要明白从堆的逻辑结构----->存储结构的转变.....

堆的存储
一般都用数组来表示堆，下标为i结点的父结点下标就为(i – 1) / 2。它的左右子结点下标分别为2 * i + 1和2 * i + 2。如第0个结点左右子结点下标分别为1和2。
如下图的两个堆：

        1                        11
      /   \                      /  \
     2     3                   9     10
    /  \  /  \                / \   /  \
   4   5  6  7               5  6  7   8
  / \  / \                  /\  /\
 8  9 10 11               1  2 3  4

将这两个堆保存在以1开始的数组中：

位置:  1  2  3  4  5  6  7  8  9 10 11
左图:  1  2  3  4  5  6  7  8  9 10 11
右图: 11  9 10  5  6  7  8  1  2  3  4

即，其基本规律为：
设当前元素在数组中以R[i]表示，那么，

(1) 它的左孩子结点是：R[2*i+1];
(2) 它的右孩子结点是：R[2*i+2];
(3) 它的父结点是：R[(i-1)/2];
(4) R[i] <= R[2*i+1] 且 R[i] <= R[2i+2]。



从堆的存储特性来看：
对于一个很大的堆，这种存储是低效的。因为节点的子节点很可能在另外一个内存页中
比如上面的，5的子节点10,11实际上离5很远，B-heap是一种效率更高的存储方式，把每个子树放到同一内存页。

堆排序的基本操作包括两个：
（1）根据初始数组去构造初始堆（构建一个完全二叉树，保证所有的父结点都比它的孩子结点数值大）。

（2）每次交换第一个和最后一个元素，输出最后一个元素（最大值），然后把剩下元素重新调整为大根堆。

http://www.cnblogs.com/jingmoxukong/p/4303826.html
http://blog.csdn.net/morewindows/article/details/6709644
http://blog.csdn.net/moxiaomomo/article/details/6331386
https://segmentfault.com/a/1190000002466215
http://blog.csdn.net/jx232515/article/details/51549323
问：如何进行堆排序？？？

答：根据堆的性质，使用基本的堆操作方法.....
即：最好的方法是定义一系列堆的封装函数，然后用这些封装的函数，来操作堆.....
上浮 shift_up；
下沉 shift_down
插入 push
弹出 pop
取顶 top
堆排序 heap_sort

堆排序的基本思路：
堆排序算法的基本思想是，将数组A创建为一个最大堆，然后交换堆的根(最大元素)和最后一个叶节点x，
将x从堆中去掉形成新的堆A1，然后重复以上动作，直到堆中只有一个节点。

A 构建一个根据初始排序的大根堆，这个堆是初始无序区,即，将原数组排序成一个大根堆的形式
    大根堆并不是最后的结果，还需要得到最后的输出队列......
B 对这个大根堆进行排序操作...，输出最后的数组

堆排序的应用场景和实际意义：

堆排序的时间复杂度是O(nlgN)，与快速排序达到相同的时间复杂度。但是在实际应用中，我们往往采用快速排序而不是堆排序。这是因为快速排序的一个好的实现，
往往比堆排序具有更好的表现。堆排序的主要用途，是在形成和处理优先级队列方面。另外，如果计算要求是类优先级队列
（比如，只要返回最大或者最小元素，只有有限的插入要求等），堆同样是很适合的数据结构。

我们要排序的话，直接使用快排即可，时间更快，用堆排还需要O(2*n)的空间。这也是为什么我说堆的操作

时间复杂度在O(1)~O(logn)。

讲完到这里，堆也基本介绍完了，那么它有什么用呢？？

举个粒子，比如当我们每次都要取某一些元素的最小值，而取出来操作后要再放回去，重复做这样的事情。
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
void PrintArray(T a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

//首先第一步需要构造初始化堆栈，构造的过程，即是一个堆栈插入的过程
template<class T>
void HeapAdjust(T a[],int parent,int n)
{
    T temp = a[parent];  //temp保存父节点
    int child = 2*parent +1; //获得左节点

    while(child<n)
    {
        //如果有右孩子节点，并且右孩子节点值大于左孩子，则选取右孩子
        if(child+1<n && a[child]<a[child+1])
        {
            child++;
        }
        //如果父节点的值已经大于孩子节点的值，则直接结束
        if(temp >=a[child])  //**在这里多了一个分号，导致调试了很久**
            break;
        //把孩子节点的值赋给父节点
        a[parent]=a[child];
        //选取孩子节点的左节点，继续向下筛选
        parent = child;
        child = 2*child+1;
    }

    a[parent] = temp;
}



template<class T>
void HeapSort(T a[],int n)
{
    //循环建立初始的堆
    /**
    建立最大堆：将A[1,n]数组转换为最大堆。因为最大堆为完全二叉树结构，因此A[n/2+1],……,A[n]是最大堆的叶子节点。每个叶子节点本身就是一个最大堆，
    所以我们就要从A[n/2]~A[1]逐步维护这个最底层的最大堆（维护）。
    //这个方法是通过叶子节点(度为0的节点)来维护整个堆的过程，即这里构建堆使用了叶子节点的特性(即，叶子节点不需要调整堆的排序过程....白话算法将得比较清楚.....).....
    **/
    for(int i = n/2-1;i>=0;i--)
    {
       HeapAdjust(a,i,n);
    }
    printf("初始堆：");
    PrintArray(a,n);
    /**
    堆排序：先建立一个最大堆。然后将最大堆的A[1]与A[n]交换，然后从堆中去掉这个节点n，通过减少A.heap_size的值来实现。剩余的节点中，
    新的根节点可能违背了最大堆的性质，因此需要调用MAX_HEAPWEIHU(A，1)来维护最大堆。
    **/
    //进行n-1次循环，完成排序
    for(int i = n-1;i>0;i--)
    {
        T temp = a[i];
        a[i]=a[0];
        a[0]=temp;
        //注意这里维护的过程实际上将数组长度每次都减去了一点
        HeapAdjust(a,0,i);
        printf("第%d趟排序完成：",(n-i));
        PrintArray(a,n);
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
cout<<"排序前为"<<endl;
PrintArray(arrayInt,num);

HeapSort(arrayInt,num);
//TODO add algorithm
//QuickSort(arrayInt,num);

cout<<"排序完成结果为"<<endl;
for(int j=0;j<num;j++){
    cout<<arrayInt[j]<<" ";
}

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
