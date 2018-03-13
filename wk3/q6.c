typedef unsigned int Word;
// which on most systems could more accurately defined as 
// typedef uint32_t Word;

void showBits (Word w) {
    int i;
    Word mask, bit;
    for (i = 31; i >= 0; i--) {
        bit = (w & mask) >> i;
        printf("%d", bit);
        mask = (mask >> 1);
    }
}
