#include <stdio.h>
#include <stdlib.h>

int main(void){
    char *available_resources[] = { 
        "long string just to try if it works \
        long sring just to try if it works",  
        "part of",  
        "longer" /* no comma! */  
        "sentence and something",  
        "very",  
        "interesting",  
        "at the end of the exmaple", /* and here we have an extra comma*/  
    };
    printf("%s\n", available_resources[0]);
    return EXIT_SUCCESS;
}
