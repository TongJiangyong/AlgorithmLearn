#include<iostream>
#include<stdio.h>
#include"chainList.h"
//#define LOCAL
using namespace std;
//让new引发NoMem异常，而不是xalloc异常
void my_new_handler(){
    throw NoMem();
}
new_handler Old_Handler_=set_new_handler(my_new_handler);

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Chain <char>T;
    cout<<"chain is"<<T<<endl;
    T.Insert(0,'a').Insert(1,'b').Insert(2,'c').Insert(2,'d');
    cout<<"chain is "<<T<<endl;
    cout<<"chain length is "<<T.Length()<<endl;
    char x;
    int num=3;
    T.Delete(num,x);
    cout<<"************* delete num is "<<num<<endl;
    cout<<"chain length is "<<T.Length()<<endl;
    cout<<"chain is "<<T<<endl;
    cout<<"delete num is "<<x<<endl;
    char num_2 ='x';
    T.Append(num_2);
    cout<<"************* append num is "<<num_2<<endl;
    cout<<"chain is "<<T<<endl;

    char *test;
    ChainIterator<char>c;
    test = c.Initialize(T);
    while(test){
        cout<<*test<<" ";
        test = c.Next();
    }
    cout<<endl;

#ifdef LOCAL
    fclose("in.txt", "r", stdin);
    fclose("out.txt", "w", stdout);
#endif

}
