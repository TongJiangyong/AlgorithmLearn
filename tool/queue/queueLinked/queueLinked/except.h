#ifndef EXCEPT_H


#define EXCEPT_H
#include<stdio.h>
class NoMem{
public:
    NoMem(){
       printf("NoMem!!!\n");
    }
};

class OutOfBounds{
public:
    OutOfBounds(){
       printf("OutOfBounds!!!\n");
    }
};
#endif // EXCEPT_H


