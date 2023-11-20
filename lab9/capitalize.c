#include <stdio.h>

void capitalize(char *s1){
    if (s1 == NULL)
        return;
    if (s1[0] > 90)
        s1[0] = s1[0] - 32;
    s1++;
    while (*s1 != '\0'){
        if (s1[0] <= 90 && s1[0] != ' ')
            s1[0] = s1[0] + 32;
        s1++;
    }
}

int main(){
    char s[] = "hello WORLD";
    capitalize(s);
    puts(s);
}