#include <stdio.h>

#define MAX_VERTICES 100

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int num_vertices, int node) {
    if (!visited[node]) {
        printf("%d ", node);
        visited[node] = 1;

        for (int i = 0; i < num_vertices; i++) {
            if (graph[node][i] && !visited[i]) {
                dfs(graph, visited, num_vertices, i);
            }
        }
    }
}

int main() {
    int num_vertices, num_edges;

    // Get the number of vertices and edges from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int graph[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES];

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges
    printf("Enter the edges (vertex pairs connected by an edge):\n");
    for (int k = 0; k < num_edges; k++) {
        int vertex1, vertex2;
        printf("Edge %d: ", k + 1);
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = graph[vertex2][vertex1] = 1;  // Assuming an undirected graph
    }

    // Choose a starting node for DFS
    int start_node;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &start_node);

    printf("DFS traversal starting from node %d: ", start_node);
    dfs(graph, visited, num_vertices, start_node);
    printf("\n");

    return 0;
}
