#include <stdio.h>
#include <stdlib.h>

int main(void){
    const int var = 10;
    int* ptr = &var;
    *ptr = 20;
    printf("%d\n", var);
    return EXIT_SUCCESS;
}
