#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int level;
    int hp;
    int xp;
} PlayerStats;

int main () {
    PlayerStats player1;

    printf("Enter player name: ");
    scanf("%s", player1.name);

    printf("Enter player level: ");
    scanf("%d", &player1.level);

    printf("Enter player hp: ");
    scanf("%d", &player1.hp);

    printf("Enter player experience: ");
    scanf("%d", &player1.xp);

    printf("Player %s is at level %d with %d experience points and %d of HP.\n", player1.name, player1.level, player1.xp,player1.hp);

    return 0;
}