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

void BFS(int** adjMatrix, int vertices, int startVertex) {
    struct Queue* q = createQueue();
    int* visited = (int*)malloc(sizeof(int) * vertices);

    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }

    free(visited);
    free(q);
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int** adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; ++j) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("\nBreadth First Traversal starting from %d\n", startVertex);
    BFS(adjMatrix, vertices, startVertex);

    for (int i = 0; i < vertices; ++i) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
