// q2 - Recursive list removal function
#include "List.h"

void drop (List L) {
    if (!empty(L)) {
        drop(tail(L));
        free(L);
    }
}
