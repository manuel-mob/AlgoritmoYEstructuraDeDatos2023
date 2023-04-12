#include <stdio.h>

int main() {
  // Inicializacion
  int myArray[5] = {1, 2, 3, 4, 5};

  // Acceso a un elemento
  printf("Element at index 2: %d\n", myArray[2]);

  // Actualizacion de elemento.
  myArray[2] = 10;
  printf("Updated element at index 2: %d\n", myArray[2]);

  // Busqueda en un arreglo
  int searchValue = 4;
  int foundIndex = -1;
  for (int i = 0; i < 5; i++) {
    if (myArray[i] == searchValue) {
      foundIndex = i;
      break;
    }
  }
  if (foundIndex != -1) {
    printf("Encontrado el valor %d en el indice %d\n", searchValue, foundIndex);
  } else {
    printf("%d no se encuentra en el arreglo\n", searchValue);
  }

  // Ordenamiento de un arreglo / selection sort
  for (int i = 0; i < 4; i++) {
    int minIndex = i;
    for (int j = i + 1; j < 5; j++) {
      if (myArray[j] < myArray[minIndex]) {
        minIndex = j;
      }
    }
    int temp = myArray[i];
    myArray[i] = myArray[minIndex];
    myArray[minIndex] = temp;
  }
  printf("Arreglo ordenado: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  // Insertando un elemento en el arreglo
  int insertValue = 6;
  int insertIndex = 3;
  for (int i = 4; i >= insertIndex; i--) {
    myArray[i + 1] = myArray[i];
  }
  myArray[insertIndex] = insertValue;
  printf("Arreglo despues de insertar %d en el indice %d: ", insertValue, insertIndex);
  for (int i = 0; i < 6; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  // Eliminacion de un elemento del arreglo
  int removeIndex = 2;
  for (int i = removeIndex; i < 4; i++) {
    myArray[i] = myArray[i + 1];
  }
  printf("Arreglo despues de remover el indice %d: ", removeIndex);
  for (int i = 0; i < 5; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  // Copiando un arreglo
  int myCopy[5];
  for (int i = 0; i < 5; i++) {
    myCopy[i] = myArray[i];
  }
  printf("Arreglo copiado: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", myCopy[i]);
  }
  printf("\n");

  // Merging two arrays
  int myOtherArray[5] = {6, 7, 8, 9, 10};
  int mergedArray[10];
  for (int i = 0; i < 5; i++) {
    mergedArray[i] = myArray[i];
  }
  for (int i = 0; i < 5; i++) {
    mergedArray[5+i] = myOtherArray[i];
  }
  printf("El otro arreglo es: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", myOtherArray[i]);
  }
  printf("\n");
  printf("El nuevo arreglo combinado es: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", mergedArray[i]);
  }
  printf("\n");
}
