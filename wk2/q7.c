// q7 - Function to check whether elements in an array occur in ascending order.
// Duplicates allowed in the array as long as they are adjacent. 
// 
// Precondition:
// - a[] is a valid pointer to the start of an array of ints
// - n is a positive int indicating how many elements in a[]
// Postcondition:
// - return value = ∀ i ∈ {0..n-2} ( a[i] ≤ a[i+1] )

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

// 1511 version using while, and macros for TRUE/FALSE
int isSorted1511 (int *a, int n) {
    int sorted = TRUE; 
    int i = 0;
    while (i < n - 1 && sorted) {
        if (a[i] > a[i+1]) {
            sorted = FALSE;
        }
        i++;
    }
    return sorted;
}

// Alternative version using for, early exit (return) and stdbool.h
bool isSortedFor (int *a, int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

int main (int argc, char *argv[]) {
    int a[5] = {1, 2, 3, 4, 5};    
    assert(isSorted1511(a, 5));
    assert(isSortedFor(a, 5));

    int b[3] = {1, 1, 1};
    assert(isSorted1511(b, 3));
    assert(isSortedFor(b, 3));

    int c[8] = {1, 2, 2, 5, 7, 8, 8, 9};
    assert(isSorted1511(c, 8));
    assert(isSortedFor(c, 8));

    int d[1] = {1};
    assert(isSorted1511(d, 1));
    assert(isSortedFor(d, 1));

    int e[5] = {1, 2, 3, 2, 1};
    assert(!isSorted1511(d, 5));
    assert(!isSortedFor(d, 5));

    int f[7] = {10, 5, 2, 9, 3, 7, 1};
    assert(!isSorted1511(d, 7));
    assert(!isSortedFor(d, 7));

    printf("All test cases passed!\n");
    return EXIT_SUCCESS;
}
