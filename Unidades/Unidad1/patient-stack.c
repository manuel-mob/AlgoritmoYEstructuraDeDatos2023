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
    Node *top;
} Stack;

void push(Stack *stack, Patient patient) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }
    node->data = patient;
    node->next = stack->top;
    stack->top = node;
}

Patient pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    Node *node = stack->top;
    Patient data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

int main() {
    Stack stack = { NULL };
    Patient p1 = { "John Smith", 32, 98.6 };
    Patient p2 = { "Jane Doe", 28, 99.2 };
    push(&stack, p1);
    push(&stack, p2);
    while (stack.top != NULL) {
        Patient p = pop(&stack);
        printf("Name: %s, Age: %d, Temperature: %.1f\n", p.name, p.age, p.temperature);
    }
    return 0;
}
