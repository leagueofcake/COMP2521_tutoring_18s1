#define NUM_ITEMS 8

typedef struct {
    int key;
    int value;
} Item;

int less(Item it1, Item it2) {
    return (it1.key < it2.key);
}
