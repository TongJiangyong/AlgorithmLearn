#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**

ð�������˼·��
��ÿ������ÿһ��ѭ����������������������ͨ�������Աȣ�ð��ѡ������
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

//��������ֵ�����������ֵ��ȡ����
//��ѡ�����ֵ.....
//��һ��ð�����������ģ�����ͨ�������Աȣ�ÿ�����ѭ������������ͨ�������Ƚ�ð�ݳ���
//https://baike.baidu.com/item/%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F/4602306?fr=aladdin
template<class T>
void BubbleSort_1(T a[],int n)
{
    //����i����С��n����С��n-1����Ϊ���һ���Ϳ��Բ�������.....
    for(int i=0;i<n;i++)
        for(int j=0;j<(n-i-1);j++)
            if(a[j]>a[j+1])
                Swap(a[j],a[j+1]);

}

//��������ֵ�����������ֵ��ȡ����
//��ѡ�����ֵ.....
//��һ��ð����������С�ģ�ͨ�������Աȣ�ÿ�����ѭ��������С���г���
template<class T>
void BubbleSort_2(T a[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j])
                Swap(a[i],a[j]);
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
    BubbleSort_1(arrayInt,num);
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
