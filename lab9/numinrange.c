#include <stdio.h>

int num_in_range(char *s1, char b, char t){
    int count = 0;
    while (*s1) {
        if (*s1 >= b && *s1 <= t) // ascii value or between count??
            count++;
        s1++;
    }
    return count;
}