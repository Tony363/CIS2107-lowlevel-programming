#include <stdio.h>

char *dedup(char *s){
    int flags[26] = {0};
    int upperlower = 0,len = 0;
    char *out = (char *)malloc(sizeof(char)*30);
    while (*s){
        upperlower = (int)*s < 90 ? 65 : 97;
        if (!flags[*s - upperlower]){
            flags[*s - upperlower] = 1;
            *out++ = *s;
        }
        s++;
    }
    *out = '\0';
    return out - len;
}
