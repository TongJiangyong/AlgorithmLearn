#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
/**
˳����ҷ���
˳������ʺ��ڴ洢�ṹΪ˳��洢�����Ӵ洢�����Ա�


**/

template <class T>

int getArrayLen(T& array)

{
    //������Ϊ������������ʱ������ָ����������飬���ݵ���������׵�ַ
    //������ﲻ�����ã�����Զ����1��һ��Ҫע�⼴��....
    return (sizeof(array) / sizeof(array[0]));
}
//��C/C++�У�������ݵ���ָ�룬��һ���޷��������鳤�ȣ�strlen������.....���ԭ����....
int SequenceSearch(int a[],int value,int n)
{
    int i;
    for(i=0; i<n; i++)
        if(a[i]==value)
            return i;
    return -1;
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
cout<<SequenceSearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
