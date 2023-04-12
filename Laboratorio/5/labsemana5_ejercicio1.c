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

void addNode(struct node **head, struct node *newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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

int main() {
    struct node *head = NULL;
    struct node *newNode = createNode(1);
    addNode(&head, newNode);
    newNode = createNode(4);
    addNode(&head, newNode);
    newNode = createNode(3);
    addNode(&head, newNode);
    
    printNodes(&head);
    freeNodes(&head);
    
    return 0;
}
