// Alternate version of q2 using if/else

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    char ch = 'u';

    // S1 - simulate break after each case
    printf("S1 output:\n");
    if (ch == 'a') {
        printf("eh? ");
    } else if (ch == 'e') {
        printf("eee ");
    } else if (ch == 'i') {
        printf("eye ");
    } else if (ch == 'o') {
        printf("ohh ");
    } else if (ch == 'u') {
        printf("you ");
    }

    printf("\n");

    // S2 - simulate no break statements
    printf("S2 output:\n");
    if (ch == 'a') {
        printf("eh? ");
        printf("eee ");
        printf("eye ");
        printf("ohh ");
        printf("you ");
    } else if (ch == 'e') {
        printf("eee ");
        printf("eye ");
        printf("ohh ");
        printf("you ");
    } else if (ch == 'i') {
        printf("eye ");
        printf("ohh ");
        printf("you ");
    } else if (ch == 'o') {
        printf("ohh ");
        printf("you ");
    } else if (ch == 'u') {
        printf("you ");
    }

    printf("\n");
    return EXIT_SUCCESS;
}
