#include<iostream>
#include<stdio.h>
#include"queueLinked.h"
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

//    QueueArray <int>q;
//    q.Add(1).Add(2).Add(4);
//    int temp;
//    q.Delete(temp);
//    cout<<q.First()<<endl;
//    cout<<q.Last()<<endl;


    LinkedQueue <int>q;
    q.Add(1).Add(2).Add(4).Add(8).Add(10);
    int temp;
    q.Delete(temp);
    cout<<q.First()<<endl;
    cout<<q.Last()<<endl;
#ifdef LOCAL
    fclose("in.txt", "r", stdin);
    fclose("out.txt", "w", stdout);
#endif

}
