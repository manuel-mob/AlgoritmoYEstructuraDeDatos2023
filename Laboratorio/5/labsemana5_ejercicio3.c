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

void push(struct node **head, struct node *newNode) {
    newNode->next = *head;
    *head = newNode;
}

struct node* pop(struct node **head) {
    if (*head == NULL) {
        printf("Error: stack underflow.");
        exit(1);
    }
    struct node *tempNodeReturn;
    struct node *temp = *head;
    tempNodeReturn = temp;
    *head = (*head)->next;
    tempNodeReturn->next = NULL;
    return tempNodeReturn;
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
    struct node *newNode;
    struct node *currentNode;
    printf("values 1,10,3,5,7\n");
    newNode = createNode(1);
    push(&head,newNode);
    newNode = createNode(10);
    push(&head,newNode);
    newNode = createNode(3);
    push(&head,newNode);
    newNode = createNode(5);
    push(&head,newNode);
    newNode = createNode(7);
    push(&head,newNode);
    printNodes(&head);
    currentNode = pop(&head);
    printf("Pop = %d\n",currentNode->data);
    free(currentNode);
    printNodes(&head);
    printf("Peek = %d\n",peek(&head)->data);
    freeNodes(&head);

}
