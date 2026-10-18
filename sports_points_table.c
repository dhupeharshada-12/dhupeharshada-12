#include <stdio.h>
#include <string.h>

#define MAX_TEAMS 20

struct Team {
    char name[50];
    int played;
    int wins;
    int draws;
    int losses;
    int points;
};

struct Team teams[MAX_TEAMS];
int teamCount = 0;

int findTeam(const char name[]) {
    for (int i = 0; i < teamCount; i++) {
        if (strcmp(teams[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void addTeam() {
    if (teamCount >= MAX_TEAMS) {
        printf("Maximum team limit reached!\n");
        return;
    }

    char name[50];

    printf("Enter team name: ");
    scanf(" %49[^\n]", name);

    if (findTeam(name) != -1) {
        printf("Team already exists!\n");
        return;
    }

    strcpy(teams[teamCount].name, name);
    teams[teamCount].played = 0;
    teams[teamCount].wins = 0;
    teams[teamCount].draws = 0;
    teams[teamCount].losses = 0;
    teams[teamCount].points = 0;

    teamCount++;

    printf("Team added successfully!\n");
}

void recordMatch() {
    if (teamCount < 2) {
        printf("Add at least two teams first.\n");
        return;
    }

    char name1[50], name2[50];
    int score1, score2;

    printf("Enter first team name: ");
    scanf(" %49[^\n]", name1);

    int t1 = findTeam(name1);

    if (t1 == -1) {
        printf("First team not found!\n");
        return;
    }

    printf("Enter second team name: ");
    scanf(" %49[^\n]", name2);

    int t2 = findTeam(name2);

    if (t2 == -1 || t1 == t2) {
        printf("Invalid second team!\n");
        return;
    }

    printf("Enter score for %s: ", name1);

    if (scanf("%d", &score1) != 1 || score1 < 0) {
        printf("Invalid score!\n");
        return;
    }

    printf("Enter score for %s: ", name2);

    if (scanf("%d", &score2) != 1 || score2 < 0) {
        printf("Invalid score!\n");
        return;
    }

    teams[t1].played++;
    teams[t2].played++;

    if (score1 > score2) {
        teams[t1].wins++;
        teams[t1].points += 3;

        teams[t2].losses++;
    }
    else if (score2 > score1) {
        teams[t2].wins++;
        teams[t2].points += 3;

        teams[t1].losses++;
    }
    else {
        teams[t1].draws++;
        teams[t2].draws++;

        teams[t1].points++;
        teams[t2].points++;
    }

    printf("Match result recorded successfully!\n");
}

void displayTable() {
    if (teamCount == 0) {
        printf("No teams available!\n");
        return;
    }

    struct Team sorted[MAX_TEAMS];

    for (int i = 0; i < teamCount; i++) {
        sorted[i] = teams[i];
    }

    for (int i = 0; i < teamCount - 1; i++) {
        for (int j = 0; j < teamCount - i - 1; j++) {
            if (sorted[j].points < sorted[j + 1].points) {
                struct Team temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    printf("\n========== POINTS TABLE ==========\n");
    printf("%-20s %5s %4s %4s %4s %6s\n",
           "Team", "P", "W", "D", "L", "Points");

    for (int i = 0; i < teamCount; i++) {
        printf("%-20s %5d %4d %4d %4d %6d\n",
               sorted[i].name,
               sorted[i].played,
               sorted[i].wins,
               sorted[i].draws,
               sorted[i].losses,
               sorted[i].points);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== SPORTS TOURNAMENT MANAGER =====\n");
        printf("1. Add Team\n");
        printf("2. Record Match Result\n");
        printf("3. Display Points Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear invalid input */
            }

            continue;
        }

        switch (choice) {
            case 1:
                addTeam();
                break;

            case 2:
                recordMatch();
                break;

            case 3:
                displayTable();
                break;

            case 4:
                printf("Tournament manager closed.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
