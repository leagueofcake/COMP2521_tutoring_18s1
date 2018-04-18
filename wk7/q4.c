// q4.c - Return all edges in a Graph
// Called as follows: 
// Edges *es; int n; es = edges(g, &n)

// Adjacency matrix ver.
Edges *edgesAdjMatrix(Graph g, int *nE) {
    // Allocate array to store Edges
    Edge *result = malloc(g->nE * sizeof(Edge));

    int n = 0; // Count of edges found
    int v, w;  // Start and end vertices
    for (v = 0; v < g->nV; v++) {
        for (w = v + 1; w < g->nV; w++) {
            if (g->edges[v][w]) {
                result[n++] = mkEdge(v, w);
            }
        }
    }

    *nE = n;

    return result;
}

// Adjacency list ver.
Edges *edgesAdjList(Graph g, int *nE) {
    // Allocate array to store Edges
    Edge *result = malloc(g->nE * sizeof(Edge));

    int n = 0; // Count of edges found;
    int v;     // Start vertex
    for (v = 0; v < g->nV; v++) {
        vNode *c;
        for (c = g->edges[v]; c != NULL; c = c->next) {
            w = c->v;
            if (w >= v) { // Prevent duplicates by enforcing w >= v
                result[n++] = mkEdge(v, w);
            }
        }
    }

    *nE = n;

    return result;
}
