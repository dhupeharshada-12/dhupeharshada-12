
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Player {
    string name;
    int score;
};

void displayScoreboard(const vector<Player>& players) {
    if (players.empty()) {
        cout << "\nNo players registered yet.\n";
        return;
    }

    cout << "\n===== TOURNAMENT SCOREBOARD =====\n";
    cout << "Rank\tPlayer\t\tScore\n";
    cout << "---------------------------------\n";

    for (int i = 0; i < players.size(); i++) {
        cout << i + 1 << "\t"
             << players[i].name << "\t\t"
             << players[i].score << "\n";
    }
}

int main() {
    vector<Player> players;
    int choice;

    do {
        cout << "\n===== TOURNAMENT MANAGER =====\n";
        cout << "1. Add Player Score\n";
        cout << "2. Display Scoreboard\n";
        cout << "3. Show Highest Scorer\n";
        cout << "4. Sort Scores (Highest First)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            Player p;

            cout << "Enter player name: ";
            cin >> ws;
            getline(cin, p.name);

            cout << "Enter score: ";
            if (!(cin >> p.score) || p.score < 0) {
                cout << "Please enter a valid non-negative score.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            players.push_back(p);
            cout << "Player score added successfully!\n";
        }
        else if (choice == 2) {
            displayScoreboard(players);
        }
        else if (choice == 3) {
            if (players.empty()) {
                cout << "No player data available.\n";
            } else {
                auto best = max_element(
                    players.begin(), players.end(),
                    [](const Player& a, const Player& b) {
                        return a.score < b.score;
                    }
                );

                cout << "\nHighest Scorer: " << best->name
                     << "\nScore: " << best->score << "\n";
            }
        }
        else if (choice == 4) {
            sort(players.begin(), players.end(),
                 [](const Player& a, const Player& b) {
                     return a.score > b.score;
                 });

            cout << "Scores sorted from highest to lowest!\n";
            displayScoreboard(players);
        }
        else if (choice == 5) {
            cout << "Tournament Manager closed. Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
