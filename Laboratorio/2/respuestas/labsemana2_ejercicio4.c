#include <stdio.h>

#define MAX_PATIENTS 10
#define NUM_DAYS 3
#define FEVER_THRESHOLD 39.0

int main()
{
    char names[MAX_PATIENTS][30];
    int ages[MAX_PATIENTS];
    float temperatures[MAX_PATIENTS][NUM_DAYS];
    int fever_counts[MAX_PATIENTS] = {0};
    int num_patients;
    
    printf("Enter the number of patients (maximum 100): ");
    scanf("%d", &num_patients);
    
    // Input patient data
    for (int i = 0; i < num_patients; i++) {
        printf("Enter name for patient %d: ", i+1);
        scanf("%s", names[i]);
        printf("Enter age for patient %d: ", i+1);
        scanf("%d", &ages[i]);
        for (int j = 0; j < NUM_DAYS; j++) {
            printf("Enter temperature for patient %d on day %d: ", i+1, j+1);
            scanf("%f", &temperatures[i][j]);
        }
    }
    
    // Calculate and display average temperature for each patient over past week
    printf("\nAverage temperature for each patient over the past week:\n");
    for (int i = 0; i < num_patients; i++) {
        float total_temp = 0;
        for (int j = 0; j < NUM_DAYS; j++) {
            total_temp += temperatures[i][j];
        }
        printf("%s (age %d): %.1f°F\n", names[i], ages[i], total_temp/NUM_DAYS);
    }
    
    // Identify patients who have had a fever for three or more consecutive days
    for (int i = 0; i < num_patients; i++) {
        for (int j = 0; j < NUM_DAYS-2; j++) {
            if (temperatures[i][j] > FEVER_THRESHOLD && temperatures[i][j+1] > FEVER_THRESHOLD && temperatures[i][j+2] > FEVER_THRESHOLD) {
                fever_counts[i]++;
            }
        }
    }
    
    // Display patients who have had a fever for three or more consecutive days
    printf("\nPatients who have had a fever for three or more consecutive days:\n");
    int num_fever_patients = 0;
    for (int i = 0; i < num_patients; i++) {
        if (fever_counts[i] > 0) {
            printf("%s (age %d): %d\n", names[i], ages[i], fever_counts[i]);
            num_fever_patients++;
        }
    }
    if (num_fever_patients == 0) {
        printf("No patients have had a fever for three or more consecutive days.\n");
    }
    
    return 0;
}

