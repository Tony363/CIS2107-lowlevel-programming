#include <stdio.h>

void rm_right_space(char *s1){
    int i = 0;
    while (s1[i++]) {}
    i--;
    while (s1[i--] == ' ') {}
    s1[i+1] = '\0';
}

// int main(){
//     char s[] = "Hello World 1  ";
//     rm_right_space(s);
//     printf("%s\n",s);
//     return 0;
// }