#include <stdio.h>
#include <stdlib.h>

int main() {
	int MAX_SIZE = 5;
	int nums[MAX_SIZE];
	int umbral = 7;
  
	printf("Ingrese los puntajes de los jugadores (5 maximo): ");
  
	int count = 0;
	while (count < MAX_SIZE && scanf("%d", &nums[count]) == 1) {
		printf("%d",count);
		count++;
	}
  
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += nums[i];
		printf("Valor %d,es %d y la suma es %d\n",i,nums[i],sum);
	}
  
	float average = (float) sum / count;
	printf("Average: %f\n", average);
	if ( average > umbral ) {
		printf("Superaste el nivel!\n");
	}
  
	return 0;
}

