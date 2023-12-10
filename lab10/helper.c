#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *_southernize(FILE *infile,long int start_pos,long int end_pos){
    FILE *cur_pos = infile;
    if (start_pos >= end_pos) {
        fprintf(stderr, "Invalid start and end positions.\n");
        return NULL;
    }

    long length = end_pos - start_pos;
    char *buffer = malloc(length + 1); // +1 for null terminator
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }

    fseek(infile, start_pos, SEEK_SET);
    if (fread(buffer, 1, length, infile) != length) {
        fprintf(stderr, "Failed to read the file.\n");
        free(buffer);
        return NULL;
    }
    buffer[length] = '\0'; // Null-terminate the string
    fseek(infile, end_pos, SEEK_SET);
    return buffer;
}

void print_queue(char* queue,int char_iter){
    for (int i = 0; i < 4; i++)
        printf("%c",queue[(char_iter - 4 + i) % 4]);
    printf("\n");
}

int is_diaglogue(char cur_char){
    return (cur_char == '"');
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

int is_yah(char* queue,int char_iter){
    // print_queue(queue,char_iter);
    return (tolower(queue[char_iter % 4] == 's' || tolower(queue[char_iter % 4]) == ' ') || tolower(queue[char_iter % 4]) == '.')
        && (tolower(queue[(char_iter - 1) % 4]) == 'r')// || tolower(queue[(char_iter - 1) % 4]) == 'h')
        && ((tolower(queue[(char_iter - 3) % 4]) == 'e' && tolower(queue[(char_iter - 2) % 4]) == 'e') || tolower(queue[(char_iter - 2) % 4]) == 'i');
}

int is_wah(char *queue,int char_iter){
    return (tolower(queue[char_iter % 4] == 's' || tolower(queue[char_iter % 4]) == ' ') || tolower(queue[char_iter % 4]) == '.')
        && (tolower(queue[(char_iter - 1) % 4]) == 'r')// || tolower(queue[(char_iter - 1) % 4]) == 'h')
        && tolower(queue[(char_iter - 3) % 4]) == 'o' 
        && tolower(queue[(char_iter - 2) % 4]) == 'o';
}

void southernize(FILE* infile,FILE* outfile){
    int end = -1,char_iter = 0;
    char queue[4] = {0}; 
    queue[char_iter++ % 4] = fgetc(infile);
    while ((queue[char_iter % 4] = fgetc(infile)) != EOF){
        end += (int)is_diaglogue(queue[char_iter % 4]);
        if (!(end % 2) && is_very(queue,char_iter)){
            fseek(outfile,-3,SEEK_CUR);
            fputs("wicked ",outfile);
            queue[char_iter++ % 4] = fgetc(infile);
            continue;
        }
        if (!(end % 2) && is_yah(queue,char_iter)){
            fseek(outfile,-1,SEEK_CUR);
            fputs("yah",outfile);
        }
        if (!(end % 2) && is_wah(queue,char_iter)){
            fseek(outfile,-1,SEEK_CUR);
            fputs("wah",outfile);
        }
        if (!(end % 2) && is_vowel(queue[(char_iter - 1) % 4]) && tolower(queue[char_iter % 4]) == 'r')
            queue[char_iter % 4] = 'h';
        if (!(end % 2) &&  queue[char_iter % 4] == ' ' && tolower(queue[(char_iter - 1) % 4]) == 'a')
            fputc('r',outfile);

        // if (end > 80)
        //     break;
        fputc(queue[char_iter % 4], outfile);
        char_iter++;
    }
}