#include <stdio.h>
#include <stdlib.h>

int _is_empty(char *str){
    return str == NULL || *str == '\0';
}

void rm_empties(char **words){
    if (words == NULL)
        return;
    int i = 0,j = 0;
    while (words[j] != NULL) {
        if (!_is_empty(words[j])) 
            words[i++] = words[j];
        j++;
    }
    words[i] = NULL;
}

// int main(){
//     char **words = malloc(4 * sizeof(char *));
//     words[0] = "Hello";
//     words[1] = "";
//     words[2] = "World";
//     words[3] = NULL;
//     rm_empties(words);
//     int i = 0;
//     while (words[i++] != NULL)
//         printf("%s\n",words[i - 1]);

//     return 0;
// }