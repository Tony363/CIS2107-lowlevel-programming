#include <stdio.h>
#include <ctype.h>
int strcmp_ign_case(char *s1, char *s2){
    if (s1 == NULL || s2 == NULL)
        return 0;
    while (*s1 && *s2) {
        if (tolower(*s1) < tolower(*s2))
            return 1;
        if (tolower(*s1) > tolower(*s2))
            return -1;
        s1++;
        s2++;   
    }
    return 0;
    // TODO edge case different string length, strip leading and ending white spaces
}

int main(){
    char s1[] = "zello";
    char s2[] = "hello";
    printf("%d\n", strcmp_ign_case(s1, s2));
}