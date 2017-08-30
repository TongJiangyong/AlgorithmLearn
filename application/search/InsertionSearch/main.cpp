#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
/**
��ֵ���ҷ�
��ֵ����=���ʺ��ڴ洢�ṹΪ˳��洢�����Ӵ洢�����Ա�
��һ�ֶԶ��ַ��ĸĽ�...

����������֮һ�Ĳ�ֵ���Ľ�Ϊ,��ֵ��صĲ�ֵ
����mid=(low+high)/2, ��mid=low+1/2*(high-low);
����ͨ����ȣ����ǿ��Խ����ҵĵ�Ľ�Ϊ���£�
����mid=low+(key-a[low])/(a[high]-a[low])*(high-low)��
�����������λ��ֵ�ı�ֵ��ϵ....

**/

template <class T>

int getArrayLen(T& array)

{
    //������Ϊ������������ʱ������ָ����������飬���ݵ���������׵�ַ
    //������ﲻ�����ã�����Զ����1��һ��Ҫע�⼴��....
    return (sizeof(array) / sizeof(array[0]));
}
//��C/C++�У�������ݵ���ָ�룬��һ���޷��������鳤�ȣ�strlen������.....���ԭ����....
//��ֵ����ʹ�õ��ǵݹ�ķ���ʵ��
//����ݹ�ʵ�����ǵ�·�ģ�����������һ·һֱ�ݹ���ȥ��ֱ������.....
int insertionSearch(int a[],int value,int low,int high)
{
    //�������쳣��ֹ����
    if(low>=high){
        return -1;
    }
    int mid =low+(value-a[low])/(a[high]-a[low])*(high-low);
    //������������ֹ����
    if(a[mid]==value)
    {
        return mid;
    }
    else if(a[mid]>value)
    {
        return insertionSearch(a,value,low,mid-1);

    }
    else if(a[mid]<value)
    {
        return insertionSearch(a,value,mid+1,high);
    }

}

int InsertionSearch(int a[],int value,int n)
{
    int high = n-1;
    int low =0;
    return insertionSearch(a,value,low,high);
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
cout<<InsertionSearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
