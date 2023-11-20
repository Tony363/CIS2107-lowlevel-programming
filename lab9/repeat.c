#include <stdio.h>

char *repeat(char *s, int x, char sep){
    if (s == NULL)
        return s;
    int strlen = sizeof(s)/sizeof(s[0]);
    int bytes = strlen * x + x,i = 0;
    char *out = (char *)malloc(bytes);
    while (i < bytes) {
        out[i] = s[i % strlen];
        if (i % strlen == strlen - 1)
            out[i] = sep;
        i++;
    }
    return out;
}