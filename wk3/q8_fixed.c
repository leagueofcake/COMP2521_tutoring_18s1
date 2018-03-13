// q8
// Read lines from stdin; writes them to stdout
// Lines longer than 20 chars are truncated
 
#include <stdio.h>
#define MAXLINE 20
 
int main (int argc, char *argv[]) {
    int  i;              // index
    char line[MAXLINE];  // string buffer
    int  mygets(char *);
 
    // initialise line buffer
    for (i = 0; i < MAXLINE; i++) line[i] = '\0';
 
    // read and echo stdin, line by line
    while (mygets(line))
        printf("%s\n", line);
    return 0;
}
 
int mygets (char *buf) {
    int c, i = 0;  // c=input char, i=index
 
    while ((c = getchar()) != EOF) {  // stop at end of file
        if (c == '\n') break;     // stop at end of line
        if (i < MAXLINE)
            buf[i++] = c; // store in buffer if not full
    }
    if (i < MAXLINE)
        buf[i++] = '\0';
    return (c != EOF);  // returns false when reach EOF, true otherwise
}
