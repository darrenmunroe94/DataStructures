#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{

    char *data;
    struct node *next;

};
typedef struct node node;

node *addNode();
void insertNode(node *newNode, node *currentNode, node *nextNode);
node *nodeSearch(node *startingNode, char *searchData);
void deleteNode(node *headNode, node *unwantedNode);

node *addNode(){

    node *newNode = malloc(sizeof(node));

    return(newNode);
}

void insertNode(node *newNode, node *currentNode, node *nextNode){

    currentNode->next = newNode;

    newNode->next = nextNode;

}

node *nodeSearch(node *startingNode, char *searchData){

    if(startingNode->data == searchData){

        return(startingNode);
    }
    else if(startingNode->next == NULL){

        return(NULL);
    }
    else{

        startingNode = startingNode->next;
        nodeSearch(startingNode, searchData);
    }

    return(NULL); //if all else fails(somehow?)
}

void deleteNode(node *headNode, node *unwantedNode){

    //find prior node to unwanted
    node *priorNode = headNode;
    while(priorNode->next != unwantedNode){

        priorNode = priorNode->next;

    }

    if(unwantedNode->next == NULL){ //if unwanted nodes is a tail, free unwanted from memory

        priorNode->next = NULL; //prior node is new tail

        free(unwantedNode);

        return(0);
    }

    //point the node before unwanted to the node after unwanted
    node *nextNode = unwantedNode->next;
    priorNode->next = nextNode;

    free(unwantedNode);
}
