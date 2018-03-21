// q7 - Fibonacci number calculator
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CACHE_SIZE 100

// Inefficient recursive version
int fib_inefficient (int n) {
    assert(n > 0);
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fib_inefficient(n-1) + fib_inefficient(n-2);
}

// Memoised version - stores computed results in an array
int *cache;     // Array to store cached values

int fibR(int n) {
    int fib1, fib2;

    if (n == 1 || n == 2) return 1;

    if (cache[n-1] == 0)  // Haven't cached fib(n-1)
        cache[n-1] = fibR(n-1);

    if (cache[n-2] == 0) // Haven't cached fib(n-2)
        cache[n-2] = fibR(n-2);

    return cache[n-1] + cache[n-2];
}

int fib (int n) {
    assert(n > 0);
    cache = calloc(n + 1, sizeof(int)); // Allocate and zero out cache
    assert(cache != NULL);              // Check malloc succeeded
    cache[1] = 1;
    cache[2] = 1;

    int result = fibR(n);
    free(cache);
    return result;
}

int main() {
    int i;

    for (i = 1; i < 10; i++) {
        printf("fib(%d): %d\n", i, fib(i));
    }

    return EXIT_SUCCESS;
}
