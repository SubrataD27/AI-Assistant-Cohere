#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player {
    char playerName[50];
    char teamName[50];
    float battingAverage;
    struct Player* next;
} Player;

Player* createPlayer(char* playerName, char* teamName, float battingAverage) {
    Player* newPlayer = (Player*)malloc(sizeof(Player));
    if (newPlayer == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newPlayer->playerName, playerName);
    strcpy(newPlayer->teamName, teamName);
    newPlayer->battingAverage = battingAverage;
    newPlayer->next = NULL;
    return newPlayer;
}

void insertPlayer(Player** head, char* playerName, char* teamName, float battingAverage) {
    Player* newPlayer = createPlayer(playerName, teamName, battingAverage);
    if (*head == NULL) {
        *head = newPlayer;
    } else {
        Player* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPlayer;
    }
}

void displayPlayers(Player* head) {
    printf("Players with a batting average of 50 or above:\n");
    while (head != NULL) {
        if (head->battingAverage >= 50) {
            printf("Player Name: %s, Team Name: %s, Batting Average: %.2f\n", head->playerName, head->teamName, head->battingAverage);
        }
        head = head->next;
    }
}

int main() {
    int n;
    char playerName[50];
    char teamName[50];
    float battingAverage;
    Player* head = NULL;

    printf("Enter the number of players: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter player %d details:\n", i + 1);
        printf("Player Name: ");
        scanf("%s", playerName); 
        printf("Team Name: ");
        scanf("%s", teamName); 
        printf("Batting Average: ");
        scanf("%f", &battingAverage);

        insertPlayer(&head, playerName, teamName, battingAverage);
    }

    displayPlayers(head);

    return 0;
}
