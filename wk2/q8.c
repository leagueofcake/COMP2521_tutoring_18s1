// q8 - Linked List Sum - 3 versions (while/for/recursive)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _Node {
    int value;
    struct _Node *next;
} Node;

typedef Node *List;

// While loop version
int listSumWhile (List l) {
    int sum = 0;
    Node *curr = l;

    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }
    return sum;
}

// For loop version
int listSumFor (List l) {
    int sum = 0;
    Node *curr;
    for (curr = l; curr != NULL; curr = curr->next) {
        sum += curr->value;
    }
    return sum;
}

// Recursive version
int listSumRecursive (List l) {
    if (l == NULL) return 0;

    return l->value + listSumRecursive(l->next);
}
















// Linked List helper functions
// Initialise new List with given value
List newNode (int value) {
    List new = malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;
    return new;
}

// Free linked list and all children
void freeList (List l) {
    List curr = l;
    while (curr != NULL) {
        List temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main (int argc, char *argv[]) {
    List head = newNode(1), n1 = newNode(2), n2 = newNode(3),
         n3   = newNode(4), n4 = newNode(7), n5 = newNode(11);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    assert(listSumWhile(head) == 28);
    assert(listSumFor(head) == 28);
    assert(listSumRecursive(head) == 28);

    assert(listSumWhile(n1) == 27);
    assert(listSumFor(n1) == 27);
    assert(listSumRecursive(n1) == 27);

    assert(listSumWhile(n2) == 25);
    assert(listSumFor(n2) == 25);
    assert(listSumRecursive(n2) == 25);

    assert(listSumWhile(n3) == 22);
    assert(listSumFor(n3) == 22);
    assert(listSumRecursive(n3) == 22);

    assert(listSumWhile(n4) == 18);
    assert(listSumFor(n4) == 18);
    assert(listSumRecursive(n4) == 18);

    printf("All test cases passed!\n");
    return EXIT_SUCCESS;
}
