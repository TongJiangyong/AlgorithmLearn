#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
希尔排序思路

**/
//相当于指针移动
//相等的情况下，指针不会动.....
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
