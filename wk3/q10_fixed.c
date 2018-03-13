// q10
// Read numbers from stdin; write sorted numbers on stdout
 
#include <stdio.h>
#include <stdlib.h>
 
int main (int argc, char *argv[]) {
    int i, n;       // i=index, n=counter
    int vec[1000];  // array of integers
    int icompare (const void *, const void *);
 
    n = 0;
    while (scanf("%d",&vec[n]) == 1)
        n++;
    qsort(vec, n, sizeof(int), icompare);
    for (i = 0; i < n; i++)
        printf("%d ",vec[i]);
    printf("\n");
    return EXIT_SUCCESS;
}
 
int icompare (const void *a, const void *b) {
    int *num1 = (int *) a;
    int *num2 = (int *) b;
    return (*num1 - *num2);
}
