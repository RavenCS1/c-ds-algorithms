#include <stdio.h>
#include <stdlib.h>

int main(void){
    const int two = 2;
    int i = 1;
    switch(i){
        case 1: printf("case 1\n");
        case two: printf("case 2\n");
        case 3: printf("case 3\n");
        default: ;
    }
    return EXIT_FAILURE;
}
