#include <stdio.h>
#include <stdbool.h>

struct node{

    char *data;
    struct node *next;

};
typedef struct node node;

node addNode(char *data, node *nextNode);
void insertNode(node *newNode, node *currentNode, node *nextNode);
void deleteNode(node *unwantedNode);
node *nodeSearch(node *startingNode, char *searchData);

node addNode(char *nodeData, node *nextNode){

    node newNode;
    newNode.data = nodeData;
    newNode.next = nextNode;

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

    if(startingNode->next == NULL){
        return(NULL);
    }

    node *priorNodePtr = startingNode;

    while(true){

        node *newNode = priorNodePtr->next;

        if(newNode->next == NULL){
            return(NULL);
        }

        else if(newNode->data == searchData){
            return(newNode);
        }

        else{

            priorNodePtr = newNode;
        }

    }

    return(NULL);

}

void deleteNode(node *unwantedNode){

    //find prior node to unwanted
    //collect address of node after unwanted
    //point node of prior to node after unwanted
}
