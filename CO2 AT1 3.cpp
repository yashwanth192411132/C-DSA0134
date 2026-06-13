#include <iostream>
using namespace std;

class Warehouse
{
private:
    int itemID, quantity;
    string name, location;

public:
    static int totalItems;

    void input()
    {
        cout << "Enter Item ID: ";
        cin >> itemID;

        cout << "Enter Item Name: ";
        cin >> name;

        cout << "Enter Quantity: ";
        cin >> quantity;

        if (quantity < 0)
        {
            cout << "Invalid Quantity!\n";
            quantity = 0;
        }

        cout << "Enter Location: ";
        cin >> location;

        totalItems++;
    }

    void addStock(int qty)
    {
        quantity += qty;
    }

    void removeStock(int qty)
    {
        if (qty <= quantity)
            quantity -= qty;
        else
            cout << "Not enough stock!\n";
    }

    void display()
    {
        cout << "\nItem ID : " << itemID;
        cout << "\nName    : " << name;
        cout << "\nQuantity: " << quantity;
        cout << "\nLocation: " << location << endl;
    }
};

int Warehouse::totalItems = 0;

int main()
{
    int n;

    cout << "Enter Number of Items: ";
    cin >> n;

    Warehouse w[10];

    for (int i = 0; i < n; i++)
    {
        cout << "\nItem " << i + 1 << endl;
        w[i].input();
    }

    cout << "\n--- Inventory Details ---\n";

    for (int i = 0; i < n; i++)
    {
        w[i].display();
    }

    cout << "\nTotal Items Stored: "
         << Warehouse::totalItems;

    return 0;
}
