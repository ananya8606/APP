#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *stack = NULL;

int top()
{
    if (stack == NULL)
        return -1;

    return stack->data;
}

void pop()
{
    if (stack == NULL)
        return;

    struct Stack *node = stack;
    stack = stack->next;

    free(node);
}

int isEmpty()
{
    return stack == NULL ? 1 : 0;
}

void push(int data)
{
    struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
    node->data = data;
    node->next = stack;

    stack = node;
}

void DFSutil(int v, int n, int visited[n], int graph[n][n])
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[v][i])
        {
            DFSutil(i, n, visited, graph);
        }
    }
}

void fillOrder(int v, int n, int visited[n], int graph[n][n])
{
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[v][i])
        {
            fillOrder(i, n, visited, graph);
        }
    }

    push(v);
}

void printSCC(int n, int graph[n][n])
{
    stack = NULL;
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            fillOrder(i, n, visited, graph);

    int tgraph[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tgraph[i][j] = graph[j][i];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    while (!isEmpty())
    {
        int v = top();
        pop();

        if (!visited[v])
        {
            DFSutil(v, n, visited, tgraph);
            printf("\n");
        }
    }
}

int main()
{
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++)
    {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
    }

    printf("Following are the strongly connected components \n");
    printSCC(n, graph);

    return 0;
}
