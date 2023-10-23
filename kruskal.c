#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to create a graph
struct Edge* createGraph(int V, int E) {
    struct Edge* graph = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find the set of an element 'i'
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Function to perform union of two sets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function to sort edges by weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm
void kruskalMST(struct Edge* graph, int V, int E) {
    struct Edge result[V]; // To store the result (MST)
    int e = 0; // An index variable to keep track of the edges added to the MST
    int i = 0; // An index variable to keep track of the sorted edges

    qsort(graph, E, sizeof(graph[0]), compareEdges); // Sort the edges by weight

    struct Subset subsets[V];

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < E) {
        struct Edge next_edge = graph[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d (Weight %d)\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge* graph = createGraph(V, E);

    printf("Enter the source, destination, and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph[i].src, &graph[i].dest, &graph[i].weight);
    }

    kruskalMST(graph, V, E);

    return 0;
}
