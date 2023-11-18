#include <stdio.h>

int is_empty(char *s1){
    if (s1 != NULL || *s1 != '\0') 
        return 0;
    while (*s1++ != ' ') {}
    return 1;
}