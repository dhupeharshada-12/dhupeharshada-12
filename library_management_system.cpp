#include <iostream>
using namespace std;

int main()
{
    int choice;
    int totalBooks = 100;
    int issuedBooks = 0;
    int books;

    do
    {
        cout << "\n===== Library Management System =====" << endl;

        cout << "1. Show Available Books" << endl;
        cout << "2. Issue Books" << endl;
        cout << "3. Return Books" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Available Books: "
                     << totalBooks - issuedBooks << endl;
                break;

            case 2:
                cout << "Enter Number of Books to Issue: ";
                cin >> books;

                if(issuedBooks + books <= totalBooks)
                {
                    issuedBooks += books;
                    cout << "Books Issued Successfully!" << endl;
                }
                else
                {
                    cout << "Not Enough Books Available!" << endl;
                }

                break;

            case 3:
                cout << "Enter Number of Books to Return: ";
                cin >> books;

                if(books <= issuedBooks)
                {
                    issuedBooks -= books;
                    cout << "Books Returned Successfully!" << endl;
                }
                else
                {
                    cout << "Invalid Return!" << endl;
                }

                break;

            case 4:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}
