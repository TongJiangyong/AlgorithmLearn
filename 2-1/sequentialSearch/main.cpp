#include<stdio.h>
#include <iostream>
#include<vector>
#define LOCAL
#define INF 1000000000
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
using namespace std;
template<class T>
//���������a��ֵ���ݣ�����ÿ��Ԫ�ض���Ҫ�ֽ�ͨ��ָ������ֵ
int sequentialSearch(T a[],const T &x,int n)
{
    int i;
    for(i=0; i<n&&a[i]!=x; i++);
    if(i==n)
        return -1;
    return i;
}

template<class T>
int sequentialSearch2(T a[],const T &x ,int n)
{
    if(n<1)
        return -1;
    if(a[n-1]== x)
        return n-1;
    return sequentialSearch2(a,x,n-1);

}


template<class T>
void maxArray(T a[],T &x,int n)
{
    int i;
    x=a[0];
    for(i=0; i<n; i++)
    {
        if(a[i]>x)
        {
            x = a[i];
        }
    }
}
//�����������Ӷ�̬����Ļ�������
//http://wenda.tianya.cn/question/05cf48b56c85c114
int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n=0,maxNum=0,position=-1;
    //�������������Ļ�������
    scanf("%d",&n);
    int *input = new int[n];
    for(int i=0;i<n;i++){
        //ע�⣬һ���������뷽��������.....
        //scanf("%d", &input[i]);
        cin>>input[i];
    }

    //while(scanf("%d", &input[i]) != EOF)
    //{
    //    i++;
    //}
    //�����ֵ
    maxArray(input,maxNum,n);
    //����������λ��
    position = sequentialSearch2(input,maxNum,n);
    printf("maxNum is %d   position is %d\n",maxNum,position);
    delete [] input;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
