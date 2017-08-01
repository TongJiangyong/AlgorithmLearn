#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
��������
����˼·Ϊ��
ֱ�Ӳ�������(Insertion Sort)�Ļ���˼���ǣ�ÿ�ν�һ��������ļ�¼�������
���ִ�С���뵽ǰ���Ѿ��ź�����������е��ʵ�λ�ã� ֱ��ȫ����¼�������
Ϊֹ��
������Ϊ a[0��n-1]��
1. ��ʼʱ��a[0]�Գ� 1 ����������������Ϊ a[1..n-1]���� i=1
2. �� a[i]���뵱ǰ�������� a[0��i-1]���γ� a[0��i]���������䡣
3. i++���ظ��ڶ���ֱ�� i==n-1��������ɡ�

�����������˼��Ϊ��
��ԭ�����Ϊ�������֣���һ������ֻ��һ��Ԫ�أ�ÿ�ζ����������һ��Ԫ�ؽ��е�������.....
���㷨��ʵ��Ҳ��Ϊ��������
1������ԭ�����飬�������±�Ϊ1Ϊ��ʼ�����������α�Ϊ1�ĵط���ʼ�������ҵ�ÿһ������������Բ����λ��
2�������ʼ���飬���ƶ����������λ��
**/






//�Լ���������д�Ĵ��뿴��ȥ����
template<class T>
void InsertSort_1(T *a,int n)
{
    int length = 1;
    for(int i=1;i<n;i++)
    {
        int j=0;
        for(;j<length;j++)
        {
            if(a[i]<a[j])
                break;
        }
        T temp = a[i];
        for(int k=length;k>j;k--)
        {
            a[k]=a[k-1];
        }
        a[j]=temp;
        length++;
    }
}
//ѧϰ���˵Ĵ��룬�������������ƶ�����ͬһ�������Ϊ.....
//ÿ��a[i]�Ⱥ�ǰ��һ������a[i-1]�Ƚϣ����a[i] > a[i-1]˵��a[0��i]Ҳ������ģ�
//����������������j=i-1,temp=a[i]��Ȼ��һ�߽�����a[j]����ƶ�һ����ǰ������
//��������a[j]<a[i]ʱֹͣ����temp�ŵ�a[j + 1]��
//����ǴӺ���ǰ�ƶ����������ƶ���ʵ���Է���һ��......
template<class T>
void InsertSort_2(T *a,int n)
{
    int i, j;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            int temp = a[i];
            for(j=(i-1);j>=0&&a[j]>temp;j--)
                a[j+1] = a[j];
            a[j+1] = temp;
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
    InsertSort_2(arrayInt,num);
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
