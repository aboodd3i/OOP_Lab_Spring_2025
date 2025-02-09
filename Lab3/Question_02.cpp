#include <iostream>
using namespace std;

class TeaMug
{
private:
    string brand, color;
    int capacity, currentFillLevel;
    bool refill;

public:
    TeaMug(string b, string c, int cap, int level, bool r)
    {
        brand = b;
        color = c;
        capacity = cap;
        currentFillLevel = level;
        refill = r;
    }

    void sipTea(int drink)
    {
        if (currentFillLevel == 0)
        {
            cout << "\nThe cup is empty.\nWould you like to refill the cup? (Y/N)\n";
            char choice;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                refill = true;
                refillTea(refill);
            }
        }
        else if (currentFillLevel < drink)
        {
            cout << "There is only " << currentFillLevel << "% tea in the cup.\nThe cup is now empty, would you like to refill? (Y/N)";
            char choice;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                refill = true;
                refillTea(refill);
            }
        }
        else
        {
            cout << "\nEnjoy your drink!!\n";
            currentFillLevel -= drink;
            cout << "There is now " << currentFillLevel << "% tea left in the cup" << endl;
        }
    }

    void refillTea(bool r)
    {
        if (r)
        {
            if (currentFillLevel == capacity)
            {
                cout << "The cup is already full!\n";
            }
            else
            {
                currentFillLevel = capacity;
                cout << "Your tea has been refilled to " << capacity << "%. This is the current cup's maximum capacity.";
            }
        }
        else
        {
            cout << "Cup cannot be refilled. Pleae make sure the refill status is set to True.";
        }
    }

    void checkStatus()
    {
        cout << "\nFollowing is the status of the current cup:\n";
        cout << "Brand: " << brand << endl;
        cout << "Color: " << color << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Current Tea Level: " << currentFillLevel << endl;
    }
};

int main()
{
    cout << "--- TEA MUG STATUS MONITOR! ---";
    cout << "\n\nPlease add the following details for your tea mug:\n";
    cout << "Brand: ";
    string brand;
    cin >> brand;
    cout << endl;
    cout << "Color: ";
    string color;
    cin >> color;
    cout << endl;
    cout << "Capacity: ";
    int capacity;
    cin >> capacity;
    cout << endl;
    int currentFillLevel = capacity;
    bool refill = (capacity == 0);
    cout << "Your mug has been refilled to the maximum capacity, which is " << capacity << endl;

    TeaMug mug1(brand, color, capacity, currentFillLevel, refill);

    while (true)
    {
        cout << "\n-- Main Menu --\n";
        cout << "1. Drink Tea.\n";
        cout << "2. Refill Mug.\n";
        cout << "3. Check Status.\n";
        cout << "4. Exit.\n";
        cout << "Please enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Please enter the amount of tea you want to drink: ";
            int amount;
            cin >> amount;
            mug1.sipTea(amount);
            break;

        case 2:
            refill = true;
            mug1.refillTea(refill);
            break;

        case 3:
            mug1.checkStatus();
            break;

        case 4:
            cout << "Exiting the program. Thank You!";
            return 0;

        default:
            cout << "Incorrect selection. Try again.";
        }
    }

    return 0;
}
