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

return (sizeof(array) / sizeof(array[0]));

}
//˳�����
int SequenceSearch(int a[], int value)
{
    int n;
    n=getArrayLen(a);
    cout<<"len_1 is "<<n<<endl;
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
int *arrayInt = new int[num];
for(int i=0;i<num;i++)
{
    cin>>arrayInt[i];
}
int searchNum;
cin>>searchNum;
int n;
    n=getArrayLen(arrayInt);
    cout<<"len_2 is "<<n<<endl;
cout<<SequenceSearch(arrayInt,searchNum)<<endl;


#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
