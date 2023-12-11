#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
Name: Tony Siu
Date: 12/10/2023
Course: CSI2107 
HW#: Lab 10: Southie Sherlock Holmes

compile -> gcc -I/./ -o south -g main.c helper.c
sample run -> ./south sherklock.txt
*/

int is_diaglogue(char cur_char);
int is_vowel(char ch);
int is_very(char* queue, int char_iter);
int is_word_end(char *queue,int char_iter);
int is_yah(char* queue,int char_iter);
int end_with_a(char *queue,int char_iter);
int is_wah(char *queue,int char_iter);
int vowel_r(char *queue,int char_iter);
void southernize(FILE* infile,FILE* outfile);
void print_queue(char* queue,int char_iter);


int main(int argc, char **argv){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "rb"),*outfile = fopen("southie-sherlock.txt", "wb");
    if (infile == NULL) {
        perror("Error opening file");
        return 1;
    }
    southernize(infile,outfile);
    fclose(infile);
    fclose(outfile);
    return 0;
}

void print_queue(char* queue,int char_iter){
    for (int i = 0; i < 4; i++)
        printf("%c",queue[(char_iter - 4 + i) % 4]);
    printf("\n");
}

int is_diaglogue(char cur_char){
    return cur_char == '"';
}

int is_vowel(char ch){
    ch = tolower(ch);
    return ch == 'a' 
        || ch == 'e' 
        || ch == 'i' 
        || ch == 'o' 
        || ch == 'u';
}

int is_very(char* queue, int char_iter){
    return tolower(queue[(char_iter - 3) % 4]) == 'v' 
        && tolower(queue[(char_iter - 2) % 4]) == 'e' 
        && (tolower(queue[(char_iter - 1) % 4]) == 'h' || tolower(queue[(char_iter - 1) % 4]) == 'r')
        && tolower(queue[char_iter % 4]) == 'y';
}

int is_word_end(char *queue,int char_iter){
    return tolower(queue[char_iter % 4]) == ' ' 
        || tolower(queue[char_iter % 4]) == '.'
        || tolower(queue[char_iter % 4]) == 's'
        || tolower(queue[char_iter % 4]) == ','
        || tolower(queue[char_iter % 4]) == '\n'
        || tolower(queue[char_iter % 4]) == '\t';
}

int is_yah(char* queue,int char_iter){
    return (
        (tolower(queue[(char_iter - 2) % 4]) == 'i' 
        && tolower(queue[(char_iter - 1) % 4]) == 'r'
        && is_word_end(queue,char_iter))
        ||
        (is_word_end(queue,char_iter) 
        && tolower(queue[(char_iter - 1) % 4]) == 'r' 
        && tolower(queue[(char_iter - 2) % 4]) == 'e' 
        && tolower(queue[(char_iter - 3) % 4]) == 'e')
    );
}

int end_with_a(char *queue,int char_iter){
    return queue[char_iter % 4] == ' ' 
        && tolower(queue[(char_iter - 1) % 4]) == 'a';
}

int is_wah(char *queue,int char_iter){
    return is_word_end(queue,char_iter)
        && (tolower(queue[(char_iter - 1) % 4]) == 'r')
        && tolower(queue[(char_iter - 3) % 4]) == 'o' 
        && tolower(queue[(char_iter - 2) % 4]) == 'o';
}

int vowel_r(char *queue,int char_iter){
    return is_vowel(queue[(char_iter - 2) % 4]) 
        && tolower(queue[(char_iter - 1) % 4]) == 'r';

}

void southernize(FILE* infile,FILE* outfile){
    int end = -1,char_iter = 0;
    char queue[4] = {0}; 
    queue[char_iter++ % 4] = fgetc(infile);
    while ((queue[char_iter % 4] = fgetc(infile)) != EOF){
        end += is_diaglogue(queue[char_iter % 4]);
        if (!(end % 2) && is_very(queue,char_iter)){
            fseek(outfile,-2,SEEK_CUR);
            fputs("wicked",outfile);
            queue[char_iter++ % 4] = fgetc(infile);
            continue;
        }
        if (!(end % 2) && end_with_a(queue,char_iter)){
            fputs("ar ",outfile);
            queue[char_iter++ % 4] = fgetc(infile);
            continue;
        }  
        if (!(end % 2) && is_yah(queue,char_iter)){
            fputs("yah",outfile);
            char_iter++;
            continue;
            
        }
        if (!(end % 2) && is_wah(queue,char_iter)){
            fputs("wah",outfile);
            char_iter++;
            continue;
        }
        if (!(end % 2) && vowel_r(queue,char_iter))
            queue[(char_iter - 1) % 4] = 'h';
     
        fputc(queue[(char_iter - 1) % 4], outfile);
        char_iter++;
    }
    fputc(queue[char_iter % 4], outfile);
}