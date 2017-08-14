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
问：如何进行堆排序？？？

答：根据堆的性质，使用基本的堆操作方法.....
即：最好的方法是定义一系列堆的封装函数，然后用这些封装的函数，来操作堆.....
上浮 shift_up；
下沉 shift_down
插入 push
弹出 pop
取顶 top
堆排序 heap_sort



堆排序的应用场景：

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

//首先第一步需要构造初始化堆栈，构造的过程，即是一个堆栈插入的过程

template<class T>
void HeapAdjust(T[] a,int parent,int n)
{
    T temp = a[parent]  //temp保存父节点
    int child = 2*parent +1;
    while(child<length)
}



template<class T>
void HeapSort(T a[],int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        Swap(a[i], a[0]);
        MinHeapFixdown(a, 0, i);
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
    HeapSort(arrayInt,num);
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
