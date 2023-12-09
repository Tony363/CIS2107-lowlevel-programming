#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "southern.h"

int main(int argc, char **argv){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "r"),*outfile = fopen("southie_sherlock.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    southernize(infile,outfile);
    fclose(infile);
    return 0;
}