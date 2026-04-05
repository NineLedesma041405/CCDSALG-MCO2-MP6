#ifndef CONNECTION_C
#define CONNECTION_C

#include <stdio.h>
#include <stdlib.h>
#include "filereader.c"

void getConnection(struct Graph* graph, int start, int end) {
    if (start < 0 || start >= graph->numVertices ||
        end < 0 || end >= graph->numVertices) {
        printf("Error: One or both IDs do not exist.\n");
        return;
    }

    int* visited = malloc(graph->numVertices * sizeof(int));
    int* parent = malloc(graph->numVertices * sizeof(int));
    int* queue = malloc(graph->numVertices * sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        if (current == end) {
            int path[graph->numVertices];
            int count = 0;
            int temp = end;

            while (temp != -1) {
                path[count++] = temp;
                temp = parent[temp];
            }

            printf("There is a connection from %d to %d!\n", start, end);

            for (int i = count - 1; i > 0; i--) {
                printf("%d is friends with %d\n", path[i], path[i - 1]);
            }

            free(visited);
            free(parent);
            free(queue);
            return;
        }

        struct Node* temp = graph->adjLists[current];
        while (temp != NULL) {
            if (!visited[temp->id]) {
                visited[temp->id] = 1;
                parent[temp->id] = current;
                queue[rear++] = temp->id;
            }
            temp = temp->next;
        }
    }

    printf("No connection found between %d and %d.\n", start, end);

    free(visited);
    free(parent);
    free(queue);
}

#endif