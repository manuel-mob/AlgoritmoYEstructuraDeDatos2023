#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient {
    char name[20];
    int age;
    int room;
    float temperature;
    struct patient *next;
} Patient;

Patient* createPatient(char *name, int age,float temp, int room);
void addPatient(Patient **head, Patient *newPatient);
void printPatients(Patient *head);
void freePatients(Patient *head);

int main(int argc, char *argv[]) {
    Patient *head = NULL;
    Patient *newPatient;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    char *file_name = argv[1];
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", file_name);
        return 1;
    }
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        char *token;
        //https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
        token = strtok(line, ",");
        char name[50];
        strcpy(name, token);
        //https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm
        int age = atoi(strtok(NULL, ","));
        int room = atoi(strtok(NULL, ","));
        float temperature = atof(strtok(NULL, ","));
        newPatient = createPatient(name, age, temperature, room);
        addPatient(&head,newPatient);
        //printf("%s, age:%d T°:%.1f ROOM:%d\n",name,age,temperature,room);
    }
    fclose(file);

    // Print the list of patients
    printPatients(head);
    // Free the memory used by the patients
    freePatients(head);

    return 0;
}

// Function to create a new patient record
Patient* createPatient(char *name, int age, float temp, int room) {
    Patient *newPatient = (Patient*)malloc(sizeof(Patient));
    strcpy(newPatient->name, name);
    newPatient->age = age;
    newPatient->temperature = temp;
    newPatient->room = room;
    newPatient->next = NULL;
    return newPatient;
}

// Function to add a new patient to the list
void addPatient(Patient **head, Patient *newPatient) {
    
    if (*head == NULL) {
        *head = newPatient;
    } else {
        Patient *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPatient;
    }
}

// Function to print the list of patients
void printPatients(Patient *head) {
    printf("List of patients:\n");
    Patient *current = head;
    while (current != NULL) {
        printf("Name: %s, age: %d, %.1f°, Room number: %d.\n", current->name, current->age,current->temperature, current->room);
        current = current->next;
    }
}

// Function to free the list of patienes
void freePatients(Patient *head) {
    Patient *current = head;
    while (current != NULL) {
        Patient *next = current->next;
        free(current);
        current = next;
    }
}






