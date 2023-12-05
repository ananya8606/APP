#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void addEdge(int vertices, int adjMatrix[vertices][vertices], int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
}

void BFS(int vertices, int adjMatrix[vertices][vertices], int source) {
    printf("BFS Traversal starting from node %d:\n", source);

    bool visited[MAX_VERTICES] = { false };
    int predecessors[MAX_VERTICES] = { -1 };
    int pathLength[MAX_VERTICES] = { 0 };

    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    queue[++rear] = source;
    visited[source] = true;

    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
                predecessors[i] = current;
                pathLength[i] = pathLength[current] + 1;
            }
        }
    }

    printf("\nPredecessors in BFS tree:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("Node %d: %d\n", i, predecessors[i]);
    }

    printf("Path Length from source in BFS tree:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("Node %d: %d\n", i, pathLength[i]);
    }
}

void DFSUtil(int vertices, int adjMatrix[vertices][vertices], int vertex, bool visited[], int predecessors[], int discoveryTime[], int finishTime[], int* time) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; ++i) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            predecessors[i] = vertex;
            (*time)++;
            discoveryTime[i] = *time;
            DFSUtil(vertices, adjMatrix, i, visited, predecessors, discoveryTime, finishTime, time);
        }
    }

    (*time)++;
    finishTime[vertex] = *time;
}

void DFS(int vertices, int adjMatrix[vertices][vertices], int source) {
    printf("\nDFS Traversal starting from node %d:\n", source);

    bool visited[MAX_VERTICES] = { false };
    int predecessors[MAX_VERTICES] = { -1 };
    int discoveryTime[MAX_VERTICES] = { 0 };
    int finishTime[MAX_VERTICES] = { 0 };
    int time = 0;

    DFSUtil(vertices, adjMatrix, source, visited, predecessors, discoveryTime, finishTime, &time);

    printf("\nPredecessors in DFS tree:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("Node %d: %d\n", i, predecessors[i]);
    }

    printf("Discovery Time in DFS tree:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("Node %d: %d\n", i, discoveryTime[i]);
    }

    printf("Finish Time in DFS tree:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("Node %d: %d\n", i, finishTime[i]);
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

    int source;
    printf("Enter the source node for traversal: ");
    scanf("%d", &source);

    BFS(vertices, adjMatrix, source);
    DFS(vertices, adjMatrix, source);

    return 0;
}
