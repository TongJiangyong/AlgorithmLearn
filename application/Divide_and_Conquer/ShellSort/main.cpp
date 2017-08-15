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
1��ÿ�ν��������룬��������ͬһ���У����������,��������ÿ�ζ��𽥱�С��ÿ���е�Ԫ�ر�࣬�������������ף�������grpҲΪ��ĸ���
3����ÿ�鳤�ȱ�Ϊ1������������в���������....
**/
template<class T>
void ShellSort_1(T a[],int n)
{
    int i,j=0,gap;
    //gap ��ʼΪn��ÿ�μ��룬����gap/2ÿ�ζ�����ܴ���1
    for(gap = n/2;gap>0;gap/=2)
    {
        //�����ÿ�ζ��������������Ǳ���ÿ����
        for(i=0;i<gap;i++)
        {
            //��ÿһ���е����ݽ���ֱ�Ӳ������� ����ϣ������ı���ֱ�Ӳ������������....
            for(j=i+gap;j<n;j+=gap)   //����ʵ����ʹ���ˣ���һ��������з���󣬱���ÿ�����������ݵı�׼����......
            {
                if(a[j]<a[j-gap]) //���ÿһ�鷢��һ�������Ԫ��С��ǰ���Ԫ��
                {
                    T temp = a[j];  //���������Ԫ��
                    int k = j-gap;    //����ǰ��Ԫ�ص�λ��
                    while(k>=0&&a[k]>temp) //��ǰ�����е�Ԫ�ؽ���ƽ��  �������Ļ���ϣ�������൱����4��ѭ��
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


//�������Լ�����д��ϣ�������㷨
template<class T>
void ShellSort_2(T a[],int n)
{
    int gap,i,j,k;
    T temp;
    for(gap = n/2;gap > 0;gap = gap/2)//��ÿһ��ѭ�����з���
    {
        //����ÿ����
        for(i=0;i<gap;i++)
        {
            //ֱ�Ӳ������򣬴����Ϊ1��ʼ��������0
            for(j=i+gap;j<n;j=j+gap) //��ÿ�����ڽ���ֱ������,�����������㷨��ʵ�֣�ֻ����֮ǰ�����㷨�ļ��Ϊ1������ļ��Ϊgap����.....��shell�����˼�뼴ʹ���
            {
                if(a[j]<a[j-gap])
                {
                    temp = a[j];
                    //�Բ���ǰ����������.....
                    for(k=j-gap;k>=0&&a[k]>temp;k=k-gap)
                        a[k+gap] = a[k];
                    a[k+gap] = temp;
                }

            }
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
    ShellSort_2(arrayInt,num);
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
