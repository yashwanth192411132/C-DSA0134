#include <iostream>
using namespace std;

class Violation
{
private:
    string vehicleNo, ownerName, violationType;
    int fineAmount;

public:
    static int totalViolations;

    void input()
    {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNo;

        cout << "Enter Owner Name: ";
        cin >> ownerName;

        cout << "Enter Violation Type (SignalJump/NoHelmet/Overspeed): ";
        cin >> violationType;

        calculateFine();
        totalViolations++;
    }

    void calculateFine()
    {
        if (violationType == "SignalJump")
            fineAmount = 1000;
        else if (violationType == "NoHelmet")
            fineAmount = 500;
        else if (violationType == "Overspeed")
            fineAmount = 1500;
        else
        {
            cout << "Invalid Violation Type!\n";
            fineAmount = 0;
        }
    }

    void display()
    {
        cout << "\nVehicle Number : " << vehicleNo;
        cout << "\nOwner Name     : " << ownerName;
        cout << "\nViolation Type : " << violationType;
        cout << "\nFine Amount    : " << fineAmount << endl;
    }
};

int Violation::totalViolations = 0;

int main()
{
    int n;

    cout << "Enter Number of Violations: ";
    cin >> n;

    Violation v[10];

    for (int i = 0; i < n; i++)
    {
        cout << "\nViolation " << i + 1 << endl;
        v[i].input();
    }

    cout << "\n--- Violation Report ---\n";

    for (int i = 0; i < n; i++)
    {
        v[i].display();
    }

    cout << "\nTotal Violations Recorded: "
         << Violation::totalViolations;

    return 0;
}
