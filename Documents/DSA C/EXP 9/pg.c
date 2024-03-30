#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Structure to store cricket player details
struct Player {
    char name[50];
    char team[50];
    float batting_avg;
    struct Player *next;
};

// Function to create a new player node
struct Player *create_player(char *name, char *team, float avg) {
    struct Player *new_player = (struct Player *)malloc(sizeof(struct Player));
    strcpy(new_player->name, name);
    strcpy(new_player->team, team);
    new_player->batting_avg = avg;
    new_player->next = NULL;
    return new_player;
}

// Function to insert a player node at the end of the list
void insert_at_end(struct Player **head, char *name, char *team, float avg) {
    struct Player *new_player = create_player(name, team, avg);
    if (*head == NULL) {
        *head = new_player;
        return;
    }

    struct Player *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_player;
}

// Function to display player information
void display_player(struct Player *player) {
    printf("Player Name: %s\n", player->name);
    printf("Team Name: %s\n", player->team);
    printf("Batting Average: %.2f\n\n", player->batting_avg);
}

// Function to print players with batting average >= 50
void print_high_avg_players(struct Player *head) {
    struct Player *temp = head;
    printf("Players with Batting Average >= 50:\n");
    while (temp != NULL) {
        if (temp->batting_avg >= 50) {
            display_player(temp);
        }
        temp = temp->next;
    }
}

int main() {
    struct Player *head = NULL;

    // Sample data (modify as needed)
    // insert_at_end(&head, "Virat Kohli", "RCB", 58.4);
    // insert_at_end(&head, "Rohit Sharma", "MI", 48.9);
    // insert_at_end(&head, "KL Rahul", "PBKS", 47.5);
    // insert_at_end(&head, "Jasprit Bumrah", "MI", 27.6);
    // insert_at_end(&head, "Ravindra Jadeja", "CSK", 36.4);

    // print_high_avg_players(head);

    return 0;
}
