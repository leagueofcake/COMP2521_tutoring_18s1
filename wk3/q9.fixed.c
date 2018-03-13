// q9
// Read numbers from stdin; display them in reverse order of reading
 
#include <stdio.h>
 
int main (int argc, char *argv[]) {
    int i, n;       // i=index, n=counter
    int vec[1000];  // array of integers
 
    n = 0;
    while (scanf("%d",&vec[n]) == 1)
        n++;
    for (i = n - 1; i >= 0; i--)
        printf("%d ",vec[i]);
    printf("\n");
    return 0;
}
