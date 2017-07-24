#include <iostream>
#include <stdio.h>

using namespace std;

template<class T>
void test(const T& a){

    a =10;
    cout<<a<<endl;
}

int main(){
    unsigned x=10;
    unsigned y = 100;
    int m[2]={1,2};
    test(m[0]);
}


