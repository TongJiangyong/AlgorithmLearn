#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
const int max_size=20;//斐波那契数组的长度
/**
斐波拉契查找法：
斐波那契查找算法对比二分法的特点是：
不需使用位移，使用加减，就能实现查找点的计算
同样也是对有序队列进行处理的方法
核心思想是使用Fibonacci数列来进行分割有序表
即，每一个数列数都等于前两个数的和
即，利用这个特性，不断的对有序表进行分割....
这篇文章讲的比较好....
http://blog.csdn.net/zsw12013/article/details/50003505

**/

template <class T>

int getArrayLen(T& array)

{
    //数组作为参数传给函数时传的是指针而不是数组，传递的是数组的首地址
    //如果这里不是引用，则永远都是1，一定要注意即可....
    return (sizeof(array) / sizeof(array[0]));
}
//在C/C++中，如果传递到是指针，则一般无法计算数组长度，strlen是例外.....清楚原理即可....


/*构造一个斐波那契数组*/
void Fibonacci(int * F)
{
    F[0]=0;
    F[1]=1;
    for(int i=2;i<max_size;++i)
        F[i]=F[i-1]+F[i-2];
}

/*定义斐波那契查找法*/
int FibonacciSearch(int *a,int key,int n)  //a为要查找的数组,n为要查找的数组长度,key为要查找的关键字
{
  int low=0;
  int high=n-1;

  int F[max_size];
  //构造斐波那契数列
  Fibonacci(F);//构造一个斐波那契数组F

  int k=0;

  while(n>F[k]-1)//计算n位于斐波那契数列的位置
      ++k;

//构建一个新的，准备用于查找的斐波那契数组
  int  * temp;//将数组a扩展到F[k]-1的长度
  temp=new int [F[k]-1];
  memcpy(temp,a,n*sizeof(int));

  //补全斐波那契数列空余的位置，这是由于斐波那契的性质得到的
  for(int i=n;i<F[k]-1;++i)
     temp[i]=a[n-1];

    //开始利用斐波那契进行查找，mid的求发，即和构建的斐波那契数组相关
  while(low<=high)
  {
    int mid=low+F[k-1]-1;
    if(key<temp[mid])
    {
      high=mid-1;
      k-=1;
    }
    else if(key>temp[mid])
    {
     low=mid+1;
     k-=2;
    }
    else
    {
       if(mid<n)
           return mid; //若相等则说明mid即为查找到的位置
       else
           return n-1; //若mid>=n则说明是扩展的数值,返回n-1
    }
  }
  //最后注意删除temp
  delete [] temp;
  return -1;
}



int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
int num;
cin>>num;
//注意这里可以知道，动态数组的长度，没法直接使用len的方式求得
//因为在C语言中，指针和数组是不同的....这一点还是要记住的.....
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
cout<<FibonacciSearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
