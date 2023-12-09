#include <stdio.h>
#include <string.h>

int is_diaglogue(char *line){
    if (line[0] == '\"')
        return 1;
    int len = strlen(line);
    while (line[len--] != '\"')
    if (line[len] == '\"')
        return 1;
    return 0;
}


void _southernize(char *line){
    return;
}

void southernize(FILE *infile,FILE *outfile){
    char line[1024];
    int end = -1;
    while (fgets(line, 1024, infile) != NULL){
        end += is_diaglogue(line);
        if (!(end % 2))
            _southernize(line);
        fprintf(outfile, "%s\n", line);
    }
}