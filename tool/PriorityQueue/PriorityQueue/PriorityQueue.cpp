#ifndef PRIORITY_QUEUE_CPP
#define PRIORITY_QUEUE_CPP

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{// ���캯��
    MaxSize = MaxHeapSize;
    heap = new T[MaxSize+1];
    CurrentSize = 0;
}
/**

**/
template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x)
{
    // �� x ���뵽������
    if (CurrentSize == MaxSize)
        throw NoMem(); // û���㹻�ռ�
    //Ϊ xѰ��Ӧ����λ��
    // i ���µ�Ҷ�ڵ㿪ʼ��������������
    int i = ++CurrentSize;
    while (i != 1 && x > heap[i/2]) {
        // ���ܹ��� x ���� h e a p [ i ]
        heap[i] = heap[i/2]; // ��Ԫ������
        i /= 2; // ���򸸽ڵ�
    }
    heap[i] = x;
    return *this;
}
#endif // PRIORITY_QUEUE_H
