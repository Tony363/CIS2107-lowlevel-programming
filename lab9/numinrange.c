#include <stdio.h>

int num_in_range(char *s1, char b, char t){
    int count = 0;
    while (*s1) {
        if (*s1 >= b && *s1 <= t) // ascii value or between count??
            count++;
        s1++;
    }
    return count;
}

// int main(){
//     char *s1 = "hello";
//     char b = 'a';
//     char t = 'b';
//     printf("%d\n", num_in_range(s1, b, t));
//     return 0;
// }