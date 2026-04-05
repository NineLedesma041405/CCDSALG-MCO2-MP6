#ifndef GRAPHTRAVERSAL_C
#define GRAPHTRAVERSAL_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filereader.c"
#include "main.c"

// add code here for both 'get friend list' and 'get connection' here
void getFriendList(struct Graph* graph, int id) {
    if (id < 0 || id >= graph->numVertices) {
        printf("Error: ID %d does not exist in the dataset.\n", id);
        return;
    }

    struct Node* temp = graph->adjLists[id];
    int count = 0;

    // Count friends first
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Person %d has %d friend(s)!\n", id, count);

    if (count == 0) {
        printf("List of friends: (none)\n");
        return;
    }

    printf("List of friends:");
    temp = graph->adjLists[id];
    while (temp != NULL) {
        printf(" %d", temp->id);
        temp = temp->next;
    }
    printf("\n");
}
#endif
