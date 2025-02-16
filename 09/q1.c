// print out what's in ~/.diary
#include <stdio.h>
#include <stdlib.h>
#define MAX_PATH_LEN 512

int main (int argc, char *argv[]) {
    // Get the $HOME environment variable
    char *home = getenv("HOME");

    // Construct a pathname as $HOME + /.diary
    char filename[MAX_PATH_LEN];
    snprintf(filename, MAX_PATH_LEN, "%s/.diary", home);

    // Open the diary file
    FILE *fp = fopen(filename, "r");

    // Handle Errors
    if (fp == NULL) {
        perror(filename);
        exit(1);
    }

    // Print the file to stdout
    int c;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
    }

    // Close the file
    fclose(fp);

    return 0;
}