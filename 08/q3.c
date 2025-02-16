#include <stdio.h>

int main (int argc, char *argv[]) {

    // check the right  number of cmd line args
    if (argc != 2) {
        fprintf(stderr, "Usage: ./q3 <filename>\n");
        return 1;
    }

    // try to open the file
    FILE *fp = fopen(argv[1], "w");

    // handle errors opening the file
    if (fp == NULL) {
        perror(argv[1]);
        return 1;
    }

    // Print the first line
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        putc(c, fp);

        // Break out of loop at end of line
        if (c == '\n') {
            break;
        }
    }

    // Close the file!
    fclose(fp);

    return 0;

}