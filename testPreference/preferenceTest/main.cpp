#include<iostream>
using namespace std;
void test(int * &p)
{

    int *a = new int[3];
    a[0] =10;
    cout<<p<<endl;
    p =&a[0];
    delete a;
    cout<<p<<" "<<*p<<endl;
}
int main(void)
{
    int *p=NULL;
    test(p);
    if(p!=NULL)
        cout<<p<<"p not NULL"<<endl;
    int t =234;
    int * p_1;
    p_1= &t;
    int * p_2 = p_1;
    //��һ�丳ֵ����ʾ�ı�ָ��ָ��ĵ�ַ��ָ��ĸ�ֵ�������Ǹı�ָ���ָ�����.....
    p_2 = (int *)0x00000005;

    cout<<p_1<<" "<<p_2<<endl;
    cout<<&p_1<<" "<<&p_2<<endl;
    //����ָ�����ָ��ͬһ���ط�����ô�ı�ֵ����ı��κζ���
    return 0;
}
