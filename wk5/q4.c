typedef Link List;

typedef struct Node *List;
struct Node { int value; List next; };

// Recursively make a new copy of the list
List copy (List ls) {
    if (ls == NULL) { // Empty list
        return NULL;
    } else {
        Node *new = malloc(sizeof(Node));

        // Check malloc succeeded
        assert(new != NULL); 
        new->value = ls->value;
        new->next = copy(ls->next); // Recursively copy ls->next

        return new;
    }
}

List selectionSort(List ls) {
    if (ls == NULL) return NULL; // Empty list

    List old = copy(ls);
    List res = NULL;  // Pointer to result (sorted list)

    Link cur, max, prev;

    while (old != NULL) {
        // Find largest element
        max = cur = old;
        while (cur != NULL) {
            if (cur->value > max->value) {
                max = cur;
            }
            cur = cur->next;
        }

        // find previous node for max element
        prev = NULL; cur = old;
        while (cur != max) {
            prev = curr;
            curr = cur->next;
        }

        // unlink max from old list
        if (prev == NULL) { // max was first element
            old = max->next;
        } else {
            prev->next = max->next;
        }

        // push max at start of result list
        max->next = res;
        res = max;
    }
    return res;
}
