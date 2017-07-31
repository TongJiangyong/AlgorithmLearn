#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
快速排序思路
 /使用快速排序方法对a[ 0 :n- 1 ]排序
从a[ 0 :n- 1 ]中选择一个元素作为m i d d l e，该元素为支点
把余下的元素分割为两段left 和r i g h t，使得l e f t中的元素都小于等于支点，而right 中的元素都大于等于支点
递归地使用快速排序方法对left 进行排序
递归地使用快速排序方法对right 进行排序
所得结果为l e f t + m i d d l e + r i g h t

分治法的自己理解为：
1、选定一个中值元素
2、以这个中值元素为依据，然后从左右两边进行互换的排序操作（包括中值元素本身）
3、直到一轮循环结束
4、分治进入其他循环
**/

/**
快速排序的特点是，每次一次循环，实际上都移动了下标的位置
下一轮循环，即处理的是数组的一部分，数组整体并没有变化
**/

//可用于中值快速排序的中值获取函数
//即选择出中值.....
void GetMiddle()
{

}

//交换数据
template<class T>
void Swap(T &a, T&b){
    T temp = a;
    a = b;
    b = temp;
}


//第一种理解方法
template <class T>
void quickSort(T a[],int left,int right)
{
    //选定中值
    if(left>=right)
        return;
    int first = left;
    int last = right;
    T middle = a[first];
    //将左右两边的元素替换
    //一般一轮循环会出现first == last的情况
    while(first<last){
        //测试结果显示好像必须要从右边的元素开始找数据
        //注意这个等于符号不能掉，不然不能排序等号的.....
        //这个过程可以等同于冒泡排序的过程.....仔细理解下就好
        while(first<last && a[last]>=middle)
        {
            last--;
        }
        //如果找到数据，则进行交互
        Swap(a[last],a[first]);
        //从左边的元素开始找
        while(first<last&&a[first]<=middle)
        {
            first++;
        }
        //如果找到数据则交互
        Swap(a[last],a[first]);
    }
    //设置分治的参数
    a[last] = middle;
    //进入分治的过程
    //左边
    quickSort(a,left,last-1);
    //右边
    quickSort(a,last+1,right);
}

//这一篇关于坑的理解也可以做体会，将交换换成了坑
//http://blog.csdn.net/morewindows/article/details/6684558
//仔细想想当i==j的情况
//实际上交换数据的时候，是左端和右端在交换，first和last只是移动的指针，所以出现i = j的时候，并不影响
//仔细想想奇数序列和偶数序列不同的情况.....
//同里，奇数序列和偶数序列并不影响
//仔细想想一轮排序完成的情况
//当一轮循环完成后，会进入 first == last 的情况，然后可能出现first = last在末尾/首部 /末尾一格等情况
//就会出现跳出递归的判断即可.....
//仔细想想换值的情况
//并不一定要换值，可以是换坑的理解.....可以理解为没必要换值......

//这个方法是为了让算法更有灵活度,传入数组长度
template<class T>
void QuickSort(T *a,int n)
{
    //对a[0:n-1]进行快速排序
    //注意数组长度和排位性质不同
    quickSort(a,0,n-1);
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
QuickSort(arrayInt,num);

for(int j=0;j<num;j++){
    cout<<arrayInt[j]<<" ";
}

#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
