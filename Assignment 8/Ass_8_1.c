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

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void BFS(struct Graph* graph, int source) {
    printf("BFS Traversal starting from node %d:\n", source);

    struct Queue* queue = createQueue(graph->vertices);
    bool visited[MAX_VERTICES] = { false };
    int predecessors[MAX_VERTICES] = { -1 };
    int pathLength[MAX_VERTICES] = { 0 };

    enqueue(queue, source);
    visited[source] = true;

    while (!isQueueEmpty(queue)) {
        int current = dequeue(queue);
        printf("%d ", current);

        struct Node* temp = graph->adjacencyList[current];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                enqueue(queue, neighbor);
                visited[neighbor] = true;
                predecessors[neighbor] = current;
                pathLength[neighbor] = pathLength[current] + 1;
            }
            temp = temp->next;
        }
    }

    printf("\nPredecessors in BFS tree:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Node %d: %d\n", i, predecessors[i]);
    }

    printf("Path Length from source in BFS tree:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Node %d: %d\n", i, pathLength[i]);
    }

    free(queue->array);
    free(queue);
}

void DFSUtil(struct Graph* graph, int vertex, bool visited[], int predecessors[], int discoveryTime[], int finishTime[], int* time) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            predecessors[neighbor] = vertex;
            (*time)++;
            discoveryTime[neighbor] = *time;
            DFSUtil(graph, neighbor, visited, predecessors, discoveryTime, finishTime, time);
        }
        temp = temp->next;
    }

    (*time)++;
    finishTime[vertex] = *time;
}

void DFS(struct Graph* graph, int source) {
    printf("DFS Traversal starting from node %d:\n", source);

    bool visited[MAX_VERTICES] = { false };
    int predecessors[MAX_VERTICES] = { -1 };
    int discoveryTime[MAX_VERTICES] = { 0 };
    int finishTime[MAX_VERTICES] = { 0 };
    int time = 0;

    DFSUtil(graph, source, visited, predecessors, discoveryTime, finishTime, &time);

    printf("\nPredecessors in DFS tree:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Node %d: %d\n", i, predecessors[i]);
    }

    printf("Discovery Time in DFS tree:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Node %d: %d\n", i, discoveryTime[i]);
    }

    printf("Finish Time in DFS tree:\n");
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Node %d: %d\n", i, finishTime[i]);
    }
}

int main() {
    struct Graph* graph = createGraph(7);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 3);

    int source = 0; // Change the source node as needed

    BFS(graph, source);
    printf("\n\n");
    DFS(graph, source);

    return 0;
}
