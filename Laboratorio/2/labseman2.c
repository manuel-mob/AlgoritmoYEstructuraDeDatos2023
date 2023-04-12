#include <stdio.h>

//Definición de variables globales

#define MAX 10   // numero maximo.
#define umbral 7   // numero umbral

int* funcion(int arreglo[],int valor){
	if ( valor < umbral ) {
		arreglo[0] = valor;
	}
	return arreglo;

}
void funcionImprimir(int arreglo[]){
	for (int i = 0; i < MAX ; i++ ){
		printf("%d ",arreglo[i]);
	}
	printf("\n");
}

int main() {
	int miArreglo[MAX] = {0};
	funcionImprimir(miArreglo);
	funcion(miArreglo,8);
	funcionImprimir(miArreglo);
	return 0;
}

