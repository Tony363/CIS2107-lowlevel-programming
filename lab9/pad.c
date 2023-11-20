#include <stdio.h>
#include <stdlib.h>

char *pad(char *s,int d){
    if (s == NULL)
        return s;
    int len = 0;
    char *str_iter = s;
    while (*str_iter++)
        len++;
    int padding = len + d - (len % d);
    char *out = (char* )malloc(sizeof(char) * padding);
    int i = 0;
    while (i < len){
        *(out + i) = *(s + i);
        i++;
    }
    while (len < padding){
        *(out + len) = '*';
        len++;
    }    
    return out;
}

int main(){
    char *s = "Hello World";
    char *p = pad(s, 5);
    printf("%s\n", p);
    return 0;
}