#include <iostream>
#include <stdio.h>
#define LOCAL
using namespace std;

/**
��������˼·
 /ʹ�ÿ������򷽷���a[ 0 :n- 1 ]����
��a[ 0 :n- 1 ]��ѡ��һ��Ԫ����Ϊm i d d l e����Ԫ��Ϊ֧��
�����µ�Ԫ�طָ�Ϊ����left ��r i g h t��ʹ��l e f t�е�Ԫ�ض�С�ڵ���֧�㣬��right �е�Ԫ�ض����ڵ���֧��
�ݹ��ʹ�ÿ������򷽷���left ��������
�ݹ��ʹ�ÿ������򷽷���right ��������
���ý��Ϊl e f t + m i d d l e + r i g h t

���η����Լ����Ϊ��
1��ѡ��һ����ֵԪ��
2���������ֵԪ��Ϊ���ݣ�Ȼ����������߽��л��������������������ֵԪ�ر���
3��ֱ��һ��ѭ������
4�����ν�������ѭ��
**/

/**
����������ص��ǣ�ÿ��һ��ѭ����ʵ���϶��ƶ����±��λ��
��һ��ѭ������������������һ���֣��������岢û�б仯
**/

//��������ֵ�����������ֵ��ȡ����
//��ѡ�����ֵ.....
void GetMiddle()
{

}

//��������
template<class T>
void Swap(T &a, T&b){
    T temp = a;
    a = b;
    b = temp;
}


//��һ����ⷽ��
template <class T>
void quickSort(T a[],int left,int right)
{
    //ѡ����ֵ
    if(left>=right)
        return;
    int first = left;
    int last = right;
    T middle = a[first];
    //���������ߵ�Ԫ���滻
    //һ��һ��ѭ�������first == last�����
    while(first<last){
        //���Խ����ʾ�������Ҫ���ұߵ�Ԫ�ؿ�ʼ������
        //ע��������ڷ��Ų��ܵ�����Ȼ��������Ⱥŵ�.....
        //������̿��Ե�ͬ��ð������Ĺ���.....��ϸ����¾ͺ�
        while(first<last && a[last]>=middle)
        {
            last--;
        }
        //����ҵ����ݣ�����н���
        Swap(a[last],a[first]);
        //����ߵ�Ԫ�ؿ�ʼ��
        while(first<last&&a[first]<=middle)
        {
            first++;
        }
        //����ҵ������򽻻�
        Swap(a[last],a[first]);
    }
    //���÷��εĲ���
    a[last] = middle;
    //������εĹ���
    //���
    quickSort(a,left,last-1);
    //�ұ�
    quickSort(a,last+1,right);
}

//��һƪ���ڿӵ����Ҳ��������ᣬ�����������˿�
//http://blog.csdn.net/morewindows/article/details/6684558
//��ϸ���뵱i==j�����
//ʵ���Ͻ������ݵ�ʱ������˺��Ҷ��ڽ�����first��lastֻ���ƶ���ָ�룬���Գ���i = j��ʱ�򣬲���Ӱ��
//��ϸ�����������к�ż�����в�ͬ�����.....
//ͬ��������к�ż�����в���Ӱ��
//��ϸ����һ��������ɵ����
//��һ��ѭ����ɺ󣬻���� first == last �������Ȼ����ܳ���first = last��ĩβ/�ײ� /ĩβһ������
//�ͻ���������ݹ���жϼ���.....
//��ϸ���뻻ֵ�����
//����һ��Ҫ��ֵ�������ǻ��ӵ����.....�������Ϊû��Ҫ��ֵ......

//���������Ϊ�����㷨��������,�������鳤��
template<class T>
void QuickSort(T *a,int n)
{
    //��a[0:n-1]���п�������
    //ע�����鳤�Ⱥ���λ���ʲ�ͬ
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
