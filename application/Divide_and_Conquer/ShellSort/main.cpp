#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
ϣ������˼·

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
void ShellSort(T a[],int n)
{


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
    ShellSort(arrayInt,num);
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
