#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        printf("Countdown: %d\n", 10 - i);
        fflush(stdout);
        sleep(1);
        system("clear"); // use "cls" on Windows
    }

    printf("Blast off!\n");

    return 0;
}
