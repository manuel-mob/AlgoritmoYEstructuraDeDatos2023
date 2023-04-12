#include <stdio.h>

#define MAX 10

void printArray(int* array,int varMax){
	for ( int i = 0; i < MAX && i < varMax ; i++ ){
		printf("El item %d tiene una cantidad de %d\n",i,array[i]);
	}
	printf("\n");
}

int* addItem(int *array,int item,int varMax){
	for (int i = 0; i < MAX && i < varMax; i++ ) {
		if ( i == item )
			array[i]++;
	}
	return array;
}

int main() {
	int arr[MAX] = {1};
	int varMAX = 0;
	int tempVar = 0;

	printf("Numero total de items, (-1) para no definir y trabajar con el maximo (%d):",MAX);
	scanf("%d",&varMAX);
	if ( varMAX != -1 ) {
		printf("Perfecto, trabajaremos con %d elementos\n",varMAX);
		for ( int i = 0 ; i < varMAX ; i ++ ) {
			printf("Ingresar la cantidad de cada item del jugado:\n");
			scanf("%d",&arr[i]);
		}
		printArray(arr,varMAX);

		for ( int i = 0 ; i < varMAX ; i ++ ) {
			printf("Ingresa el item que obtuviste\n");
			scanf("%d",&tempVar);
			addItem(arr,tempVar,varMAX);
			printArray(arr,varMAX);
		}
	}
	else {
		if ( varMAX > 10 ) {
			printf("Lo lamento, no seguiste las instruciones e ingresaste un numero que no corresponde");
			return 1;
		}
	}


	for ( int i = 0 ; i < MAX ; i++ ) {
		//Ingreso de datos
		printf("%d ",arr[i]);
	}	
	return 0;
}
