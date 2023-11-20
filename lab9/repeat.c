#include <stdio.h>
#include <stdlib.h>

char *repeat(char *s, int x, char sep){
    if (s == NULL)
        return s;
    char *stmp = s;
    int strlen = 0;
    while (*stmp++){strlen++;};  
    int bytes = strlen * x + x + 1,i = 0,j = 0;
    printf("%d\n",bytes);
    char *out = (char *)malloc(bytes);
    while (i < bytes) {
        out[i + j] = s[i % strlen];
        if (i % strlen == strlen - 1){
            j++;
            out[i + j] = sep;
        }
        i++;
    }
    return out;
}

int main(){
    char *s = "Hello World";
    char *p = repeat(s, 2, '-');
    printf("%s\n", p);
    return 0;
}