#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];

struct Graph {
    int vertices;
    int edges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

int isBSTUtil(struct Graph* graph, int vertex, int min, int max) {
    if (graph == NULL || vertex < 0 || vertex >= graph->vertices) {
        return 1; // Invalid input, considered as a BST
    }

    if (visited[vertex]) {
        return 1; // Already visited, considered as a BST
    }

    visited[vertex] = 1;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i]) {
            if (i < min || i > max) {
                return 0; // Violates BST property
            }

            if (!isBSTUtil(graph, i, min, vertex - 1) || !isBSTUtil(graph, i, vertex + 1, max)) {
                return 0;
            }
        }
    }

    return 1; // Graph is a BST
}

int isBST(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }

    return isBSTUtil(graph, 0, 0, graph->vertices - 1);
}

int isAVL(struct Graph* graph, int root, int* height) {
    if (graph == NULL || root < 0 || root >= graph->vertices) {
        *height = 0;
        return 1; // Invalid input, considered as AVL
    }

    int leftHeight = 0, rightHeight = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[root][i]) {
            int subtreeHeight;
            if (!isAVL(graph, i, &subtreeHeight)) {
                return 0; // Subtree is not AVL
            }

            if (i < root) {
                leftHeight = subtreeHeight + 1;
            } else {
                rightHeight = subtreeHeight + 1;
            }
        }
    }

    *height = (leftHeight > rightHeight) ? leftHeight : rightHeight;

    return abs(leftHeight - rightHeight) <= 1;
}

int main() {
    struct Graph myGraph;
    myGraph.vertices = 7;
    myGraph.edges = 6;
    // Assuming an undirected graph, edges are represented in the adjacency matrix
    int edges[][2] = {{12, 8}, {8, 5}, {5, 4},{8,11},{12,18},{18,17}};
    for (int i = 0; i < myGraph.edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        myGraph.adjacencyMatrix[u][v] = myGraph.adjacencyMatrix[v][u] = 1;
    }

    if (isBST(&myGraph)) {
        printf("The graph is a BST.\n");

        int height;
        if (isAVL(&myGraph, 0, &height)) {
            printf("The graph is AVL.\n");
        } else {
            printf("The graph is not AVL.\n");
        }
    } else {
        printf("The graph is not a BST.\n");
    }

    return 0;
}
