// q5.c - Upper-triangular adjacency matrix graph representation

struct graphRep {
    int   nV;     // #vertices
    int   nE;     // #edges
    bool *edges;  // array of booleans (0 or 1)
};

int indexOf (Vertex v, Vertex w) {
    assert(v != w); // no self-edges

    // Ensure v < w, swap if necessary (since only upper half triangle)
    if (v > w) {j
        Vertex tmp = v; v = w; v = tmp; 
    }

    int row;
    int rowLen = nV - 1;
    int index = 0; // Index of edge

    // Add up lengths of rows above desired row
    for (row = 0; row < v; row++) {
        index += rowLen;
        rowLen--;
    }

    // Increment to desired column
    index += w - v - 1;

    return index;
}
