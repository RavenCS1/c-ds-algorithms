#include <stdio.h>
#include <stdlib.h>

void fgoto(unsigned);

int main(void){
    fgoto(2);
    return EXIT_SUCCESS;
}

void fgoto(unsigned n){
    unsigned j = 0;
    unsigned* p = 0;
    unsigned* q;
    AGAIN:
    if(p) printf("%u: p and q are %s, *p is %u, *q is %u\n", j, (q == p) ? "equal" : "unequal", *p, q ? *q : 0);
    q = p;
    p = &((unsigned){ j, });
    ++j;    
    if(j <= n) goto AGAIN;
}
