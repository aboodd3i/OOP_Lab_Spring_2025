// Muhammad Abdullah 24K0977 - OOP Lab 05 Question 04

#include <iostream>
using namespace std;

class Battery
{
private:
    int capacity;
    string batteryModel;

public:
    Battery()
    {
        capacity = 0;
        batteryModel = "XX-0000";
    }

    Battery(int cap, string model)
    {
        capacity = cap;
        batteryModel = model;
    }

    ~Battery()
    {
        cout << "\nObject of " << batteryModel << " has been destroyed!\n";
    }

    void setCapacity(int c)
    {
        capacity = c;
    }

    void setBattteryModel(string m)
    {
        batteryModel = m;
    }

    int getCapacity()
    {
        return capacity;
    }

    string getBatteryModel()
    {
        return batteryModel;
    }
};

class CellPhone
{
private:
    string phoneModel;
    Battery powerBrick;

public:
    CellPhone()
    {
        phoneModel = "Brand - Model";
    }

    CellPhone(string model)
    {
        phoneModel = model;
    }

    ~CellPhone()
    {
        cout << "\nObject of " << phoneModel << " has been destroyed!";
    }

    void selectBattery()
    {
        cout << "\nPlease choose a battery for your " << phoneModel << endl;
        cout << "1. SX-0505 5000mAh \n2. PQ-1234 4000mAh \n3. WT-9980 5500mAh\n";
        cout << "Enter you choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            powerBrick.setCapacity(5000);
            powerBrick.setBattteryModel("SX-0505");
            break;
        case 2:
            powerBrick.setCapacity(4000);
            powerBrick.setBattteryModel("PQ-1234");
            break;
        case 3:
            powerBrick.setCapacity(5500);
            powerBrick.setBattteryModel("WT-9980");
            break;

        default:
            cout << "Select again.";
            break;
        }
    }

    void displayDetails()
    {
        cout << "\nPhone Model: " << phoneModel << endl
             << "Battery Model: " << powerBrick.getBatteryModel() << endl
             << "Battery Capacity: " << powerBrick.getCapacity() << endl;
    }
};

int main()
{
    CellPhone phone01("Iphone 15 Pro Max");
    phone01.selectBattery();

    CellPhone phone02("Samsung Galaxy S25 Ultra");
    phone02.selectBattery();

    CellPhone phone03("Google Pixel 9");
    phone03.selectBattery();

    phone01.displayDetails();
    phone02.displayDetails();
    phone03.displayDetails();

    return 0;
}
