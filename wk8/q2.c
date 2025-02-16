#include <stdio.h>

int main (int argc, char *argv[]) {

    // check the right  number of cmd line args
    if (argc != 2) {
        fprintf(stderr, "Usage: ./q2 <filename>\n");
        return 1;
    }

    // try to open the file
    FILE *fp = fopen(argv[1], "r");

    // handle errors opening the file
    if (fp == NULL) {
        perror(argv[1]);
        return 1;
    }

    // Print the first line
    int c;
    while ((c = fgetc(fp)) != EOF) {
        putc(c, stdout);

        // Break out of loop at end of line
        if (c == '\n') {
            break;
        }
    }

    // Close the file!
    fclose(fp);

    return 0;

}