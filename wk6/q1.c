// q1 - External file merge
#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
 
void fileMerge(char *inFile, char *outFile, int runLength, int N);

int main () {
    fileMerge("inFile", "outFile", NUM_ITEMS, NUM_ITEMS * 2);

    return EXIT_SUCCESS;
}
 
// N gives the number of Items in the file
// runLength gives the number of Items in each sorted subsequence
void fileMerge(char *inFile, char *outFile, int runLength, int N) {
    FILE *inf1 = fopen(inFile, "r");    // Open inFile for reading
    FILE *inf2 = fopen(inFile, "r");    // Open inFile for reading
    FILE *outf = fopen(outFile, "w");   // Open outFile for writing

    Item it1, it2;

    // Offsets, in bytes
    long in1 = 0;
    long in2 = runLength*sizeof(Item);
    long end1, end2;
 
    while (in1 < N*sizeof(Item)) {
        // End of each subsequence, in bytes
        end1 = in1 + (runLength*sizeof(Item));
        end2 = in2 + (runLength*sizeof(Item));

        // Initialise inf1 and inf2's positions and read data into it1/it2
        fseek(inf1, in1, SEEK_SET);
        fread(&it1, sizeof(Item), 1, inf1);
        fseek(inf2, in2, SEEK_SET);
        fread(&it2, sizeof(Item), 1, inf2);

        while (in1 < end1 && in2 < end2) {  // While both sequences have elements
            if (less(it1, it2)) {   // it1 < it2, output it1
                fwrite(&it1, sizeof(Item), 1, outf);
                fread(&it1, sizeof(Item), 1, inf1);
                in1 += sizeof(Item);
            } else {                // it1 >= it2, output it2
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

    // Close each FILE pointer
    fclose(inf1);
    fclose(inf2);
    fclose(outf);
}
