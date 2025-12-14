#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a = 5, b, c;
    __asm__ ("addl %%ebx, %%eax"
         : "=a" (b)           // output: b = eax after addition
         : "a" (a), "b" (3)   // inputs: eax = a, ebx = 3
         :                    // no clobbered registers
    );
    return EXIT_SUCCESS;
}
