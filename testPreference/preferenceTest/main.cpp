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
    //这一句赋值，表示改变指针指向的地址，指针的赋值，单纯是改变指针的指向而已.....
    p_2 = (int *)0x00000005;

    cout<<p_1<<" "<<p_2<<endl;
    cout<<&p_1<<" "<<&p_2<<endl;
    //两个指针如果指向同一个地方，那么改变值不会改变任何东西
    return 0;
}
