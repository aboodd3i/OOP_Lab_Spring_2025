// Muhammad Abdullah 24K0977 - OOP Lab 05 Question 07

#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    int itemCode;
    string itemName;
    double itemPrice;

public:
    Item()
    {
        itemCode = 0;
        itemName = "Unnamed";
        itemPrice = 0.00;
    }

    Item(int code, string name, double price)
    {
        itemCode = code;
        itemName = name;
        itemPrice = price;
    }

    void showDetails() const
    {
        cout << "Code: " << itemCode << ", Product: " << itemName << ", Cost: $" << itemPrice << endl;
    }

    int getCode() const { return itemCode; }
    string getProduct() const { return itemName; }
    double getCost() const { return itemPrice; }
};

class Stock
{
private:
    string stockName;
    Item *inventory;
    int itemCount;
    int capacity = 100;

public:
    Stock(string s)
    {
        stockName = s;
        itemCount = 0;
        inventory = new Item[capacity];
    }

    void addItem(Item &itm)
    {
        if (itemCount < capacity)
        {
            inventory[itemCount] = itm;
            itemCount++;
        }
        else
        {
            cout << "Stock is at full capacity!" << endl;
        }
    }

    void arrangeByCost()
    {
        for (int i = 0; i < itemCount - 1; i++)
        {
            for (int j = i + 1; j < itemCount; j++)
            {
                if (inventory[i].getCost() < inventory[j].getCost())
                {
                    Item temp = inventory[i];
                    inventory[i] = inventory[j];
                    inventory[j] = temp;
                }
            }
        }
    }

    void findByName(string searchName)
    {
        bool located = false;
        for (int i = 0; i < itemCount; i++)
        {
            if (inventory[i].getProduct() == searchName)
            {
                cout << "Product Located: ";
                inventory[i].showDetails();
                located = true;
                break;
            }
        }
        if (!located)
        {
            cout << "No matching product found." << endl;
        }
    }

    void showStock()
    {
        cout << "Stock Name: " << stockName << endl;
        for (int i = 0; i < itemCount; i++)
        {
            inventory[i].showDetails();
        }
    }

    ~Stock()
    {
        delete[] inventory;
    }
};

int main()
{
    Stock electronicsStore("Tech World Inventory");

    Item i1(101, "Gaming Laptop", 1400.99);
    Item i2(102, "Smartphone Pro", 999.49);
    Item i3(103, "Drawing Tablet", 650.30);
    Item i4(104, "Wireless Earbuds", 199.95);
    Item i5(105, "Mechanical Keyboard", 89.99);

    electronicsStore.addItem(i1);
    electronicsStore.addItem(i2);
    electronicsStore.addItem(i3);
    electronicsStore.addItem(i4);
    electronicsStore.addItem(i5);

    // Displaying initial stock
    cout << "Current Stock List:" << endl;
    electronicsStore.showStock();

    // Sorting by price
    electronicsStore.arrangeByCost();
    cout << "\nStock Sorted by Price (Highest to Lowest):" << endl;
    electronicsStore.showStock();

    // Searching for items
    cout << "\nSearching for 'Drawing Tablet':" << endl;
    electronicsStore.findByName("Drawing Tablet");
    cout << "\nSearching for 'Smartwatch':" << endl;
    electronicsStore.findByName("Smartwatch");

    return 0;
}
