typedef struct BagRep *Bag;
typedef struct Node *Link;
typedef struct Node { int value; Link next; } Node;
typedef struct BagRep { Node *list; } BagRep;

// If we have access to some Set() ADT (no duplicates!)
int BagNumUniq (Bag b) {
    int count;
    Set s = newSet();

    Node *curr;
    for (curr = b->list; curr != NULL; curr = curr->next) {
        SetInsert(s, curr->value);
    }
    n = SetSize(s);
    freeSet(s);
    return n;
}

// If we don't... we can use an array to store used values
int BagNumUniq (Bag b) {
    int count = 0;

    int vals[MAX_BAG] = {0}; // Store currently seen values
    Node *curr;

    for (curr = b->list; curr != NULL; curr = curr->next) {
        // Try find value in vals
        for (i = 0; i < count; i++) {
            if (vals[i] == curr->value) break;
        }

        if (i == count) { // Didn't find value in seen values - add to vals and increment count
            vals[count] = curr->value;
            count++;
        }
    }
    return count;
}
