// q2 - demonstrating switch statements and the use of break

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    char ch = 'u';

    // S1 - break after each case - exits switch block after executing a match
    printf("S1 output:\n");
    switch (ch) {
        case 'a': printf("eh? "); break;
        case 'e': printf("eee "); break;
        case 'i': printf("eye "); break;
        case 'o': printf("ohh "); break;
        case 'u': printf("you "); break;
    }
    printf("\n");

    // S2 - no break statements - a matched case will "fall through"
    printf("S2 output:\n");
    switch (ch) {
        case 'a': printf("eh? ");
        case 'e': printf("eee ");
        case 'i': printf("eye ");
        case 'o': printf("ohh ");
        case 'u': printf("you ");
    }
    printf("\n");
    return EXIT_SUCCESS;
}
