#include<stdio.h>
#include <iostream>
#include<vector>
#define LOCAL
using namespace std;

template <class T>
T Horner(T a[],int n,const T &x)
{
    T y=1, value= a [ 0 ] ;
    for ( int i = 1; i <= n; i++)
    {
        y *= x;
        value += y * a [ i ] ;
    }
    return value;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n=0;
    //这里是输出数组的基本方法
    scanf("%d",&n);
    int *input = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d", &input[i]);
    }

    //while(scanf("%d", &input[i]) != EOF)
    //{
    //    i++;
    //}
    //求最大值
    //求任意数的位置
    delete [] input;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
