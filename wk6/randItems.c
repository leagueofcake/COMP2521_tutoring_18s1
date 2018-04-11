#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item.h"

#define SEQ_PAIRS 1     // Number of pairs of sequences to generate
#define MAX_NUM 1000    // Largest number generated as a key

int main () {
    // Initialise pseudo-RNG
    srand(time(NULL));
    int r = rand();

    // Open outFile for writing
    char *outFile = "inFile";
    FILE *outf = fopen(outFile, "w");

    Item itArr1[NUM_ITEMS];
    Item itArr2[NUM_ITEMS];

    int seqPair;
    for (seqPair = 0; seqPair < SEQ_PAIRS; seqPair++) {
        // Write NUM_ITEMS items to file
        int i;
        for (i = 0; i < NUM_ITEMS; i++) {
            Item it1 = (Item) {rand() % MAX_NUM, rand() % MAX_NUM};
            Item it2 = (Item) {rand() % MAX_NUM, rand() % MAX_NUM};
            itArr1[i] = it1;
            itArr2[i] = it2;
        }

        // Write to outf
        fwrite(&itArr1, sizeof(Item), NUM_ITEMS, outf);
        fwrite(&itArr2, sizeof(Item), NUM_ITEMS, outf);
    }

    return EXIT_SUCCESS;
}
