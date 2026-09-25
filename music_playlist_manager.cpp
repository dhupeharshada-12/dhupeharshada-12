#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> playlist;
    int choice;
    string song;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Show Playlist\n";
        cout << "3. Search Song\n";
        cout << "4. Remove Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter song name: ";
            cin.ignore();
            getline(cin, song);

            playlist.push_back(song);
            cout << "Song added successfully!\n";
        }
        else if (choice == 2)
        {
            if (playlist.empty())
            {
                cout << "Playlist is empty.\n";
            }
            else
            {
                cout << "\n--- Your Playlist ---\n";

                for (int i = 0; i < playlist.size(); i++)
                {
                    cout << i + 1 << ". " << playlist[i] << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Enter song to search: ";
            cin.ignore();
            getline(cin, song);

            bool found = false;

            for (string currentSong : playlist)
            {
                if (currentSong == song)
                {
                    found = true;
                    break;
                }
            }

            if (found)
                cout << "Song found in playlist!\n";
            else
                cout << "Song not found.\n";
        }
        else if (choice == 4)
        {
            int number;

            cout << "Enter song number to remove: ";
            cin >> number;

            if (number >= 1 && number <= playlist.size())
            {
                playlist.erase(playlist.begin() + number - 1);
                cout << "Song removed successfully!\n";
            }
            else
            {
                cout << "Invalid song number.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Thank you for using Playlist Manager!\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
