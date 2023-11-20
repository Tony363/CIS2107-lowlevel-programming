#include <stdio.h>

char *pad(char *s,int d){
    if (s == NULL)
        return s;
    int len = 0;
    while (*s++)
        len++;
    // *out = '\0';
    char *final = (char* )realloc(s,sizeof(char) * (len % d));
    *(final + (len + (len % d))) = '\0';
    return final;
}