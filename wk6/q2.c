/ q2 - External file merge - updated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Item.h"
 
void fileMerge(FILE *inf, FILE *outf, int runLength, int N);
int copy(FILE *in, FILE *out);

int main () {
    // make temp files (unique names, open for read/write)
    char templateA[] = "/tmp/mrg.XXXXXX";
    char templateB[] = "/tmp/mrg.XXXXXX";
    FILE *A = fopen(mktemp(templateA),"w+");
    FILE *B = fopen(mktemp(templateB),"w+");

    if (A == NULL || B == NULL) {
        fprintf(stderr, "Cannot make sort temp files\n");
        exit(EXIT_FAILURE);
    }

    // copy stdin file to A, Item by Item
    int N = copy(stdin, A);

    // run mergesort algorithm
    FILE *inFile, *outFile;
    int runLength = 1;
    int iter = 0;
    while (runLength < N) {
        if (iter % 2 == 0) {
            inFile = A; outFile = B;
        }
        else {
            inFile = B; outFile = A;
        }
        fileMerge(inFile, outFile, runLength, N);
        iter++;
        runLength *= 2;

        rewind(inFile);
        rewind(outFile);
    }
    // print outfile to stdout
    rewind(outFile);
    Item it;
    while (fread(&it, sizeof(Item), 1, outFile) != 0) {
        printf("%d\t%d\n", it.key, it.value);
    }
    // copy(outFile,stdout);
    return EXIT_SUCCESS;
}
 
// N gives the number of Items in the file
// runLength gives the number of Items in each sorted subsequence
void fileMerge(FILE *inf, FILE *outf, int runLength, int N) {
    // FILE pointers for input and output files
    FILE *inf1 = inf;
    FILE *inf2 = fdopen(dup(fileno(inf)), "r");   // Duplicate inf

    Item it1, it2;

    // Offsets, in bytes
    long in1 = 0;
    long in2 = runLength*sizeof(Item);

    long end1, end2;
 
    while (in1 < N*sizeof(Item)) {
        // End of each subsequence, in bytes
        end1 = in1 + (runLength*sizeof(Item));
        end2 = in2 + (runLength*sizeof(Item));

        // Initialise inf1 and inf2's positions
        fseek(inf1, in1, SEEK_SET);
        fread(&it1, sizeof(Item), 1, inf1);
        fseek(inf2, in2, SEEK_SET);
        fread(&it2, sizeof(Item), 1, inf2);

        // While we haven't finished processing either sequence
        while (in1 < end1 && in2 < end2) {
            if (less(it1, it2)) {   // it1 < it2, merge it1
                fwrite(&it1, sizeof(Item), 1, outf);
                fread(&it1, sizeof(Item), 1, inf1);
                in1 += sizeof(Item);
            } else {                // it1 >= it2, merge it2
                fwrite(&it2, sizeof(Item), 1, outf);
                fread(&it2, sizeof(Item), 1, inf2);
                in2 += sizeof(Item);
            }
        }

        // If there are remaining items in first sequence, write them all out
        while (in1 < end1) {
            fwrite(&it1, sizeof(Item), 1, outf);
            fread(&it1, sizeof(Item), 1, inf1);
            in1 += sizeof(Item);
        }

        // If there are remaining items in second sequence, write them all out
        while (in2 < end2) {
            fwrite(&it2, sizeof(Item), 1, outf);
            fread(&it2, sizeof(Item), 1, inf2);
            in2 += sizeof(Item);
        }

        // Move in1 and in2 to the start of the next two sequences
        in1 += runLength*sizeof(Item);
        in2 += runLength*sizeof(Item);
    }

    // Close inf2 (since it was duplicated)
    fclose(inf2);
}

// Copy data from in to out. Returns number of items read.
int copy(FILE *in, FILE *out) {
    int nitems = 0;
    Item it;
    while (fread(&it, sizeof(Item), 1, in) > 0) {
        fwrite(&it, sizeof(Item), 1, out);
        nitems++;
    }
    return nitems;
}
