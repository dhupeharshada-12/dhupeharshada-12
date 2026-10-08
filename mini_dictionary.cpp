#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> dictionary;

    dictionary["algorithm"] = "A step-by-step method to solve a problem.";
    dictionary["variable"] = "A named storage location for data.";
    dictionary["compiler"] = "A program that converts source code into machine code.";
    dictionary["function"] = "A reusable block of code that performs a task.";
    dictionary["pointer"] = "A variable that stores the address of another variable.";

    int choice;
    string word;

    do {
        cout << "\n===== MINI DICTIONARY =====\n";
        cout << "1. Search Word\n";
        cout << "2. Show All Words\n";
        cout << "3. Add New Word\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter word: ";
            cin >> word;

            auto it = dictionary.find(word);

            if (it != dictionary.end()) {
                cout << "Meaning: " << it->second << endl;
            } else {
                cout << "Word not found.\n";
            }
        }

        else if (choice == 2) {
            cout << "\n--- Dictionary Words ---\n";

            for (const auto &entry : dictionary) {
                cout << entry.first << " : "
                     << entry.second << endl;
            }
        }

        else if (choice == 3) {
            string meaning;

            cout << "Enter new word: ";
            cin >> word;

            cin.ignore();

            cout << "Enter meaning: ";
            getline(cin, meaning);

            dictionary[word] = meaning;

            cout << "Word added successfully!\n";
        }

        else if (choice == 4) {
            cout << "Dictionary closed.\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
