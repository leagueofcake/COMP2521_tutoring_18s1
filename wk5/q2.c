#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

// Item struct - a (key), b (value)
typedef struct { int a; int b; } Item;

// Slow/fast pointer approach - O(n^2) algorithm
// Fast pointer iterates through original array
// Slow pointer iterates through each key in the sorted array, incrementing whenever
// the fast pointer finds a matching key.
// Early exits if an unstable match is found (same key, different value).
int isStableSort(Item original[], Item sorted[], int lo, int hi) {
    int slow = 0;
    while (slow < hi) {
        int oldKey = sorted[slow].a;

        // Iterate through original array using fast pointer
        for (int fast = 0; fast <= hi; fast++) {
            if (original[fast].a == sorted[slow].a) { // Matching key found
                // Value at fast pointer doesn't match slow pointer - return false
                if (original[fast].b != sorted[slow].b) return FALSE;

                // Value matches, advance slow pointer
                slow++;

                // If current key at slow pointer doesn't match oldKey, 
                // break out of inner for loop to reset fast pointer
                if (slow < hi && sorted[slow].a != oldKey) break;
            }
        }
    }
    return TRUE;
}

// Same algorithm but without the comments
int isStableSortNoAnnotations(Item original[], Item sorted[], int lo, int hi) {
    int slow = 0;
    while (slow < hi) {
        int oldKey = sorted[slow].a;

        for (int fast = 0; fast <= hi; fast++) {
            if (original[fast].a == sorted[slow].a) {
                if (original[fast].b != sorted[slow].b) return FALSE;

                slow++;

                if (slow < hi && sorted[slow].a != oldKey) break;
            }
        }
    }
    return TRUE;
}

// Test runner
int main () {
    Item orig[2], sorted[2];

    // Test case 1 - unstable sort, 2 items, various keys
    orig[0] = (Item) {0, 1};
    orig[1] = (Item) {0, 2};

    sorted[0] = (Item) {0, 2};
    sorted[1] = (Item) {0, 1};
    assert(!isStableSort(orig, sorted, 0, 1));

    // Test case 2 - stable sort, 2 items, various keys
    orig[0] = (Item) {0, 1};
    orig[1] = (Item) {0, 2};

    sorted[0] = (Item) {0, 1};
    sorted[1] = (Item) {0, 2};
    assert(isStableSort(orig, sorted, 0, 1));

    Item orig2[5], sorted2[5];
    // Test case 3 - unstable sort, 5 items, various keys
    orig2[0] = (Item) {1, 1};
    orig2[1] = (Item) {2, 0};
    orig2[2] = (Item) {0, 2};
    orig2[3] = (Item) {1, 2};
    orig2[4] = (Item) {2, 1};

    sorted2[0] = (Item) {0, 2};
    sorted2[1] = (Item) {1, 2};
    sorted2[2] = (Item) {1, 1};
    sorted2[3] = (Item) {2, 0};
    sorted2[4] = (Item) {2, 1};
    assert(!isStableSort(orig2, sorted2, 0, 4));

    // Test case 4 - stable sort, 5 items, various keys
    orig2[0] = (Item) {1, 1};
    orig2[1] = (Item) {2, 0};
    orig2[2] = (Item) {0, 2};
    orig2[3] = (Item) {1, 2};
    orig2[4] = (Item) {2, 1};

    sorted2[0] = (Item) {0, 2};
    sorted2[1] = (Item) {1, 1};
    sorted2[2] = (Item) {1, 2};
    sorted2[3] = (Item) {2, 0};
    sorted2[4] = (Item) {2, 1};
    assert(isStableSort(orig2, sorted2, 0, 4));

    // Test case 5 - unstable sort, 5 items, various keys
    orig2[0] = (Item) {0, 0};
    orig2[1] = (Item) {0, 1};
    orig2[2] = (Item) {1, 0};
    orig2[3] = (Item) {2, 0};
    orig2[4] = (Item) {2, 1};

    sorted2[0] = (Item) {0, 0};
    sorted2[1] = (Item) {0, 1};
    sorted2[2] = (Item) {1, 0};
    sorted2[3] = (Item) {2, 1};
    sorted2[4] = (Item) {2, 0};
    assert(!isStableSort(orig2, sorted2, 0, 4));

    // Test case 6 - stable sort, 5 items, various keys
    orig2[0] = (Item) {0, 0};
    orig2[1] = (Item) {0, 1};
    orig2[2] = (Item) {1, 0};
    orig2[3] = (Item) {2, 0};
    orig2[4] = (Item) {2, 1};

    sorted2[0] = (Item) {0, 0};
    sorted2[1] = (Item) {0, 1};
    sorted2[2] = (Item) {1, 0};
    sorted2[3] = (Item) {2, 0};
    sorted2[4] = (Item) {2, 1};
    assert(isStableSort(orig2, sorted2, 0, 4));

    // Test case 7 - unstable sort, 5 items, all same key
    orig2[0] = (Item) {0, 0};
    orig2[1] = (Item) {0, 1};
    orig2[2] = (Item) {0, 2};
    orig2[3] = (Item) {0, 3};
    orig2[4] = (Item) {0, 4};

    sorted2[0] = (Item) {0, 1};
    sorted2[1] = (Item) {0, 0};
    sorted2[2] = (Item) {0, 2};
    sorted2[3] = (Item) {0, 3};
    sorted2[4] = (Item) {0, 4};
    assert(!isStableSort(orig2, sorted2, 0, 4));

    // Test case 8 - unstable sort, 5 items, all same key
    orig2[0] = (Item) {0, 0};
    orig2[1] = (Item) {0, 1};
    orig2[2] = (Item) {0, 2};
    orig2[3] = (Item) {0, 3};
    orig2[4] = (Item) {0, 4};

    sorted2[0] = (Item) {0, 1};
    sorted2[1] = (Item) {0, 0};
    sorted2[2] = (Item) {0, 2};
    sorted2[3] = (Item) {0, 3};
    sorted2[4] = (Item) {0, 4};

    // Test case 8 - unstable sort, 5 items, all same key
    orig2[0] = (Item) {0, 0};
    orig2[1] = (Item) {0, 1};
    orig2[2] = (Item) {0, 2};
    orig2[3] = (Item) {0, 3};
    orig2[4] = (Item) {0, 4};

    sorted2[0] = (Item) {0, 4};
    sorted2[1] = (Item) {0, 3};
    sorted2[2] = (Item) {0, 2};
    sorted2[3] = (Item) {0, 1};
    sorted2[4] = (Item) {0, 0};

    assert(!isStableSort(orig2, sorted2, 0, 4));

    // Test case 9 - stable sort, 5 items, all same key
    orig2[0] = (Item) {0, 0};
    orig2[1] = (Item) {0, 1};
    orig2[2] = (Item) {0, 2};
    orig2[3] = (Item) {0, 3};
    orig2[4] = (Item) {0, 4};

    sorted2[0] = (Item) {0, 0};
    sorted2[1] = (Item) {0, 1};
    sorted2[2] = (Item) {0, 2};
    sorted2[3] = (Item) {0, 3};
    sorted2[4] = (Item) {0, 4};
    assert(isStableSort(orig2, sorted2, 0, 4));

    // Test case 10 - stable sort, 5 items, all different keys (must be stable)
    orig2[0] = (Item) {0, 0};
    orig2[1] = (Item) {1, 1};
    orig2[2] = (Item) {2, 2};
    orig2[3] = (Item) {3, 3};
    orig2[4] = (Item) {4, 4};

    sorted2[0] = (Item) {0, 0};
    sorted2[1] = (Item) {1, 1};
    sorted2[2] = (Item) {2, 2};
    sorted2[3] = (Item) {3, 3};
    sorted2[4] = (Item) {4, 4};
    assert(isStableSort(orig2, sorted2, 0, 4));

    // Test case 11 - stable sort, 6 items, various keys
    Item orig3[6], sorted3[6];
    orig3[0] = (Item) {1, 0};
    orig3[1] = (Item) {2, 0};
    orig3[2] = (Item) {0, 0};
    orig3[3] = (Item) {1, 1};
    orig3[4] = (Item) {2, 1};
    orig3[4] = (Item) {2, 2};

    sorted3[0] = (Item) {0, 0};
    sorted3[1] = (Item) {1, 0};
    sorted3[2] = (Item) {1, 1};
    sorted3[3] = (Item) {2, 0};
    sorted3[4] = (Item) {2, 1};
    sorted3[4] = (Item) {2, 2};
    assert(isStableSort(orig3, sorted3, 0, 5));

    // Test case 12 - unstable sort, 6 items, various keys
    orig3[0] = (Item) {1, 0};
    orig3[1] = (Item) {2, 0};
    orig3[2] = (Item) {0, 0};
    orig3[3] = (Item) {1, 1};
    orig3[4] = (Item) {2, 1};
    orig3[5] = (Item) {2, 2};

    sorted3[0] = (Item) {0, 0};
    sorted3[1] = (Item) {1, 0};
    sorted3[2] = (Item) {1, 1};
    sorted3[3] = (Item) {2, 0};
    sorted3[4] = (Item) {2, 2};
    sorted3[5] = (Item) {2, 1};
    assert(!isStableSort(orig3, sorted3, 0, 5));

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}
