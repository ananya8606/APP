#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < vertices; ++i) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[startVertex] = 0;

    for (int count = 0; count < vertices - 1; ++count) {
        int minDistance = INT_MAX, minIndex;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && graph[minIndex][v] && distance[minIndex] != INT_MAX &&
                distance[minIndex] + graph[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + graph[minIndex][v];
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; ++i) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges and their weights (src dest weight):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
    }

    int startVertex;
    printf("Enter the starting vertex for Dijkstra's algorithm: ");
    scanf("%d", &startVertex);

    dijkstra(graph, vertices, startVertex);

    return 0;
}
