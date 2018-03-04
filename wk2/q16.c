// q16 - mysterious function

#include <stdlib.h>

void swap (int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void mysteriousFunction (int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int low = i;                    // n - 1 times
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[low]) {        // (n-1) + (n-2) + ... + 1 = n(n-1)/2 times
                low = j;                // up to n(n-1)/2 times
            }
        }
        swap(a, i, low);                // n - 1 times
    }
}

int main (int argc, char *argv[]) {
    int a[5] = {5, 4, 2, 1, 3};
    mysteriousFunction(a, 5); // What does this do?

    return EXIT_SUCCESS;
}
