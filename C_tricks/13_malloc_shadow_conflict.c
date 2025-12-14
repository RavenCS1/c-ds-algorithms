#include <stdio.h>
#include <stdlib.h>

void malloc(int);

int main(void){
    int x = 5;
    malloc(x);
    return EXIT_FAILURE;
}

void malloc(int x){
    printf("x = %d\n", x);
    return;
}
