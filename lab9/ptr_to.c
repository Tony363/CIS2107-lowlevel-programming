#include <stdio.h>

char *ptr_to(char *h,char *n){
    if (h == NULL || n == NULL)
        return NULL;
    // int i = 0, j = 0,k = 0;
    char *k = h,*temp = n;
    while (*h) {
        if (*temp == '\0') 
            return k;
        if (*h == *temp) {
            temp++;
        } else {
            temp = n;
            k = h + 1;
        }
        h++;
    }
    return NULL;
}