#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Edge
{
    int src, dest, weight;
};

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int edgeComparator(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void MST_Kruskal(int v, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int e)
{
    struct Edge *edges = (struct Edge *)malloc(e * sizeof(struct Edge));

    int edgeCount = 0;

    struct subset *subsets = (struct subset *)malloc(v * sizeof(struct subset));
    for (int i = 0; i < v; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for (int row = 0; row < v; row++)
    {
        for (int col = row; col < v; col++)
        {
            if (adjMatrix[row][col] != 0)
            {
                edges[edgeCount].src = row;
                edges[edgeCount].dest = col;
                edges[edgeCount].weight = adjMatrix[row][col];
                edgeCount++;
            }
        }
    }

    qsort(edges, e, sizeof(edges[0]), edgeComparator);

    struct Edge *result = (struct Edge *)malloc((v - 1) * sizeof(struct Edge));

    int i = 0, j = 0;

    while (i < v - 1 && j < e)
    {
        struct Edge nextEdge = edges[j++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y)
        {
            result[i++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Following edges are there in MST\n");
    printf("src--dest=weight\n");
    for (i = 0; i < v - 1; i++)
        printf("%d--%d=%d\n", result[i].src, result[i].dest, result[i].weight);

    free(edges);
    free(result);
    free(subsets);
}

int main()
{
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter edges with their weights (src dest weight):\n");
    for (int i = 0; i < e; i++)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }

    MST_Kruskal(v, adjMatrix, e);

    return 0;
}
