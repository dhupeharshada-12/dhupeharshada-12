#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int length;

    char characters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*";

    int charactersLength = sizeof(characters) - 1;

    cout << "===== Password Generator =====" << endl;

    cout << "Enter Password Length: ";
    cin >> length;

    srand(time(0));

    cout << "\nGenerated Password: ";

    for(int i = 0; i < length; i++)
    {
        cout << characters[rand() % charactersLength];
    }

    cout << endl;

    return 0;
}
