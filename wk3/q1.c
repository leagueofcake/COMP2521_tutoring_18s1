// q1 - Bag ADT
// i. Unsorted array of pre-defined size MAX_BAG

#define MAX_BAG 10
int numElems = 4;       // Count of items in bag
int numUniq = 3;

// Values appear multiple times
Bag    [2, 5, 2, 1, _, _, _, _, _, _]

// Each value appears only once, along with a count of occurrences
Bag    [2, 5, 1, _, _, _, _, _, _, _]
Counts [2, 1, 1, 0, 0, 0, 0, 0, 0, 0]       // Counters for values



// ii. Unsorted linked list

int numElems = 4;
int numUniq = 3;

// Values appear multiple times
Bag is 2 -> 5 -> 2 -> 1 -> X

// Each value appears only once, along with a count of occurrences
// Each node in form (Value, Count)
Bag is (2, 2) -> (5, 1) -> (1, 1) -> X


// b. Algorithms on Bag ADT
// Array, values appear multiple times
BagInsert(Bag, Int) {
    Check that max capacity hasn't been reached             // O(1)
    Insert at the next available slot in the array          // O(1)
    Increment numElems                                      // O(1)
    if (value isn't already in array) Increment numUniq     // O(n)
}
Overall: O(n)

BagMember(Bag, Int) {
    count = 0                                               // O(1)
    for each element in the array:                          // O(n)
        if (element == value) Increment count               // O(1)
    return count                                            // O(1)
}
Overall: O(n)

// Array, values appear once with a count of occurrences
BagInsert(Bag, Int) {
    index = -1
    for i = 0 to numElems - 1:                              // O(n)
        if (array[i] == value):                             // O(1)
            index = -1                                      // O(1)
            break

    if (index != -1):                                       // O(1)
        Increment counts[index]                             // O(1)
    else:
        Insert at next available slot in the array          // O(1)
        Set counts[index] to 1                              // O(1)
        Incremnt numUniq                                    // O(1)

    Increment numElems                                      // O(1)
}
Overall: O(n)

BagMember(Bag, Int) {
    for i = 0 to numElems - 1:                              // O(n)
        if (array[i] == value) return counts[i]             // O(1)
    return 0                                                // O(1)
}
Overall: O(n)

// List, values appear multiple times
BagInsert(Bag, Int) {
    Insert new node for element at end of list              // O(1)
    Increment numElems                                      // O(1)
    if (value isn't already in list): Increment numUniq     // O(n)
}
Overall: O(n)

BagMember(Bag, Int) {
    counter = 0                                             // O(1)
    for each node in list:                                  // O(n)
        if (node.value == value) Increment counter          // O(1)
    return counter                                          // O(1)
}
Overall: O(n)

// List, values appear once with a count of occurrences
BagInsert(Bag, Int) {
    found = FALSE                                           // O(1)
    for node in list:                                       // O(n)
        if (node.value == value):                           // O(1)
            Increment node.count                            // O(1)
            found = TRUE                                    // O(1)

    if (!found):                                            // O(1)
        Insert new node at end of list                      // O(1)
        Increment numUniq                                   // O(1)
    Increment numELems                                      // O(1)
}
Overall: O(n)

BagMember(Bag, Int) {
    for node in list:                                       // O(n)
        if (node.value == value):                           // O(1)
            return node.count                               // O(1)
    return 0                                                // O(1)
}
Overall: O(n)

// NumElems and NumUniq
BagNumElems(Bag) {
    return numElems;                                        // O(1)
}
Overall: O(1)

BagNumUniq(Bag) {
    return numUniq;                                         // O(1)
}
Overall: O(1)
