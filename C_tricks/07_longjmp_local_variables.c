#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;  

int main(void){
    int x = 0;
    if (setjmp(buf) == 0){
        x = 42;
        longjmp(buf, 1);
    } else{
        printf("%d\n", x); // might be 0, 42... or something completely different!
    }
    return EXIT_SUCCESS;
}
