#include <stdio.h>
#include <stdlib.h>

int main(void){
    int len = 5;
    char* str = malloc(sizeof(char[len + 1]));
    for(int i = 0; i < len; ++i)
        str[i] = i % 2 ? '1' : '0';
    str[len] = '\0';
    puts(str);
    free(str);
    return EXIT_SUCCESS;
}
