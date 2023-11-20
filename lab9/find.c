#include <stdio.h>

int find(char *h, char *n){
    if (h == NULL || n == NULL)
        return -1;
    int i = 0, j = 0,k = 0;
    while (h[i]) {
        if (n[j] == '\0') {
            return k;
        }
        if (h[i] == n[j]) {
            j++;
        } else {
            j = 0;
            k = i + 1;
        }
        i++;
    }
    return -1;
}

int main(){
    char h[] = "Hello World";
    char n[] = "o W";
    printf("%d\n",find(h,n));
    return 0;
}