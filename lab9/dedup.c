#include <stdio.h>
#include <stdlib.h>

char *dedup(char *s){
    int flags[26] = {0};
    int upperlower = 0;
    char *out = (char *)malloc(sizeof(char)*30);
    char *out_tmp = out;
    while (*s){
        upperlower = (int)*s < 90 ? 65 : 97;
        if (!flags[*s - upperlower]){
            flags[*s - upperlower] = 1;
            *out_tmp++ = *s;
        }
        s++;
    }
    *out_tmp = '\0';
    return out;
}

int main(){
    char s[] = "Hello World";
    printf("%s\n", dedup(s));
    return 0;
}
