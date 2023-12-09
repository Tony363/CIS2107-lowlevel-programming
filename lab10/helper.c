#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_diaglogue(char cur_char){
    // printf("%c",cur_char);
    return (cur_char == '"');
}



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
    // char cur_char = '\0';
    // while (ftell(infile) < end_pos){
    //     cur_char = fgetc(infile);
    //     if (cur_char == '\n')
    //         continue;
    //     printf("%c",cur_char);
        
    //     buffer[ftell(infile)-start_pos] = cur_char;
    // }
    if (fread(buffer, 1, length, infile) != length) {
        fprintf(stderr, "Failed to read the file.\n");
        free(buffer);
        return NULL;
    }
    buffer[length] = '\0'; // Null-terminate the string
    fseek(infile, end_pos, SEEK_SET);
    return buffer;
}

int is_vowel(char ch){
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void southernize(FILE *infile,FILE *outfile){
    int end = -1;
    long int start_pos = 0,end_pos = 0;
    char window[4] = {0};
    char *buffer = NULL;
    while ((window[3] = fgetc(infile)) != EOF){
        end += (int)is_diaglogue(window[1]);
        if (!(end % 2) && s_vowel(window[0]) && tolower(window[1]) == 'r')
            window[1] = 'h';
        if (!(end % 2) &&  window[2] == ' ' && tolower(window[1]) == 'a')
            fputc('r',outfile);
        // if (!start_pos && (end % 2) == 0)
        //     start_pos = ftell(infile);
        
        // if (start_pos && (end % 2) == 1){
        //     end_pos = ftell(infile);
        //     buffer = _southernize(infile,start_pos-10,end_pos);
        //     puts(buffer);
        //     start_pos = end_pos = 0;
        // }
        if (end > 10)
            break;
        window[0] = window[1];  
        window[1] = window[2];
        window[2] = window[3];
        fputc(window[2], outfile);
    }
    fputc(window[2], outfile);
}