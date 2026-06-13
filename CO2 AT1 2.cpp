#include <iostream>
using namespace std;

class Member
{
private:
    int memberID;
    string name, planType;
    int fee;

public:
    static int totalMembers;

    void input()
    {
        cout << "Enter Member ID: ";
        cin >> memberID;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Plan Type (Basic/Premium/VIP): ";
        cin >> planType;

        calculateFee();
        totalMembers++;
    }

    void calculateFee()
    {
        if (planType == "Basic")
            fee = 1000;
        else if (planType == "Premium")
            fee = 2000;
        else if (planType == "VIP")
            fee = 3000;
        else
        {
            cout << "Invalid Plan!\n";
            fee = 0;
        }
    }

    void display()
    {
        cout << "\nMember ID : " << memberID;
        cout << "\nName      : " << name;
        cout << "\nPlan Type : " << planType;
        cout << "\nFee       : Rs." << fee << endl;
    }
};

int Member::totalMembers = 0;

int main()
{
    int n;

    cout << "Enter Number of Members: ";
    cin >> n;

    Member m[10];

    for (int i = 0; i < n; i++)
    {
        cout << "\nMember " << i + 1 << endl;
        m[i].input();
    }

    cout << "\n--- Membership Details ---\n";

    for (int i = 0; i < n; i++)
    {
        m[i].display();
    }

    cout << "\nTotal Active Members: "
         << Member::totalMembers;

    return 0;
}
