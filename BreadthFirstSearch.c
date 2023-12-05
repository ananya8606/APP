#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Queue structure
struct Queue {
    struct QueueNode *front, *rear;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Function to create a new node for adjacency list
struct Node* newAdjNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue a data into the queue
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

// Function to dequeue a data from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q))
        return -1;

    struct QueueNode* temp = q->front;
    int data = temp->data;
    q->front = temp->next;

    free(temp);
    return data;
}

// Function to perform Breadth-First Search
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

        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(q);
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = newAdjNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = newAdjNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printf("\nBreadth First Traversal starting from 0 \n");
    BFS(graph, 0);

    return 0;
}
