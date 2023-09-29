#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count_consonants(char* input);

int main(){
    char* input = (char* )malloc(10*sizeof(char));
    puts("Enter a string: ");
    scanf("%s",input);
    printf("Number of consonants: %d\n",count_consonants(input));
    free(input);
    return 0;
}

// write function to count consonants in a string
int count_consonants(char* input){
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++){
        if (tolower(input[i]) != 'a'
         && tolower(input[i]) != 'e' 
         && tolower(input[i]) != 'i' 
         && tolower(input[i]) != 'o' 
         && tolower(input[i]) != 'u')
            count++;
    }
    return count;
}