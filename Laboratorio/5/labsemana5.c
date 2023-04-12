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

void push(struct node **headRef,struct node *newNode){
    newNode->next = *headRef;
    *headRef = newNode;
}

struct node* pop(struct node **headRef){
    if ( *headRef == NULL ) {
        printf("stack is empty");
        exit(0);
    }
    struct node *temp = *headRef;
    *headRef = temp->next;
    temp->next = NULL;
    return temp;
}

void enqueue(struct node **headRef, struct node **tailRef, struct node *newNode) {
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        (*tailRef)->next = newNode;
    }
    *tailRef = newNode;
}

struct node* dequeue(struct node **headRef, struct node **tailRef) {
    if (*headRef == NULL) {
        printf("Error: queue underflow.");
        exit(1);
    }
    struct node* dequeuedNode = *headRef;
    *headRef = (*headRef)->next;
    if (*headRef == NULL) {
        *tailRef = NULL;
    }
    dequeuedNode->next = NULL;
    return dequeuedNode;
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


    struct node *newNode;
    printf("\n\t//QUEUE\n\n");
    //QUEUE FIFO
    // Values are 4,7,9
    // 9 Last
    // 7
    // 4 First
    struct node *queque = NULL;
    struct node *tail = NULL;
    newNode = createNode(4);
    enqueue(&queque,&tail,newNode);
    newNode = createNode(7);
    enqueue(&queque,&tail,newNode);
    newNode = createNode(9);
    enqueue(&queque,&tail,newNode);
    printNodes(queque);
    struct node *tempNode = dequeue(&queque,&tail);
    printf("Out of queue: %d\n",tempNode->data);
    free(tempNode);
    tempNode = dequeue(&queque,&tail);
    printf("Out of queue: %d\n",tempNode->data);
    free(tempNode);
    printNodes(queque);

    printf("\n\t//STACK\n\n");
    //STACK LIFO
    // Values are 4,7,9
    // 9 Last
    // 7
    // 4 First
    struct node *stack = NULL;
    newNode = createNode(4);
    push(&stack,newNode);
    newNode = createNode(7);
    push(&stack,newNode);
    newNode = createNode(9);
    push(&stack,newNode);
    printNodes(stack);
    struct node *poped = pop(&stack);
    printf("Pop: %d\n",poped->data);
    free(poped);
    poped = pop(&stack);
    printf("Pop: %d\n",poped->data);
    free(poped);
    printNodes(stack);
    //STACK END


    struct node *begin = NULL;

    printf("\n\t//LIST\n\n");
    //LIST
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
