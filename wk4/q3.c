// q3 - Recursive list copy function
#include "List.h"

List copy (List L) {
    if (empty(L)) return NULL;

    List new = newNode(head(L));
    tail(new) = copy(tail(L));
    return new;
}
