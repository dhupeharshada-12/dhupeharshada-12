#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> courses;
    int choice;

    do
    {
        cout << "\n===== STUDENT COURSE PLANNER =====\n";
        cout << "1. Add Course\n";
        cout << "2. Show Courses\n";
        cout << "3. Search Course\n";
        cout << "4. Remove Course\n";
        cout << "5. Count Courses\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string course;

                cout << "Enter course name: ";
                cin.ignore();
                getline(cin, course);

                courses.push_back(course);

                cout << "Course added successfully!\n";
                break;
            }

            case 2:
            {
                if (courses.empty())
                {
                    cout << "No courses added yet.\n";
                }
                else
                {
                    cout << "\n--- My Courses ---\n";

                    for (int i = 0; i < courses.size(); i++)
                    {
                        cout << i + 1 << ". "
                             << courses[i] << endl;
                    }
                }

                break;
            }

            case 3:
            {
                string searchCourse;
                bool found = false;

                cout << "Enter course to search: ";
                cin.ignore();
                getline(cin, searchCourse);

                for (string course : courses)
                {
                    if (course == searchCourse)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                    cout << "Course found!\n";
                else
                    cout << "Course not found.\n";

                break;
            }

            case 4:
            {
                int number;

                cout << "Enter course number to remove: ";
                cin >> number;

                if (number >= 1 && number <= courses.size())
                {
                    courses.erase(courses.begin() + number - 1);
                    cout << "Course removed successfully!\n";
                }
                else
                {
                    cout << "Invalid course number.\n";
                }

                break;
            }

            case 5:
                cout << "Total Courses: "
                     << courses.size() << endl;
                break;

            case 6:
                cout << "Exiting Course Planner...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
