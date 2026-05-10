#include <stdio.h>
#include <stdlib.h>

#define MAX 10
struct Graph
{
    int vertices;
    int Matrix[MAX][MAX]
};

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->Matrix[i][j] = 0;
            printf("%d ", graph->Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nCreated a %dx%d graph.\n", vertices, vertices);
    return graph;
};

void addEdge(struct Graph *graph, int src, int dest)
{
    graph->Matrix[src][dest] = 1; // This indicates that there is a edge between vertices src and dest
}

void printGraph(struct Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->Matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);
    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print adjacency matrix
    printGraph(graph);

    return 0;
}