#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Graph {
    int vertices;
    int** adjMatrix;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void enqueue(struct Queue* q, int data) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q))
        return -1;

    struct QueueNode* temp = q->front;
    int data = temp->data;
    q->front = temp->next;

    free(temp);
    return data;
}

void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();
    int* visited = (int*)malloc(sizeof(int) * graph->vertices);

    for (int i = 0; i < graph->vertices; ++i)
        visited[i] = 0;

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; ++i) {
            if (graph->adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }

    free(visited);
    free(q);
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("\nBreadth First Traversal starting from %d\n", startVertex);
    BFS(graph, startVertex);

    return 0;
}
