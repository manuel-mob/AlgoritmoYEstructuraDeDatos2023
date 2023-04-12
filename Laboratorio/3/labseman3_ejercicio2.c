#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 5

typedef struct {
    char name[50];
    int level;
    int hp;
    int xp; // 0,25,50 o 75. 100 for the next level and get 0.
} PlayerStats;

int expGeneratorRand(){
    srand(time(NULL));
    int random_number = rand() % 4;  
    int random_value = random_number * 25;  
    return random_value;
}

void createPlayer(PlayerStats playerArray[],int index) {
    printf("Enter player name: ");
    scanf("%s", playerArray[index].name);

    printf("Enter player level: ");
    scanf("%d", &playerArray[index].level);

    playerArray[index].hp = 100;   
    playerArray[index].xp = expGeneratorRand();
}

void printPlayerInformation(PlayerStats playerArray) {
    printf("Stats of %s area; Level %d, %d EX and %d of HP.\n",playerArray.name, playerArray.level, playerArray.xp,playerArray.hp);
}


int main () {
    PlayerStats playerTeam1[MAX];

    for (int i = 0; i < MAX; i++)
    {
        createPlayer(playerTeam1,i);   
    }
    
    for( int i = 0 ; i < MAX ; i++) {
        printPlayerInformation(playerTeam1[i]);
    } 

    return 0;
}