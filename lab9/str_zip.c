#include <stdio.h>

char* str_zip(char *s1, char *s2){
    int flag = 0;
    char* zipped = (char *)malloc(sizeof(char) * 100);
    while (flag > -1){
        *zipped++ = !(flag % 2)?*s2++:*s1++;
        flag++;
    }
    return zipped - flag;
}