#include <stdio.h>
#include <stdlib.h>

char *str_connect(char **strs, int n, char c){
    if (strs == NULL)
        return strs;
    char *cat = malloc(sizeof(char)*100);
    char *cat_iter = cat;
    int i = 0;
    while (i < n){
        *cat_iter++ = c;
        char *tmp = strs[i];
        while (*tmp)
            *cat_iter++ = *tmp++;
        i++;
    }
    *cat_iter = '\0';
    cat = realloc(cat,cat_iter - cat);
    return cat + 1;
}

// int main(){
//     char *strs[] = {"Hello","World","!"};
//     printf("%s\n",str_connect(strs,3,'-'));
//     return 0;
// }