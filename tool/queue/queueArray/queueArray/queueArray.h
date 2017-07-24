#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
template<class T>
//����queue��������Բ������õĴ���ʽ
//location (i ) = (location (1) + i -1) % M a x S i z e
//rearʼ��ָ���β
class QueueArray {
// FIFO ����
public:
    QueueArray(int MaxQueueSize = 10);
    ~QueueArray() {delete [] queue;}
    bool IsEmpty() const {return front == rear;}
    bool IsFull() const {return (
    ((rear + 1) % MaxSize == front) ? 1 : 0);}
    T First() const; //���ض���Ԫ��
    T Last() const; // ���ض�βԪ��
    QueueArray<T>& Add(const T& x);
    QueueArray<T>& Delete(T& x);
private:
    //�����front��rear������ֵ����
    int front; //���һ��Ԫ���ڷ�ʱ�뷽�������һ��λ��
    int rear; // ָ�����һ��Ԫ��
    int MaxSize; // ��������Ĵ�С
    T *queue; // ����
} ;
#include"queueArray.cpp"
#endif // QUEUE_ARRAY_H
