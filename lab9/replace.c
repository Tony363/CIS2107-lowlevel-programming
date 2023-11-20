#include <stdio.h>
#include <stdlib.h>


char *replace(char *s, char *pat, char *rep){
    if (s == NULL)
        return s;
    int buffer = 100;
    char *out_iter = (char *)malloc(sizeof(char)*buffer),*pat_tmp = pat,*rep_tmp = rep;
    char *out = out_iter;
    while (*s){
        if (*pat_tmp == '\0'){
            while (*rep_tmp)
                *out_iter++ = *rep_tmp++;
            rep_tmp = rep;
            pat_tmp = pat;  
        }
        if (*s == *pat_tmp){
            pat_tmp++;
        } else {
            *out_iter++ = *s;
        }
        s++;
    }   
    out_iter = '\0';
    return out;
}

// int main(){
//     char *s = "Hello World",*pat = "l",*rep = "LOLZ";
//     printf("%s\n",replace(s,pat,rep));
//     return 0;
// }