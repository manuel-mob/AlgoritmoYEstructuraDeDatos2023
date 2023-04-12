#include <stdio.h>

int main() {
	int sum = 0;
	int count = 0;
  	int umbral = 7;

	printf("Ingrese los puntajes de los jugadores: \n");
  
	int num;
	while (scanf("%d", &num) == 1) {
		sum += num;
		count++;
	}
  
	float average = (float) sum / count;
	printf("Average: %f\n", average);
	if ( average > umbral ) {
		printf("Superaste el nivel!\n");
	}
  
	return 0;
}

