#include<iostream>
#include<stdio.h>
#include"IndirectList.h"
//#define LOCAL
using namespace std;
//��new����NoMem�쳣��������xalloc�쳣
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






#ifdef LOCAL
    fclose("in.txt", "r", stdin);
    fclose("out.txt", "w", stdout);
#endif

}
