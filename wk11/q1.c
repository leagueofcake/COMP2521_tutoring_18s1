// q1.c - BST deletion via marking nodes
#include <stdbool.h>

typedef struct BSTNode {
    bool deleted;
    int value;
    Link left, right;
}

// Need to handle nodes that are marked as deleted
bool BSTreeFind(BSTree t, int v) {
    if (t == NULL) {
        return 0;
    } else if (v < t->value) {
        return BSTreeFind(t->left, v);
    } else if (v > t->value) {
        return BSTreeFind(t->right, v);
    } else if (t->deleted) { // Equal value, but deleted
        return 0;
    } else {
        return 1;
    }
}

int BSTreeNumNodes(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        int currNodeCount = (t->deleted) ? 0 : 1;
        return currNodeCount + 
               BSTreeNumNodes(t->left) + 
               BSTreeNumNodes(t->right);
    }
}

BSTree BSTreeDelete(BSTree t, int v) {
    if (t == NULL) {
        return NULL;
    } else if (v < t->value) {
        t->left = BSTreeDelete(t->left, v);
    } else if (v > t->value) {
        t->right = BSTreeDelete(t->right, v);
    } else {
        t->deleted = true;
    }

    return t;
}

// LNR traversal
void showBSTreeInfix(BSTree t) {
    if (t == NULL) return;
    showBSTreeInfix(t->left);
    if (!t->deleted) printf("%d ", t->value);
    showBSTreeInfix(t->right);
}

BSTree BSTreeInsert(BSTree t, int v) {
    if (t == NULL) { // Empty tree
        t = newBSTNode(v);
    } else if (t->deleted && v > max(t->left) && v < min(t->right)) {
        // Current node deleted, but v "fits" in the range so we can reuse it
        t->value = v;
        t->deleted = false;
    } else if (v < t->value) { // Left subtree case
        t->left = BSTreeInsert(t->left, v);
    } else if (v > t->value) { // Right subtree case
        t->right = BSTreeInsert(t->right, v);
    } else if (t->deleted) { // t->value == v
        t->deleted = false;
    }

    return t;
}
