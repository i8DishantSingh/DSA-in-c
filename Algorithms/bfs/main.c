#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Graph structure
struct Graph
{
    int vertices;
    struct Node **adjList;
};

// Queue structure
struct Queue
{
    int items[100];
    int front, rear;
};

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = (struct Node **)malloc(vertices * sizeof(struct Node *));
    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;
    return graph;
}

// Add edge (undirected graph)
void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Queue functions
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(struct Queue *q)
{
    return q->rear == -1;
}

void enqueue(struct Queue *q, int value)
{
    if (q->rear == 99)
        return; // queue full
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
        return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return item;
}

// BFS function
void BFS(struct Graph *graph, int startVertex)
{
    bool visited[graph->vertices];
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = false;

    struct Queue *q = createQueue();

    visited[startVertex] = true;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node *temp = graph->adjList[currentVertex];
        while (temp)
        {
            int adjVertex = temp->data;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int V = 5;
    struct Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    printf("BFS starting from vertex 0:\n");
    BFS(graph, 0);

    return 0;
}