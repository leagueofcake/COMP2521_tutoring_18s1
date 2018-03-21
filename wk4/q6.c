#include "List.h"

int one (int x) { return 1; }
int add (int x, int y) { return x + y; }

int findLength(List l) {
    return fold(map(L, one), add, 0);
}
