#include <stdio.h>
#include <ctype.h>

int ends_with_ignore_case(char *s, char *suff){
    if (s == NULL || suff == NULL)
        return 0;

    while (*s++){};
    while (*suff++){};
    s--;
    suff--;
    while (*--s && *--suff) {
        *s = (*s < 90 )?tolower(*s): *s;
        *suff = (*suff < 90 )?tolower(*suff): *suff;
        if (*s != *suff)
            return 0;
    } //TODO deal with case insensitive
    return 1;
}

// int main(){
//     char s[] = "Hello World";
//     char suff[] = "world";
//     printf("%d\n", ends_with_ignore_case(s, suff));
//     return 0;
// }