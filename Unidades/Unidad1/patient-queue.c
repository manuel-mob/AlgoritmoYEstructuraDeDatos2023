#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float temperature;
} Patient;

typedef struct node {
    Patient data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *queue, Patient patient) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }
    node->data = patient;
    node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
}

Patient dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    Node *node = queue->front;
    Patient data = node->data;
    queue->front = node->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(node);
    return data;
}

int main() {
    Queue queue = { NULL, NULL };
    Patient p1 = { "John Smith", 32, 98.6 };
    Patient p2 = { "Jane Doe", 28, 99.2 };
    enqueue(&queue, p1);
    enqueue(&queue, p2);
    while (queue.front != NULL) {
        Patient p = dequeue(&queue);
        printf("Name: %s, Age: %d, Temperature: %.1f\n", p.name, p.age, p.temperature);
    }
    return 0;
}
