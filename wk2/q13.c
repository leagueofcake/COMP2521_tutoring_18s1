// q13 - Array swap function

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap (int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Also possible to write swap as a macro: 

#define swapMacro(a, i, j) {int temp = a[i]; a[i] = a[j]; a[j] = temp;}

int main (int argc, char *argv[]) {
    int a[5] = {1, 2, 3, 4, 5};
    swap(a, 2, 4);
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 5);
    assert(a[3] == 4);
    assert(a[4] == 3);

    swap(a, 1, 2);
    assert(a[0] == 1);
    assert(a[1] == 5);
    assert(a[2] == 2);
    assert(a[3] == 4);
    assert(a[4] == 3);

    swap(a, 0, 3);
    assert(a[0] == 4);
    assert(a[1] == 5);
    assert(a[2] == 2);
    assert(a[3] == 1);
    assert(a[4] == 3);

    swapMacro(a, 1, 4);
    assert(a[0] == 4);
    assert(a[1] == 3);
    assert(a[2] == 2);
    assert(a[3] == 1);
    assert(a[4] == 5);

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}
