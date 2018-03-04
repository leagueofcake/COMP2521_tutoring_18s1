// q15 - Array search algorithm

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Original search algorithm
int search (int val, int a[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (a[i] == val) break;
    }
    return (i == N) ? -1 : i;
}

// Alternative in 1511 style
int search1511 (int val, int a[], int N) {
    int i = 0;
    int location = -1;

    while (i < N && location == -1) {
        if (a[i] == val) {
            location = i;
        }
        i++;
    }

    return location;
}

int main (int argc, char *argv[]) {
    int a[5] = {0, 1, 1, 3, 4};
    assert(search(0, a, 5) == 0);
    assert(search(1, a, 5) == 1);
    assert(search(3, a, 5) == 3);
    assert(search(4, a, 5) == 4);
    assert(search(5, a, 5) == -1);
    assert(search(12, a, 5) == -1);

    assert(search1511(0, a, 5) == 0);
    assert(search1511(1, a, 5) == 1);
    assert(search1511(3, a, 5) == 3);
    assert(search1511(4, a, 5) == 4);
    assert(search1511(5, a, 5) == -1);
    assert(search1511(12, a, 5) == -1);

    printf("All test cases passed!\n");

    return EXIT_SUCCESS;
}
