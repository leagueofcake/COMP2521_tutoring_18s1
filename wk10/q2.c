// q2.c - calculate maximum branch length of a binary tree
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTree;

typedef struct BSTNode {
   int  value;
   BSTree left, right;
} BSTNode;

int max (int a, int b) {
    return (a > b) ? a : b;
}

int maxBranchLen(BSTree t) {
    if (t == NULL) { // Base case - empty tree
        return 0;
    } else if (t->left == NULL && t->right == NULL) { // Base case - no children
        return 0;
    } else { // Recursive case
        return 1 + max(maxBranchLen(t->left), maxBranchLen(t->right));
    }
}
