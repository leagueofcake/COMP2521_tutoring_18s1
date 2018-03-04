// q10 - Demonstrates argc, argv, stdin, stdout, stderr and exit()

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER_SIZE 10

int main (int argc, char *argv[]) {
    // Print value of argc
    printf("argc: %d\n\n", argc);

    // Print contents of argv
    int i;
    for (i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // Explicitly reading in from stdin using fgets
    char buffer[BUFFER_SIZE];

    printf("Enter text: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    printf("Read in: %s\n", buffer);

    // stdout and stderr. fprintf() lets you specify an output stream.
    // Run the following and check the differences
    // ./q10 >  out_stdout
    // ./q10 2> out_stderr
    // ./q10 >  out_stdout_stderr 2>&1
    printf("This goes to stdout!\n");
    fprintf(stdout, "This also goes to stdout!\n");

    fprintf(stderr, "This goes to stderr!\n");
    assert(0 && "Failed assertions messages also go to stderr!");

    // Exit with a given exit status (EXIT_FAILURE)
    // This doesn't get reached due to the failed assertion above
    exit(EXIT_FAILURE);
}
