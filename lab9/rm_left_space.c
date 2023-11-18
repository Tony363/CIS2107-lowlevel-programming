#include <stdio.h>

void rm_left_space(char *s1){
    int i = 0;
    while (s1[i] == ' ') {
        i++;
    }
    int j = 0;
    while (s1[i]) {
        s1[j] = s1[i];
        i++;
        j++;
    }
    s1[j] = '\0';
}