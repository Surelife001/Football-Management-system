#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char position[MAX_NAME_LENGTH];
    int jersey_number;
} Player;

void initializePlayers(Player players[], int *playerCount) {
    *playerCount = 0;
}

void addPlayer(Player players[], int *playerCount) {
    if (*playerCount >= MAX_PLAYERS) {
        printf("Team is full. Cannot add more players.\n");
        return;
    }

    printf("Enter player name: ");
    scanf(" %[^\n]", players[*playerCount].name);
    printf("Enter player age: ");
    scanf("%d", &players[*playerCount].age);
    printf("Enter player position: ");
    scanf(" %[^\n]", players[*playerCount].position);
    printf("Enter player jersey number: ");
    scanf("%d", &players[*playerCount].jersey_number);

    (*playerCount)++;
    printf("Player added successfully.\n");
}

void viewPlayers(Player players[], int playerCount) {
    if (playerCount == 0) {
        printf("No players in the team.\n");
        return;
    }

    printf("Name\t\tAge\tPosition\tJersey Number\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s\t\t%d\t%s\t\t%d\n", players[i].name, players[i].age, players[i].position, players[i].jersey_number);
    }
}

void searchPlayer(Player players[], int playerCount) {
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter player name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, name) == 0) {
            printf("Player found: %s, Age: %d, Position: %s, Jersey Number: %d\n", players[i].name, players[i].age, players[i].position, players[i].jersey_number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Player not found.\n");
    }
}

void removePlayer(Player players[], int *playerCount) {
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter player name to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < *playerCount; i++) {
        if (strcmp(players[i].name, name) == 0) {
            for (int j = i; j < *playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            (*playerCount)--;
            found = 1;
            printf("Player removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Player not found.\n");
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;
    int choice;

    initializePlayers(players, &playerCount);

    do {
        printf("\nFootball Team Management System\n");
        printf("1. Add Player\n");
        printf("2. View Players\n");
        printf("3. Search Player\n");
        printf("4. Remove Player\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer(players, &playerCount);
                break;
            case 2:
                viewPlayers(players, playerCount);
                break;
            case 3:
                searchPlayer(players, playerCount);
                break;
            case 4:
                removePlayer(players, &playerCount);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
