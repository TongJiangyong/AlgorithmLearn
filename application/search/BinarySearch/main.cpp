#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
/**
���ַ�����/�۰����
���ڲ������Ա�ȽϺ�.....
�������Ա�Ҫ�ǵ����ıȽϺ�.....

�۰���ҵ�ǰ����������Ҫ�����˳��洢�����ھ�̬���ұ�һ��������ٱ仯���۰�����ܵõ������Ч�ʡ�
��������ҪƵ��ִ�в����ɾ�����������ݼ���˵��ά�����������������С�Ĺ��������ǾͲ�����ʹ��

**/

template <class T>

int getArrayLen(T& array)

{
    //������Ϊ������������ʱ������ָ����������飬���ݵ���������׵�ַ
    //������ﲻ�����ã�����Զ����1��һ��Ҫע�⼴��....
    return (sizeof(array) / sizeof(array[0]));
}
//��C/C++�У�������ݵ���ָ�룬��һ���޷��������鳤�ȣ�strlen������.....���ԭ����....
int BinarySearch_1(int a[],int value,int n)
{
    int low ,high,mid;
    low = 0;
    high =n-1;
    //����low��high�ڲ��ϱ仯
    while(low<=high)
    {
        //���ַ���Ҫ�ȼ���middle��ֵ
        mid=(low+high)/2;
        if(a[mid]==value)
        {
             return mid;
        }
        else if(a[mid]>value)
        {
             high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}

//ʹ�õݹ�ʵ�ֶ��ַ�
//�ؼ��Ǽ����low and hight����.....
int BinarySearch_2(int a[], int value, int low, int high)
{
    int mid = low+(high-low)/2;
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return BinarySearch2(a, value, low, mid-1);
    if(a[mid]<value)
        return BinarySearch2(a, value, mid+1, high);
}


int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int num;
cin>>num;
//ע���������֪������̬����ĳ��ȣ�û��ֱ��ʹ��len�ķ�ʽ���
//��Ϊ��C�����У�ָ��������ǲ�ͬ��....��һ�㻹��Ҫ��ס��.....
int *arrayInt = new int[num];
int test[] ={1,2,6,8};
for(int i=0;i<num;i++)
{
    cin>>arrayInt[i];
    cout<<arrayInt[i]<<" ";
}
cout<<endl;
int searchNum;
cin>>searchNum;
cout<<BinarySearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
