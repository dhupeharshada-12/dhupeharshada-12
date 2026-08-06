#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Member
{
private:
    int memberId;
    string name;
    string plan;
    int months;
    float fee;

public:
    void addMember()
    {
        cout << "Enter Member ID: ";
        cin >> memberId;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        cout << "Enter Membership Plan (Basic/Premium/VIP): ";
        getline(cin, plan);

        cout << "Enter Duration (Months): ";
        cin >> months;

        if(plan == "Basic")
            fee = months * 1000;
        else if(plan == "Premium")
            fee = months * 1800;
        else if(plan == "VIP")
            fee = months * 2500;
        else
            fee = 0;
    }

    int getMemberId()
    {
        return memberId;
    }

    void display()
    {
        cout << "\n-----------------------------\n";
        cout << "Member ID   : " << memberId << endl;
        cout << "Name        : " << name << endl;
        cout << "Plan        : " << plan << endl;
        cout << "Duration    : " << months << " Months" << endl;
        cout << fixed << setprecision(2);
        cout << "Total Fee   : Rs. " << fee << endl;
    }
};

int main()
{
    vector<Member> members;
    int choice;

    do
    {
        cout << "\n===== Gym Membership Management =====\n";
        cout << "1. Add Member\n";
        cout << "2. View Members\n";
        cout << "3. Search Member\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                Member m;
                m.addMember();
                members.push_back(m);
                cout << "Member Added Successfully!\n";
                break;
            }

            case 2:
            {
                if(members.empty())
                    cout << "No Members Found!\n";
                else
                    for(Member &m : members)
                        m.display();
                break;
            }

            case 3:
            {
                int id;
                cout << "Enter Member ID: ";
                cin >> id;

                bool found = false;

                for(Member &m : members)
                {
                    if(m.getMemberId() == id)
                    {
                        m.display();
                        found = true;
                        break;
                    }
                }

                if(!found)
                    cout << "Member Not Found!\n";

                break;
            }

            case 4:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
