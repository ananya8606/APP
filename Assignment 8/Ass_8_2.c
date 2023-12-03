#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc((vertices+1) * sizeof(struct Node*));

    for (int i = 1; i <= vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex, bool visited[], int currentSet[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* current = graph->adjacencyList[vertex];
    while (current != NULL) {
        int neighbor = current->data;
        if (!visited[neighbor]) {
            currentSet[neighbor] = currentSet[vertex];
            DFS(graph, neighbor, visited, currentSet);
        }
        current = current->next;
    }
}

void findDisjointSets(struct Graph* graph) {
    bool visited[MAX_VERTICES] = { false };
    int currentSet[MAX_VERTICES] = { 0 };

    int setNumber = 1;

    for (int i = 1; i <= graph->vertices; ++i) {
        if (!visited[i]) {
            printf("Set %d: ", setNumber++);
            currentSet[i] = i;
            DFS(graph, i, visited, currentSet);
            printf("\n");
        }
    }
}

int main() {
    struct Graph* graph = createGraph(8);
    addEdge(graph, 3, 1);
    addEdge(graph, 8, 2);
    addEdge(graph, 6, 2);
    addEdge(graph, 5, 6);
    addEdge(graph, 4, 2);
    addEdge(graph, 7, 7);
    findDisjointSets(graph);

    return 0;
}
