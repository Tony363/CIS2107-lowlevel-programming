#include <stdio.h>

int all_letters(char *s){
    if (s == NULL)
        return 0;
    int check = (int)s[0] < 90;
    while (*s) {
        if (((int)s[0] < 90) != check)
            return 0;
        s++;
    }
    return 1;
}

// int main(){
//     char *s = "Hello";
//     printf("%d\n", all_letters(s));
//     char *s1 = "HELLO";
//     printf("%d\n", all_letters(s1));
//     char *s2 = "hello";
//     printf("%d\n", all_letters(s2));
//     return 0;
// }