// q5 - showcasing the conditional (ternary) operator

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
    char ch;
    char *type;

    ch = getchar();

    type = isdigit(ch) ? "digit" : "non-digit";
    printf("'%c' is a %s\n", ch, type);

    return EXIT_SUCCESS;
}

/* 
    Conditional Operator Syntax:
    condition ? value_if_true : value_if_false;

    Compare the with the if-else version:
    if (isdigit(ch)) {
        type = "digit";
    } else {
        type = "non-digit";
    }
*/
