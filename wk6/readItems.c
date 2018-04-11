#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"

int main (int argc, char* argv[]) {
    char *inFile = "outFile";
    if (argc > 1) { // Use argv[1] as inFile if provided
        inFile = argv[1];
    }

    FILE *inf = fopen(inFile, "r");
    if (inf == NULL) { // Failed to open file
        fprintf(stderr, "Error opening %s\n", inFile);
        return EXIT_FAILURE;
    }

    // printf("Key\tValue\n");
    Item it;
    while (fread(&it, sizeof(Item), 1, inf) != 0) {
        printf("%d\t%d\n", it.key, it.value);
    }

    return EXIT_SUCCESS;
}
