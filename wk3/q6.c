#include <stdio.h>

typedef unsigned int Word;
// which on most systems could more accurately defined as 
// typedef uint32_t Word;

void showBits (Word w) {
    int i;
    Word mask, bit;
    mask = 1 << 31;
    for (i = 31; i >= 0; i--) {
        bit = (w & mask) >> i;
        printf("%d", bit);
        mask = (mask >> 1);
    }
    printf("\n");
}

int main () {
    Word w = 0xFFFF;
    showBits(w);
    return 0;
}
