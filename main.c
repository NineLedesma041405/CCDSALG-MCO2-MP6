#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filereader.c"
#include "graphtraversal.c"

#define MAX_CHAR 500

int main() {

    int filechoice, menuchoice;
    char filename[MAX_CHAR];

    do {
        
        printf("SELECT FILE:");
        printf("1. Caltech36.txt\n");
        printf("2. Harvard1.txt\n");
        printf("3. Rice31.txt\n");
        printf("4. Stanford3.txt\n");
        printf("5. Trinity100.txt\n");

        printf("Input number (1-5): ");
        scanf("%d", &filechoice);

        switch (filechoice) {
            case 1:
                strcpy(filename, "data/Caltech36.txt"); 
                break;
            case 2:
                strcpy(filename, "data/Harvard1.txt");    
                break;
            case 3:
                strcpy(filename, "data/Rice31.txt");  
                break;
            case 4: 
                strcpy(filename, "data/Stanford3.txt");  
                break;
            case 5:
                strcpy(filename, "data/Trinity100.txt");  
                break;
            default:
                printf("Invalid choice.");
                filechoice = 0;
        } 

    } while (filechoice < 1 || filechoice > 5);

    struct Graph* graph = loadGraph(filename);
    printf("Graph loaded!\n");

    do {
        printf("MAIN MENU"); 
        printf("[1] Get friend list");
        printf("[2] Get connection"); 
        printf("[3] Exit");
        printf("Enter your choice: ");
        scanf("%d", &menuchoice);

        switch (menuchoice) {
            case 1: {    //get friend list main code
                int personID;
                printf("Enter ID of person: ");
                scanf("%d", &personID);
                getFriendList(graph, personID);
                break;
                    }
            case 2:
                // get connection main code here
                break;

            case 3:
                printf("Succesfully exited.");
                exit(EXIT_FAILURE);
                break;

            default:
                printf("Invalid choice.");
                menuchoice = 0;
        }
    } while (filechoice < 1 || filechoice > 3);

    return 0;
}
