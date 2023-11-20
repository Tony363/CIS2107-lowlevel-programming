#include <stdio.h>
#include <stdlib.h>

char* str_zip(char *s1, char *s2){
    int flag = 0;
    char* zipped = (char *)malloc(sizeof(char) * 100);
    while (*s1 != '\0' && *s2 != '\0'){
        *zipped++ = !(flag % 2)?*s2++:*s1++;
        flag++;
    }
    if (*s1 == '\0'){
        while (*s2 != '\0'){
            *zipped++ = *s2++;
            flag++;
        }
    } else {
        while (*s1 != '\0'){
            *zipped++ = *s1++;
            flag++;
        }
    }
    return zipped - flag;
}

int main(){
    char *s1 = "Tony";
    char *s2 = "Siu";
    puts(str_zip(s1,s2));
}