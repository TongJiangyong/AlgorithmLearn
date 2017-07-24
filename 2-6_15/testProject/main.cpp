#include<stdio.h>
#include <iostream>
#include<vector>
#define LOCAL
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
using namespace std;


//工具函数
template <class T>
inline void Swap(T& a, T& b)
{// 交换a和b
    T temp = a; a = b; b = temp;
}
//工具函数
template <class T>
int Max(T a[], int n)
{
    int temp = a[0];
    int returnNum = 0;
    for(int i=0;i<n;i++){
        if(a[i]>temp){
            temp = a[i];
            returnNum = i;
        }
    }
    return returnNum;
}
template<class T>
//2-5
//input a=[4, 3, 9, 3, 7]
//output r =[2, 0, 4, 1, 3]
void rankArray(T a[],int r[],int n)
{
    for(int i=0;i<n;i++){
        for(int j=(i+1);j<n;j++){
            if(a[i]>a[j]){
                r[i]++;
            }else{
                r[j]++;
            }
        }

    }
}

template<class T>
//2-6
//根据2-5进行重新排序
void reRank(T a[],int n,int r[]){
    T *temp = new T[n];
    for(int i=0;i<n;i++){
        temp[r[i]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i] = temp[i];
    }
    delete []temp;

}

//2-11
//第二种reRank的方法 原地重排法
//原理是根据交换的方式，直到每一个位置都换好了，才向下走
template<class T>
void reRank_2(T a[],int n,int r[]){
    for(int i=0;i<n;i++){
        while(r[i]!=i){
            int t = r[i];
            Swap(a[i],a[t]);
            Swap(r[i],r[t]);
        }
    }
}




//2-7
//选择排序法
//基本思路：
//首先找出最大的元素，把它移动到 a [ n-1 ]，然后在余下的 n-1个元素中寻找最大的元素并把它移动到a [ n-2 ]，如此进行下去，这种排序方法为选择排序
template <class T>
void selectionSort (T a[], int n)
{
    for (int size = n; size > 1; size--)
    {
        int j= Max(a, size);
        Swap(a[j],a[size-1]);
    }
}

//选择排序法2
//基本思路：
//程序2 - 7中选择排序函数的一个缺点是：即使元素已经按序排列，程序仍然继续运行。
//例如，即使在第二次循环过后数组元素可能已经按序排列， f o r循环仍需要执行n - 1次。
//为了终止不必要的循环，在查找最大元素期间，可以顺便检查数组是否已按序排列。程序2 - 1 2给出了一个按照这种思想实现的选择排序函数。
//但是这种方法，改进效果不大
template <class T>
void selectionSort_2(T a[], int n)
{
    bool sorted = false;
    for (int size = n; !sorted && (size > 1); size--) {
        int pos = 0;
        sorted = true;
        // 找最大元素
        for (int i = 1; i < size; i++)
            if (a[pos] <= a[i]) pos = i;
            else sorted = false; // 未按序排列
        Swap(a[pos], a[size - 1 ] ) ;
        }
}



//2-8冒泡排序法
//冒泡策略”把最大元素移到右部。在冒泡过程中，对相邻的元素进行比较，如果左边的元素大于右边的元素，则交换这两个元素
template<class T>
void bubbleOrde(T a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            if(a[i]>a[j]){
                Swap(a[i],a[j]);
            }
        }
    }
}

//2-13 带有终止的冒泡排序
//即，如果在一次冒泡中，没有发生交换现象，则表示排序已经完成，有一定的效率提高

template<class T>
void bubbleOrde_2(T a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            if(a[i]>a[j]){
                Swap(a[i],a[j]);
                break;
            }
        }
    }
}


//插入排序法
//基本思路：
//因为只有一个元素的数组是一个
//有序数组，所以可以从仅包含欲排序的 n 个元素的第一个元素的数组开始。通过把第二个元素
//插入到这个单元数组中，可以得到一个大小为 2的有序数组。插入第三个元素可以得到一个大
//小为3的有序数组。按照这种方法继续进行下去，最终将得到一个大小为 n的有序数组，这种排
//序方式为插入排序（ insertion sort）
template<class T>
void Insert(T a[], int n, const T& x)
{// 向有序数组 a [ 0 : n - 1 ]中插入元素x
    int i;
    //注意，这里的一个for循环，为什么从后向前，就是为了进行移位的操作，所以按照插入排序的性质，如果插入的数比较小，
    //则向后移位，然后在循环结束后赋予位置新的数据即可
    cout <<"test_2:"<<x<<endl;
    for (i = n-1; i >= 0 && x < a[i]; i--)
        a[i+1] = a[i];
    cout <<"test_3:"<<x<<endl;
    a[i+1] = x;
}
template<class T>
void InsertionSort(T a[], int n)
{// 对 a [ 0 : n-1 ]进行排序
    for (int i = 1; i < n; i++) {
        T t = a[i];
        cout <<"test_1:"<<t<<endl;
        //Insert(a, i, a[i]);
//注意在这里，只能传递t，不能传递a[i]的原因，因为这里的Insert传递的是引用，所以如果引用在
//函数内部运行改变的话，会改变整个函数的取向
//即，这里值得注意的是，如果函数传递的是引用，一定要注意，函数这个引用所代表的内存
//在函数运行过程中的变化一定要注意！！！！
        Insert(a, i, t);
    }
}



//这里给出了添加动态数组的基本方法
//http://wenda.tianya.cn/question/05cf48b56c85c114
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
    int *output  = new int[n];
     for(int m=0;m<n;m++){
        output[m] =0;
    }
    //rankArray(input,output,n);
    //reRank(input,n,output);
    InsertionSort(input,n);
    for(int k=0;k<n;k++){
        cout<<input[k]<<" ";
    }
    delete [] input;
    delete [] output;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
