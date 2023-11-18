#include <stdio.h>

void rm_space(char *s){
    int i = 0;
    int j = 0;
    while (s[i]) {
        if (s[i] != ' ') {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';
}