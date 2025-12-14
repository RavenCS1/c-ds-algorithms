#include <stdio.h>
#include <stdlib.h>

#define THIS_WORKS int

typedef int this_does_not_work;

int main(void){
    this_does_not_work a;
    unsigned this_does_not_work b;
    THIS_WORKS c;
    unsigned THIS_WORKS d;
    return EXIT_FAILURE;
}
