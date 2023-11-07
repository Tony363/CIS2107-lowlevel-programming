#include <stdio.h>

int all_letters(char *s){
    int check = (int)s < 90;
    while (*s) {
        if (((int)s < 90) != check)
            return 0;
        s++;
    }
    return 1;
}