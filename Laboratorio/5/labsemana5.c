#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int dataValue){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = dataValue;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct node **headRef,struct node *newNode){
    if (*headRef == NULL){
        *headRef = newNode;
    }
    else {
        struct node *current = *headRef;
        while ( current->next != NULL ){
            current = current->next;
        }
        current->next = newNode;
    }
}

void printNodes(struct node *headRef){
    struct node *current = headRef;
    while (current != NULL){
        printf("Data[%d]\n",current->data);
        current = current->next;
    }
}

void freeNodes(struct node *headRef){
    struct node *current = headRef;
    while (current != NULL){
        struct node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

struct node* searchNode(struct node *headRef,int value){
    struct node *current = headRef;
    while (current != NULL){
        //return first value in the list
        if ( current-> data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int getSize(struct node *headRef){
    int size = 0;
    struct node *current = headRef;
    while (current != NULL){
        size++;
        current = current->next;
    }
    return size;
}

int main () {
    struct node *begin = NULL;
    struct node *newNode;
    //Values 2,5,8
    //Create and x 3 
    newNode = createNode(2);
    addNode(&begin,newNode);
    newNode = createNode(5);
    addNode(&begin,newNode);
    newNode = createNode(8);
    addNode(&begin,newNode);
    printNodes(begin);
    freeNodes(begin);
    begin = NULL;
    newNode = createNode(3);
    addNode(&begin,newNode);
    newNode = createNode(8);
    addNode(&begin,newNode);
    newNode = createNode(232);
    addNode(&begin,newNode);
    newNode = createNode(29);
    addNode(&begin,newNode);
    printNodes(begin);
    printf("[%d] size\n",getSize(begin));
    //search 232
    int searchPatter = 7;
    struct node *searchValueNode = searchNode(begin,searchPatter);
    if ( searchValueNode != NULL ){
        printf("%d is on the list\n",searchValueNode->data);
        printf("%d is on the list\n",searchPatter);
    }
    else {
        printf("%d not found",searchPatter);
    }

    freeNodes(begin);
    
    return 0;
}
