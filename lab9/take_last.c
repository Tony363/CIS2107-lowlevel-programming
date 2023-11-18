#include <stdio.h>

void take_last(char *s,int n){
    int i = 0;
    while (s[i]) 
        i++;
    i--;
    int j = 0;
    while (j < n) {
        s[j] = s[i];
        i--;
        j++;
    }
    s[j] = '\0';
}