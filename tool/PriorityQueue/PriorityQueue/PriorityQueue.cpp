#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{// 构造函数
    MaxSize = MaxHeapSize;
    heap = new T[MaxSize+1];
    CurrentSize = 0;
}
/**

**/
template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x)
{
    // 把 x 插入到最大堆中
    if (CurrentSize == MaxSize)
        throw NoMem(); // 没有足够空间
    //为 x寻找应插入位置
    // i 从新的叶节点开始，并沿着树上升
    int i = ++CurrentSize;
    while (i != 1 && x > heap[i/2]) {
        // 不能够把 x 放入 h e a p [ i ]
        heap[i] = heap[i/2]; // 将元素下移
        i /= 2; // 移向父节点
    }
    heap[i] = x;
    return *this;
}
#endif // PRIORITY_QUEUE_H
