// search for substring in input

// if 1 arg: search stdin

// if 2+ args: search those files

// 1st arg is substring to look for

// print with line numbers

// handle errors

// strstr is useful apparently

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

void search_stream(FILE *fp, char *substring);

int main (int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Usage: ./q5 <substring> [filenames]+\n");
        return 1;
    } else if (argc == 2) {
        // Search stdin
        search_stream(stdin, argv[1]);
    } else {
        for (int i = 2; i < argc; i++) {
            // Attempt to open the file
            FILE *fp = fopen(argv[i], "r");

            // Handle errors
            if (fp == NULL) {
                perror(argv[i]);
                return 1;
            }

            // Print file name and search
            printf("\t%s\n", argv[i]);
            search_stream(fp, argv[1]);

            fclose(fp);
        }
    }

    return 0;
}

void search_stream(FILE *fp, char *substring) {
    char buffer[MAX_SIZE];
    int i = 1;

    // Read lines from fp until end of file
    while (fgets(buffer, MAX_SIZE, fp) != NULL) {
        // If strstr != NULL, we found substring
        if (strstr(buffer, substring) != NULL) {
            printf("%d: %s", i, buffer);
        }
        i++;
    }

}