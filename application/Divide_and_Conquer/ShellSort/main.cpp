#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
ϣ������˼·�������������
����˼���ǣ��Ƚ���������Ԫ�����зָ�����ɸ������У������ĳ��
����������Ԫ����ɵģ��ֱ����ֱ�Ӳ�������Ȼ���������������ٽ�������
�����������е�Ԫ�ػ������������㹻С��ʱ���ٶ�ȫ��Ԫ�ؽ���һ��ֱ�Ӳ�
������
�������е�Ԫ�ػ������������£�ʹ��ֱ�Ӳ�������Ƚϸ�Ч

����ϣ��������Կ�����ֱ�Ӳ�������ĸĽ�������
�����˲�������������ص㣺
1��������Ԫ�ؽ��ٵ�ʱ������Ч�ʽϸ�
2�������ڴ���������ɵ����������Ч�ʽϸ�
http://www.cnblogs.com/jingmoxukong/p/4303279.html
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

/**
�����Ƕ�ϣ����������㷨��ʵ��.....
1��ÿ�ν��������룬��������ͬһ���У����������

**/
template<class T>
void ShellSort_1(T a[],int n)
{
    int i,j=0,gap;
    //gap ��ʼΪn��ÿ�μ��룬����gap/2ÿ�ζ�����ܴ���1
    for(gap = n/2;gap>0;gap/=2)
    {
        //�����ÿ�ζ�������
        for(i=0;i<gap;i++)
        {
            for(j=i+gap;j<n;j+=gap)
            {
                if(a[j]<a[j-gap])
                {
                    int temp = a[j];
                    int k = j-gap;
                    while(k>=0&&a[k]>temp)
                    {
                        a[k+gap]=a[k];
                        k-=gap;
                    }
                    a[k+gap] = temp;
                }
            }
        }
    }
}


/**
�����Ƕ�ϣ������ľ���ʵ��

**/




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
    ShellSort_1(arrayInt,num);
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
