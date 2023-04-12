#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int room;
    float temperature;
} Patient;

#define MAX 3

void printPatients(Patient patients[]);
void addPatient(Patient patients[]);

int main(){
    Patient patients[MAX];
    
    Patient newPatient;

    addPatient(patients); 
    printPatients(patients);

}

void printPatients(Patient patients[]) {
    printf("List of patients:\n");
    for(int i = 0 ; i < MAX ; i++ ){
        printf("%s, %d and room:%d\n",patients[i].name,patients[i].age,patients[i].room);
    }
}

void addPatient(Patient patients[]){
    for (int i = 0; i < MAX; i++) {
        printf("Nombre:");
        scanf("%s", patients[i].name);
        printf("Agregar edad:");
        scanf("%d",&patients[i].age);
        printf("Agregar habilitación:");
        scanf("%d",&patients[i].room);
    }
}