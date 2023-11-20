#include <stdio.h>
#include <stdlib.h>

char *repeat(char *s, int x, char sep){
    if (s == NULL)
        return s;
    char *stmp = s;
    int strlen = 0;
    while (*stmp++){strlen++;};  
    int bytes = strlen * x + x,i = 0,j = 0;
    char *out = (char *)malloc(sizeof(char)*bytes);
    while (i + j < bytes) {
        out[i + j] = s[i % strlen];
        if (i % strlen == strlen - 1){
            j++;
            out[i + j] = sep;
        }
        i++;
    }
    out[i + j - 1] = '\0';
    return out;
}

// int main(){
//     char *s = "Hello World";
//     char *p = repeat(s, 2, '-');
//     printf("%s\n", p);
//     return 0;
// }