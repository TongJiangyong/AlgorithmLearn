#include<stdio.h>
#include <iostream>
#include "linearList.h"
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
try {
    LinearList<int> L(5);
    cout << "Length = " << L.Length() << endl;
    cout << "IsEmpty = " << L.IsEmpty() <<endl;
    L.Insert(0,2) .Insert(1,6).Insert(0,3) ;
    cout << "List is " << L <<endl;
    cout << "IsEmpty = " << L.IsEmpty() << endl;
    int z;
    L.Find( 1 , z ) ;
    cout << "First element is " << z << endl;
    cout << "Length = " << L.Length() << endl;
    L.Delete( 1 , z ) ;
    cout << "Deleted element is " << z << endl;
    cout << "List is " << L << endl;
    }
    catch (...) {
        cerr << "An exception has occurred" << endl;
    }
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
