#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define VBAR "\u2502"
#define HBAR "\u2500"
#define TOPLEFT "\u250c"
#define TOPRIGHT "\u2510"

void draw_sep(char const start[static 1], char const end[static 1]);

int main(void){
    setlocale(LC_ALL, "");
    draw_sep(TOPLEFT " © 2014 j nz 'g z,t t ", TOPRIGHT);
    return EXIT_SUCCESS;
}

void draw_sep(char const start[static 1], char const end[static 1]){
    fputs(start, stdout);
    size_t slen = mblen(start, 0);
    size_t elen = 90-mblen(end, 0);
    for(size_t i = slen; i < elen; ++i) fputs(HBAR, stdout);
    fputs(end, stdout);
    fputc('\n', stdout);
}

