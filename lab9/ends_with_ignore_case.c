#include <stdio.h>
#include <ctype.h>

int ends_with_ignore_case(char *s, char *suff){
    if (s == NULL || suff == NULL)
        return 0;
    int _case = 0;
    while (*s++){};
    while (*suff++){};
    while (*s && *suff) {
        *s = ((int)*s < 90 )?(*s) - 32: *s;
        *suff = ((int)*suff < 90 )?(*suff) - 32: *suff;
        if (*s != *suff)
            return 0;
        s--;
        suff--;
    } //TODO deal with case insensitive
    return 1;
}