#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "southern.h"

int main(int argc, char **argv){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "rb"),*outfile = fopen("southie_sherlock.txt", "wb");
    if (infile == NULL) {
        perror("Error opening file");
        return 1;
    }
    southernize(infile,outfile);
    fclose(infile);
    fclose(outfile);
    return 0;
}