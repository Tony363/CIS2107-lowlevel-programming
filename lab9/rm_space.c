#include <stdio.h>

// void rm_space(char *s){
//     int i = 0;
//     int j = 0;
//     while (s[i]) {
//         if (s[i] != ' ') {
//             s[j] = s[i];
//             j++;
//         }
//         i++;
//     }
//     s[j] = '\0';
// }

void rm_space(char *s){
    if (s == NULL)
        return;
    char *end = s;
    char *start = s;
    char *stmp = s;
    while (*start++ == ' ') {}
    start--;
    while (*stmp++ = *start++){}
    while (*end++){}
    end--;
    while (*end-- == ' '){}
    end++;
    end = '\0';
}

int main(){
    char s[] = "   Hello World   ";
    rm_space(s);
    printf("%s\n",s);
    return 0;
}