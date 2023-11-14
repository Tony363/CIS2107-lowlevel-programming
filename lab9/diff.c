#include <stdio.h>

int diff(char *s1, char *s2){
    int count = 0;
    while (*s1 || *s2) {
        if (*s1 != *s2)
            count++;
        s1 = (*(s1) != '\0')?s1 + 1: NULL;
        s2 = (*(s2) != '\0')?s2 + 1: NULL;

    }
    return count;
}