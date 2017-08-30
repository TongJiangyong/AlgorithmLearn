#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LOCAL

#define ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
using namespace std;
const int max_size=20;//쳲���������ĳ���
/**
쳲��������ҷ���
쳲����������㷨�Աȶ��ַ����ص��ǣ�
����ʹ��λ�ƣ�ʹ�üӼ�������ʵ�ֲ��ҵ�ļ���
ͬ��Ҳ�Ƕ�������н��д���ķ���
����˼����ʹ��Fibonacci���������зָ������
����ÿһ��������������ǰ�������ĺ�
��������������ԣ����ϵĶ��������зָ�....
��ƪ���½��ıȽϺ�....
http://blog.csdn.net/zsw12013/article/details/50003505

**/

template <class T>

int getArrayLen(T& array)

{
    //������Ϊ������������ʱ������ָ����������飬���ݵ���������׵�ַ
    //������ﲻ�����ã�����Զ����1��һ��Ҫע�⼴��....
    return (sizeof(array) / sizeof(array[0]));
}
//��C/C++�У�������ݵ���ָ�룬��һ���޷��������鳤�ȣ�strlen������.....���ԭ����....


/*����һ��쳲���������*/
void Fibonacci(int * F)
{
    F[0]=0;
    F[1]=1;
    for(int i=2;i<max_size;++i)
        F[i]=F[i-1]+F[i-2];
}

/*����쳲��������ҷ�*/
int FibonacciSearch(int *a,int key,int n)  //aΪҪ���ҵ�����,nΪҪ���ҵ����鳤��,keyΪҪ���ҵĹؼ���
{
  int low=0;
  int high=n-1;

  int F[max_size];
  //����쳲���������
  Fibonacci(F);//����һ��쳲���������F

  int k=0;

  while(n>F[k]-1)//����nλ��쳲��������е�λ��
      ++k;

//����һ���µģ�׼�����ڲ��ҵ�쳲���������
  int  * temp;//������a��չ��F[k]-1�ĳ���
  temp=new int [F[k]-1];
  memcpy(temp,a,n*sizeof(int));

  //��ȫ쳲��������п����λ�ã���������쳲����������ʵõ���
  for(int i=n;i<F[k]-1;++i)
     temp[i]=a[n-1];

    //��ʼ����쳲��������в��ң�mid���󷢣����͹�����쳲������������
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
           return mid; //�������˵��mid��Ϊ���ҵ���λ��
       else
           return n-1; //��mid>=n��˵������չ����ֵ,����n-1
    }
  }
  //���ע��ɾ��temp
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
cout<<FibonacciSearch(arrayInt,searchNum,num)<<endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}
