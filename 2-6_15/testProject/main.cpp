#include<stdio.h>
#include <iostream>
#include<vector>
#define LOCAL
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
using namespace std;


//���ߺ���
template <class T>
inline void Swap(T& a, T& b)
{// ����a��b
    T temp = a; a = b; b = temp;
}
//���ߺ���
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
//����2-5������������
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
//�ڶ���reRank�ķ��� ԭ�����ŷ�
//ԭ���Ǹ��ݽ����ķ�ʽ��ֱ��ÿһ��λ�ö������ˣ���������
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
//ѡ������
//����˼·��
//�����ҳ�����Ԫ�أ������ƶ��� a [ n-1 ]��Ȼ�������µ� n-1��Ԫ����Ѱ������Ԫ�ز������ƶ���a [ n-2 ]����˽�����ȥ���������򷽷�Ϊѡ������
template <class T>
void selectionSort (T a[], int n)
{
    for (int size = n; size > 1; size--)
    {
        int j= Max(a, size);
        Swap(a[j],a[size-1]);
    }
}

//ѡ������2
//����˼·��
//����2 - 7��ѡ����������һ��ȱ���ǣ���ʹԪ���Ѿ��������У�������Ȼ�������С�
//���磬��ʹ�ڵڶ���ѭ����������Ԫ�ؿ����Ѿ��������У� f o rѭ������Ҫִ��n - 1�Ρ�
//Ϊ����ֹ����Ҫ��ѭ�����ڲ������Ԫ���ڼ䣬����˳���������Ƿ��Ѱ������С�����2 - 1 2������һ����������˼��ʵ�ֵ�ѡ����������
//�������ַ������Ľ�Ч������
template <class T>
void selectionSort_2(T a[], int n)
{
    bool sorted = false;
    for (int size = n; !sorted && (size > 1); size--) {
        int pos = 0;
        sorted = true;
        // �����Ԫ��
        for (int i = 1; i < size; i++)
            if (a[pos] <= a[i]) pos = i;
            else sorted = false; // δ��������
        Swap(a[pos], a[size - 1 ] ) ;
        }
}



//2-8ð������
//ð�ݲ��ԡ������Ԫ���Ƶ��Ҳ�����ð�ݹ����У������ڵ�Ԫ�ؽ��бȽϣ������ߵ�Ԫ�ش����ұߵ�Ԫ�أ��򽻻�������Ԫ��
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

//2-13 ������ֹ��ð������
//���������һ��ð���У�û�з��������������ʾ�����Ѿ���ɣ���һ����Ч�����

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


//��������
//����˼·��
//��Ϊֻ��һ��Ԫ�ص�������һ��
//�������飬���Կ��Դӽ������������ n ��Ԫ�صĵ�һ��Ԫ�ص����鿪ʼ��ͨ���ѵڶ���Ԫ��
//���뵽�����Ԫ�����У����Եõ�һ����СΪ 2���������顣���������Ԫ�ؿ��Եõ�һ����
//СΪ3���������顣�������ַ�������������ȥ�����ս��õ�һ����СΪ n���������飬������
//��ʽΪ�������� insertion sort��
template<class T>
void Insert(T a[], int n, const T& x)
{// ���������� a [ 0 : n - 1 ]�в���Ԫ��x
    int i;
    //ע�⣬�����һ��forѭ����Ϊʲô�Ӻ���ǰ������Ϊ�˽�����λ�Ĳ��������԰��ղ�����������ʣ������������Ƚ�С��
    //�������λ��Ȼ����ѭ����������λ���µ����ݼ���
    cout <<"test_2:"<<x<<endl;
    for (i = n-1; i >= 0 && x < a[i]; i--)
        a[i+1] = a[i];
    cout <<"test_3:"<<x<<endl;
    a[i+1] = x;
}
template<class T>
void InsertionSort(T a[], int n)
{// �� a [ 0 : n-1 ]��������
    for (int i = 1; i < n; i++) {
        T t = a[i];
        cout <<"test_1:"<<t<<endl;
        //Insert(a, i, a[i]);
//ע�������ֻ�ܴ���t�����ܴ���a[i]��ԭ����Ϊ�����Insert���ݵ������ã��������������
//�����ڲ����иı�Ļ�����ı�����������ȡ��
//��������ֵ��ע����ǣ�����������ݵ������ã�һ��Ҫע�⣬�������������������ڴ�
//�ں������й����еı仯һ��Ҫע�⣡������
        Insert(a, i, t);
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
    int n=0;
    //�������������Ļ�������
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
