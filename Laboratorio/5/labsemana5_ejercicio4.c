#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

void printNodes(struct node **head) {
    struct node *temp = *head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void freeNodes(struct node **head) {
    struct node *current = *head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
}

struct node* searchNode(int dataValue,struct node **head) {
    struct node *temp = *head;
    while (temp != NULL) {
        //Return the first match
        if(temp->data == dataValue){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct node* peek(struct node **head) {
    struct node *tempNodeReturn = *head;
    return tempNodeReturn;
}

int getSize(struct node **head) {
    struct node *temp = *head;
    int size;
    for (size = 0 ;  temp != NULL ; size++ ){
        temp = temp->next;
    }
    return size;
}

int main() {
    //stack/pila
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *newNode;
    struct node *currentNode;
    printf("values 10,4,9,7\n");
    newNode = createNode(10);
    enqueue(&head,&tail,newNode);
    newNode = createNode(4);
    enqueue(&head,&tail,newNode);
    newNode = createNode(9);
    enqueue(&head,&tail,newNode);
    newNode = createNode(7);
    enqueue(&head,&tail,newNode);
    printNodes(&head);
    currentNode = dequeue(&head, &tail);
    printf("dequeue = %d\n",currentNode->data);
    free(currentNode);
    printNodes(&head);

}
