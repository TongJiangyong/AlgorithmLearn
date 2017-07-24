#ifndef EXCEPT_H


#define EXCEPT_H
#include<stdio.h>
class NoMem{
public:
    NoMem(){
       printf("NoMem\n");
    }
};

class OutOfBounds{
public:
    OutOfBounds(){
       printf("OutOfBounds\n");
    }
};

class BadInput{
public:
    BadInput(){
       printf("BadInput\n");
    }
};
#endif // EXCEPT_H


