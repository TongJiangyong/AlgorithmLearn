#include<iostream>
#include<stdio.h>
using namespace std;
template<class T>
void test(T a[],T b,T *point)
{
    int c =1;
    point = &c;
    b =  5;
    a[0]=2;
}
int main(){
    cout<<"hello world"<<endl;
    int a[2]={4,5};
    int *point =NULL;
    int d =2;
    point = &d;
    cout<<point<<" value:"<<*point <<endl;
    int b =3;
    test(a,b,point);

    printf("a[0]= %d,b = %d\n",a[0],b);
    cout<<point<<" value:"<<*point <<endl;

}
