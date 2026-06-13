#include <iostream>
#include <string>
using namespace std;

class Event
{
private:
    string eventName;
    string participantName;
    int regID;

public:
    static int totalParticipants;
    void registerParticipant(string eName, string pName, int id, Event arr[], int count)
    {
        for(int i = 0; i < count; i++)
        {
            if(arr[i].regID == id)
            {
                cout << "Duplicate Registration ID! Registration Failed.\n";
                return;
            }
        }

        eventName = eName;
        participantName = pName;
        regID = id;
        totalParticipants++;

        cout << "Participant Registered Successfully.\n";
    }

    void display()
    {
        cout << "\nEvent Name      : " << eventName;
        cout << "\nParticipant Name: " << participantName;
        cout << "\nRegistration ID : " << regID << endl;
    }
};

int Event::totalParticipants = 0;

int main()
{
    int n;
    cout << "Enter number of registrations: ";
    cin >> n;

    Event reg[100];

    for(int i = 0; i < n; i++)
    {
        string eName, pName;
        int id;

        cout << "\nEnter Event Name: ";
        cin >> eName;

        cout << "Enter Participant Name: ";
        cin >> pName;

        cout << "Enter Registration ID: ";
        cin >> id;

        reg[i].registerParticipant(eName, pName, id, reg, i);
    }

    cout << "\n Registration Details \n";
    for(int i = 0; i < n; i++)
    {
        reg[i].display();
    }

    cout << "\nTotal Participants Registered: "
         << Event::totalParticipants << endl;

    return 0;
}
