#ifndef FILEREADER_C
#define FILEREADER_C

#include <stdio.h>
#include <string.h>

// code for adjacency list and file reading

// node in linked list for friends
struct Node {
    int id;
    struct Node* next;
};

// graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->id = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* loadGraph(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return NULL;
    }

    int n, e;
    fscanf(file, "%d %d", &n, &e); // reads accounts and friendship count

    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;
    graph->adjLists = malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
    }

    for (int i = 0; i < e; i++) {
        int src, dest;
        fscanf(file, "%d %d", &src, &dest);

        // bidirectional so add edges to both
        struct Node* newNode = createNode(dest);
        newNode->next = graph->adjLists[src];
        graph->adjLists[src] = newNode;

        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }

    fclose(file);
    return graph;
}

#endif