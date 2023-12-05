#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

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

int scompare(const void *a, const void *b)
{
    struct Edge *na = (struct Edge *)a;
    struct Edge *nb = (struct Edge *)b;

    return na->weight - nb->weight;
}

void MST_kruskal(int v, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int e)
{
    struct Edge result[v];

    int edgeCount = 0;
    int i = 0;

    struct subset *subsets = (struct subset *)malloc(v * sizeof(struct subset));

    for (i = 0; i < v; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    i = 0;

    // Create an array of edges for sorting
    struct Edge *edges = (struct Edge *)malloc(e * sizeof(struct Edge));

    for (int row = 0; row < v; row++)
    {
        for (int col = row; col < v; col++)
        {
            if (adjMatrix[row][col] != 0)
            {
                edges[i].src = row;
                edges[i].dest = col;
                edges[i].weight = adjMatrix[row][col];
                i++;
            }
        }
    }

    // Sort edges according to their weight/length using library function qsort()
    qsort(edges, e, sizeof(edges[0]), scompare);

    // As in a minimum spanning tree, the number of edges is n-1.
    while (edgeCount < v - 1)
    {
        struct Edge crawl = edges[i++];

        int x = find(subsets, crawl.src);
        int y = find(subsets, crawl.dest);

        if (x != y) // Avoid cycles
        {
            result[edgeCount++] = crawl;
            Union(subsets, x, y);
        }
    }

    printf("Following edges are there in MST\n");
    printf("src--dest=weight\n");
    for (i = 0; i < edgeCount; i++)
        printf("%d--%d=%d\n", result[i].src, result[i].dest, result[i].weight);
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

    MST_kruskal(v, adjMatrix, e);

    return 0;
}
