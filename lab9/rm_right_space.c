#include <stdio.h>

void rm_right_space(char *s1){
    int i = 0;
    while (s1[i]) {
        i++;
    }
    i--;
    while (s1[i] == ' ') {
        i--;
    }
    s1[i+1] = '\0';
}