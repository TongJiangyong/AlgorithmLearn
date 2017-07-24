#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
template<class T>
//讨论queue的做法，圆环是最好的处理方式
//location (i ) = (location (1) + i -1) % M a x S i z e
//rear始终指向队尾
class QueueArray {
// FIFO 对象
public:
    QueueArray(int MaxQueueSize = 10);
    ~QueueArray() {delete [] queue;}
    bool IsEmpty() const {return front == rear;}
    bool IsFull() const {return (
    ((rear + 1) % MaxSize == front) ? 1 : 0);}
    T First() const; //返回队首元素
    T Last() const; // 返回队尾元素
    QueueArray<T>& Add(const T& x);
    QueueArray<T>& Delete(T& x);
private:
    //这里的front和rear都是数值而已
    int front; //与第一个元素在反时针方向上相差一个位置
    int rear; // 指向最后一个元素
    int MaxSize; // 队列数组的大小
    T *queue; // 数组
} ;
#include"queueArray.cpp"
#endif // QUEUE_ARRAY_H
