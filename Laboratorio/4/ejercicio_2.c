#include <stdio.h>

void pointerFunction(int* number);

int main() {
    int number;
    int* point;

    point = &number;

    scanf("%d",&number);
    printf("[%d]\n",number);

    number = number * 5;

    printf("*[%d]\n",*point);

    pointerFunction(&number);
    printf("*[%d]\n",*point);
    printf("[%d]\n",number);

    return 0;
}

void pointerFunction(int* number){
    *number = 44;
}