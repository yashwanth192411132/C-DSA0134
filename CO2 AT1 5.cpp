#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string productName;
    float price;
    int quantity;

public:
    static int totalProducts;

    void getData()
    {
        cout << "\nEnter Product Name: ";
        cin >> productName;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;

        // Validation
        if(price <= 0 || quantity <= 0)
        {
            cout << "Invalid Price or Quantity!\n";
            price = 0;
            quantity = 0;
        }
        else
        {
            totalProducts++;
        }
    }

    float calculateTotal()
    {
        return price * quantity;
    }

    void display()
    {
        cout << "\nProduct Name : " << productName;
        cout << "\nPrice        : " << price;
        cout << "\nQuantity     : " << quantity;
        cout << "\nTotal Cost   : " << calculateTotal() << endl;
    }
};

int Product::totalProducts = 0;

int main()
{
    int n;
    float totalBill = 0;

    cout << "Enter Number of Products: ";
    cin >> n;

    Product p[100];   // Array of objects

    for(int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << ":";
        p[i].getData();
    }

    cout << "\n----- Shopping Cart Details -----\n";

    for(int i = 0; i < n; i++)
    {
        p[i].display();
        totalBill += p[i].calculateTotal();
    }

    cout << "\nTotal Products Added : "
         << Product::totalProducts << endl;

    cout << "Final Bill Amount : "
         << totalBill << endl;

    return 0;
}
