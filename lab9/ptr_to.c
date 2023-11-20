#include <stdio.h>

char *ptr_to(char *h,char *n){
    if (h == NULL || n == NULL)
        return NULL;
    char *k = h,*temp = n;
    while (*h) {
        if (*(temp + 1) == '\0') 
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

int main(){
    char s[] = "Hello World";
    char t[] = "o W";
    char *p = ptr_to(s,t);
    printf("%s\n",p);
    return 0;
}