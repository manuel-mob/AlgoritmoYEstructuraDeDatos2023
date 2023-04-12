#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // for ( int i = 0 ; i < argc ; i++ ) {
        //     printf("Parametro[%d]:%s\n",i,argv[i]);
        // }
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
        printf("%s, age:%d T°:%.1f ROOM:%d\n",name,age,temperature,room);
    }
    fclose(file);

    return 0;
}






