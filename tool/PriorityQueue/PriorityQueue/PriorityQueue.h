#ifndef PRIORITY_QUEUE_h
#define PRIORITY_QUEUE_h
#include <stdio.h>
#include "except.h"
/**
抽象数据类型M a x P r i o r i t y Q u e u e{
实例
有限的元素集合，每个元素都有一个优先权
操作
Create ( )：创建一个空的优先队列
Size ( )：返回队列中的元素数目
Max ( )：返回具有最大优先权的元素
I n s e rt (x)：将x 插入队列
DeleteMax (x)：从队列中删除具有最大优先权的元素，并将该元素返回至 x
}

解决问题类型，对有优先权的排序问题，进行快速检索等操作....

基本定义：
//完全二叉树：叶节点只能出现在最下层和次下层，并且最下面一层的结点都集中在该层最左边的若干位置的二叉树
//最大树（最小树） ] 每个节点的值都大于 （小于）或等于其子节点（如果有的话）值的树
//最大堆（最小堆） ] 最大（最小）的完全二叉树。
//堆这种数据结构即为完全二叉树，可用一维数组有效的描述堆.....
最大堆/最小堆------理解为有序的完全二叉树（有序的过程是在插入/删除中就做好的....所需的时间另算即可.....）
按照最大堆的特性:
插入策略从叶到根只有单一路径
删除策略产生了一条从堆的根节点到叶节点的单一路径
http://www.cnblogs.com/tonyluis/p/5700140.html

//初始化最大堆的转换为：
按顺序交换，并遍历子树的最大堆

**/

template<class T>
class MaxHeap {
public:
    MaxHeap(int MaxHeapSize = 10);
    ~MaxHeap() {
        delete [] heap;
    }
    int Size() const {
        return CurrentSize;
    }
    T Max() {
        if (CurrentSize == 0)
            throw OutOfBounds();
        return heap[1];
    }
    MaxHeap<T>& Insert(const T& x);
    MaxHeap<T>& DeleteMax(T& x);

private:
    int CurrentSize, MaxSize;
    T *heap; // 元素数组
} ;


#endif // PRIORITY_QUEUE_H
