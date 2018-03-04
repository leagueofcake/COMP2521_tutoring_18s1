// q6 - equivalent while/for loops

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    char ch;

    // While-loop version
    ch = getchar();
    while (ch != EOF) {
        putchar(ch);
        ch = getchar();
    }

    /* An even more concise version
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
    */

    return EXIT_SUCCESS;
}


/*
    For loop syntax:
    for (initialisation; condition; update;) {
        // Do stuff
    }

    Compare the with the if-else version:
    for (ch = getchar(); ch != EOF; ch = getchar()) {
        putchar(ch);
    }
*/

