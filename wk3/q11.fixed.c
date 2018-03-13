// q11
// Read lines of text from stdin; display them in reverse order
// Assumes no more than 1000 lines; lines longer than 100 are truncated
 
#include <stdlib.h>
#include <stdio.h>
 
int main (int argc, char *argv[]) {
    int  n=0;           // counter/index
    char *thisline = calloc(100, sizeof(char)); // current line
    char *lines[1000];  // array of lines
 
    // read lines into array of strings
    while (fgets(thisline,100,stdin) != NULL) {
        lines[n++] = thisline;
        thisline = calloc(100, sizeof(char));
    }
 
    // print lines in reverse order
    while (n-- > 0) {
        fputs(lines[n],stdout);
        free(lines[n]);
    }
 
    return EXIT_SUCCESS;
}
