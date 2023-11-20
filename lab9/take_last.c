#include <stdio.h>

void take_last(char *s,int n){
    int i = 0;
    while (s[i]) 
        i++;
    i--;
    int j = 0;
    while (j < n) {
        s[j] = s[i - n + 1 + j];
        j++;
    }
    s[j] = '\0';
}

int main(){
    char s[] = "Hello World";
    take_last(s, 2);
    printf("%s\n", s);
    return 0;
}