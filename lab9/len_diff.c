#include <stdio.h>

int len_diff(char *s1,char *s2){
    int len1 = 0,len2 = 0;
    while (*s1++ != NULL)
        len1++;
    while (*s2++ != NULL)
        len2++;
    return len1 - len2;
}

// int main(){
//     char *s1 = "Hello";
//     char *s2 = "Hello";
//     printf("%d\n", len_diff(s1, s2));
//     char *s3 = "Hello";
//     char *s4 = "Hella hello";
//     printf("%d\n", len_diff(s3, s4));
// }