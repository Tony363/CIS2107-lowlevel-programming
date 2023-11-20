#include <stdio.h>

// TODO finish not same length
int diff(char *s1, char *s2){
    int count = 0;
    while (*s1 || *s2) {
        if (*s1 != *s2)
            count++;
        s1 = (*(s1) != '\0')?s1 + 1: s1;
        s2 = (*(s2) != '\0')?s2 + 1: s2;

    }
    return count;
}

// int main(){
//     char *s1 = "Hello";
//     char *s2 = "Hello";
//     printf("%d\n", diff(s1, s2));
//     char *s3 = "Hello";
//     char *s4 = "Hella     ";
//     printf("%d\n", diff(s3, s4));
// }