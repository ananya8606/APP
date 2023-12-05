#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *stop = NULL; // top of stack

int isempty()
{
    return stop == NULL ? 1 : 0;
}

void push(int data)
{
    struct Stack *newnode = (struct Stack *)malloc(sizeof(struct Stack));
    newnode->data = data;
    newnode->next = stop;
    stop = newnode;
}

void pop()
{
    if (stop == NULL)
        return;

    struct Stack *node = stop;
    stop = stop->next;
    free(node);
}

int top()
{
    return stop->data;
}

void tSortutil(int v, int size, int adjMatrix[size][size], int visited[])
{
    visited[v] = 1;

    for (int i = 0; i < size; i++)
    {
        if (adjMatrix[v][i] && !visited[i])
            tSortutil(i, size, adjMatrix, visited);
    }

    push(v);
}

void TopologicalSort(int size, int adjMatrix[size][size])
{
    stop = NULL; // creating a stack
    int *visited = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        visited[i] = 0;

    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 0)
            tSortutil(i, size, adjMatrix, visited);
    }

    printf("Topological Sort for the given graph is: ");

    while (!isempty())
    {
        printf("%d ", top());
        pop();
    }
}

int main()
{
    int size, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);

    int adjMatrix[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            adjMatrix[i][j] = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
    }

    TopologicalSort(size, adjMatrix);

    return 0;
}
