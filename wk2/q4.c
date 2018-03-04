// q4 - Representing switch/case block with if/else

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
    char ch = 'a';

    // Original switch-case version
    assert(islower(ch));
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("vowel"); break;
        default:
            printf("consonant"); break;
    }
    printf("\n");

    // If-else version
    assert(islower(ch));
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        printf("vowel");
    } else {
        printf("consonant!");
    }

    printf("\n");

    return EXIT_SUCCESS;
}
