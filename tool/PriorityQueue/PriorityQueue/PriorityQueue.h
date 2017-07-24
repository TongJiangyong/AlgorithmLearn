#ifndef PRIORITY_QUEUE_h
#define PRIORITY_QUEUE_h
#include <stdio.h>
#include "except.h"
/**
������������M a x P r i o r i t y Q u e u e{
ʵ��
���޵�Ԫ�ؼ��ϣ�ÿ��Ԫ�ض���һ������Ȩ
����
Create ( )������һ���յ����ȶ���
Size ( )�����ض����е�Ԫ����Ŀ
Max ( )�����ؾ����������Ȩ��Ԫ��
I n s e rt (x)����x �������
DeleteMax (x)���Ӷ�����ɾ�������������Ȩ��Ԫ�أ�������Ԫ�ط����� x
}

����������ͣ���������Ȩ���������⣬���п��ټ����Ȳ���....

�������壺
//��ȫ��������Ҷ�ڵ�ֻ�ܳ��������²�ʹ��²㣬����������һ��Ľ�㶼�����ڸò�����ߵ�����λ�õĶ�����
//���������С���� ] ÿ���ڵ��ֵ������ ��С�ڣ���������ӽڵ㣨����еĻ���ֵ����
//���ѣ���С�ѣ� ] �����С������ȫ��������
//���������ݽṹ��Ϊ��ȫ������������һά������Ч��������.....
����/��С��------���Ϊ�������ȫ������������Ĺ������ڲ���/ɾ���о����õ�....�����ʱ�����㼴��.....��
�������ѵ�����:
������Դ�Ҷ����ֻ�е�һ·��
ɾ�����Բ�����һ���Ӷѵĸ��ڵ㵽Ҷ�ڵ�ĵ�һ·��
http://www.cnblogs.com/tonyluis/p/5700140.html

//��ʼ�����ѵ�ת��Ϊ��
��˳�򽻻�������������������

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
    T *heap; // Ԫ������
} ;


#endif // PRIORITY_QUEUE_H
