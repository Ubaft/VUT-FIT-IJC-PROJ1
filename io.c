// io.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include "io.h"
int get_word(char *s, int max, FILE *f){
    if (f == NULL)
        return EOF;
    char c;
    c=fgetc(f);
    while ((c != EOF) && isspace(c) != 0) c = fgetc(f);
    if (c == EOF)
        return EOF;

    int i = 0;
    while ((c != EOF) && (isspace(c) == 0) && (i < max - 1))
    {
        s[i] = c;
        i++;
        c = fgetc(f);
    }
    s[i] = '\0';
    
    if(i != max - 1)
        return i;
    while ((c != EOF) && isspace(c) == 0) {
        c = fgetc(f);
        i++;
    }
    return i;
}