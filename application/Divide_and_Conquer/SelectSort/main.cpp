#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
ѡ������˼·
ֱ��ѡ�������ֱ�Ӳ����������ƣ��������ݷ�Ϊ��������������������ͬ����
ֱ�Ӳ��������ǽ��������ĵ�һ��Ԫ��ֱ�Ӳ��뵽���������γ�һ���������
������
��ֱ��ѡ�������Ǵ�������ѡһ����С��Ԫ��ֱ�ӷŵ����������ʼ�ĵط���
��ֱ�Ӳ�������ÿ�ζ����������жԱȺ��ٲ���
ѡ������ÿ�ζ���������ѡ����ٲ���


������Ϊ a[0��n-1]��
4. ��ʼʱ������ȫΪ������Ϊ a[0..n-1]���� i=0
5. �������� a[i��n-1]��ѡȡһ����С��Ԫ�أ� ������ a[i]������ ����֮�� a[0��i]
���γ���һ����������
6. i++���ظ��ڶ���ֱ�� i==n-1��������ɡ�
**/
//�൱��ָ���ƶ�
//��ȵ�����£�ָ�벻�ᶯ.....
template<class T>
void Swap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void SelectSort(T a[],int n)
{
    int tempIndex;
    //�������е�����
    for(int i=0;i<n;i++)
    {
        //ÿ��ѡ����һ���������ĵ�һ��Ԫ����Ϊ�ο���
        //�����������д���......
        tempIndex = i;
        //��������˴�һ��������ѡ����СԪ�صĴ���.....
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[tempIndex])
                tempIndex = j;
        }
        //��ѡ�����������������ĵ�һ�������н���
        Swap(a[i],a[tempIndex]);
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
    SelectSort(arrayInt,num);
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
