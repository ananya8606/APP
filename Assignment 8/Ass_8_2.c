#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void addEdge(int vertices, int adjMatrix[vertices][vertices], int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
}

void DFS(int vertices, int adjMatrix[vertices][vertices], int vertex, bool visited[], int currentSet[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int neighbor = 1; neighbor <= vertices; ++neighbor) {
        if (adjMatrix[vertex][neighbor] == 1 && !visited[neighbor]) {
            currentSet[neighbor] = currentSet[vertex];
            DFS(vertices, adjMatrix, neighbor, visited, currentSet);
        }
    }
}

void findDisjointSets(int vertices, int adjMatrix[vertices][vertices]) {
    bool visited[MAX_VERTICES] = { false };
    int currentSet[MAX_VERTICES] = { 0 };

    int setNumber = 1;

    for (int i = 1; i <= vertices; ++i) {
        if (!visited[i]) {
            printf("Set %d: ", setNumber++);
            currentSet[i] = i;
            DFS(vertices, adjMatrix, i, visited, currentSet);
            printf("\n");
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(vertices, adjMatrix, src, dest);
    }

    findDisjointSets(vertices, adjMatrix);

    return 0;
}
