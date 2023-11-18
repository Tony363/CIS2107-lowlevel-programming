#include <stdio.h>

void capitalize(char *s1){
    if (s1 == NULL)
        return;
    if (*s1 > 90)
        *s1 -= 32;
    while (*s1++ != ' ') {
        if (*s1 <= 90)
            *s1 += 32;
    }
}