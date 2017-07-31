#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
�鲢����˼·
�����������������(�൱����������)����ͬһ���������ڵ�λ���ϣ�array[low..m]��array[m + 1..high]��
�Ƚ����Ǻϲ���һ���ֲ����ݴ����� temp (�൱���������)�У����ϲ���ɺ� temp ���ƻ� array[low..high]�У��Ӷ��������
�ھ���ĺϲ������У����� i��j �� p ����ָ�룬���ֵ�ֱ�ָ����������¼������ʼλ�á�
�ϲ�ʱ���αȽ� array[i] �� array[j] �Ĺؼ��֣�ȡ�ؼ��ֽ�С����ϴ󣩵ļ�¼���Ƶ� temp[p] �У�
Ȼ�󽫱����Ƽ�¼��ָ�� i �� j �� 1���Լ�ָ����λ�õ�ָ�� p�� 1���ظ���һ����ֱ�������������������һ����ȫ���������(��������Ϊ��)��
��ʱ����һ�ǿյ���������ʣ���¼���θ��Ƶ� array �м��ɡ�

��Ҫ��Ϊ��
��"�ָ�"��"�ϲ�"

����Ҳ�ܿ����鲢����Ϳ�������ܲ�һ���ĵط���
�鲢�����ǱȽϵ��͵ķ����㷨�����Ƚ���������С����󣬷ֳ�С���⣬���ǵ�ǰ���Ⲣû�н���������û��С����󣬵ݹ������������****
�Կ��������㷨
��Ҳ�з����㷨��˼�룬���Ǻ͹鲢�㷨��������̫���ͣ��ڷ���ǰ��ÿһ��ѭ���������˵�ǰѭ��������飬Ȼ����͸�����ν��С���������****

http://blog.csdn.net/robertcpp/article/details/51540976
http://blog.csdn.net/morewindows/article/details/7961256
**/






//���������ָ��һ��������й鲢�Ĺ���
//�������⽫һ�������Ϊ���Σ�Ȼ��ʹ�ù鲢��˼����й鲢
//ͨ�������α꣬������������������У�����cΪһ���м������
template<class T>
void mergeArray(T *a,int first,int mid,int last,T *c)
{
    int i = first,j=mid+1;
    int k=0;
    while(i<=mid&&j<=last)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
    {
        c[k++]= a[i++];
    }
    while(j<=last)
    {
        c[k++]= a[j++];
    }
    for(i = 0;i<k;i++)
        a[first+i] = c[i];
}

//�鲢������ص�����Ҫ�ȷ��ٺϲ�
//���Ҫ��������Ĺ���
template<class T>
void mergeSort(T *a,int first,int last,T *temp)
{
    if(first<last)
    {
        //�ݹ鵽���գ�ʵ����middle = first = last������
        int middle = (first+last)/2;
        mergeSort(a,first,middle,temp);     //�������Ϊ��������.....
        mergeSort(a,middle+1,last,temp);  //�����������������������.....һ��Ϊһ�룬Ȼ���1������
       //���������в���...��Ҫ�����ȥ�������ֻ���Ȼ��ϲ��Ĺ��̣��ϲ��Ĺ��̣��Ƕ�����a����ͨ�������α�ı仯���ƶ����ݣ�����ʹ��һ������Ҳ�ǿ��Ե�
       //ֻҪ��֤Ԥ���鲢����������������ļ���......
        mergeArray(a,first,middle,last,temp);
    }

}
//��������ֵ�����������ֵ��ȡ����
//��ѡ�����ֵ.....
template<class T>
void MergeSort(T a[],int n)
{
    //�鲢������ص㣬��Ҫ����һ���µ����������м�ʹ�õĹ���.......
    T *p = new T[n];
    if(p==NULL)
        return;
    //�鲢�Ĺ���Ҳ��Ҫ����ָ��
    mergeSort(a,0,n-1,p);
    delete[] p;
}

//�൱��ָ���ƶ�
//��ȵ�����£�ָ�벻�ᶯ.....
template<class T>
void mergeArrayTest(T *a,int m,T *b,int n,T *temp)
{
    int i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
            temp[k++]=a[i++];
        else
            temp[k++]=b[j++];
    }
    while(i<m)
    {
        temp[k++]= a[i++];
    }
    while(j<n)
    {
        temp[k++]= b[j++];
    }
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
    MergeSort(arrayInt,num);
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
