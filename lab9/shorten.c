#include<stdio.h>

void shorten(char *s,int new_len){
    int i = 0;
    while (i < new_len) {
        if (*(s + i) == '\0')
            break;
        i++;
    }
    *(s + i) = '\0';
}