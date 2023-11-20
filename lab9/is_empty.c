#include <stdio.h>

int is_empty(char *s1){
    if (s1 == NULL) 
        return 1;
    while (*s1++ == ' ') {}
    return *s1 == '\0';
}

// int main(){
//     char s[] = "a ";
//     printf("%d\n",is_empty(s));
//     return 0;
// }