#include <stdio.h>
#include <stdlib.h>

char **str_chop_all(char *s, char c){
    char **arr = malloc(sizeof(char *)*50);
    char *s_iter = s,*start = s,**arr_iter = arr,*str = NULL,*str_temp = NULL;
    while (*s_iter){
        if (*s_iter == c || *(s_iter + 1) == '\0'){
            str = str_temp = (char *)malloc(sizeof(char)*(s_iter - start + 1));
            while (start <= s_iter){
                *str_temp++ = *start++;
            }
            *arr_iter = str;
            arr_iter++;
            start = s_iter + 1;
        }
        s_iter++;
    }
    *++arr_iter = NULL;
    return arr;
}

// int main(){
//     char *str = "I am ready for a nice vacation";
//     char **arr = str_chop_all(str,' ');
//     int i = 0;
//     while (arr[i++] != NULL)
//         printf("%s\n",arr[i - 1]);
//     return 0;
// }