// Muhammad Abdullah 24K0977 - OOP Lab 05 Question 01

#include <iostream>
#include <string.h>
using namespace std;

class Car
{
private:
    string registrationNumber, modelName, ownerName;

public:
    Car()
    {
        registrationNumber = "Unregistered";
        modelName = "Model Name";
        ownerName = "No Current Owner";
    }

    Car(string r, string m, string o)
    {
        registrationNumber = r;
        modelName = m;
        ownerName = o;
        cout << modelName << " with reg. no. " << registrationNumber << " succesfully rented by " << ownerName << endl;
    }

    Car(const Car &object)
    {
        registrationNumber = object.registrationNumber;
        modelName = object.modelName;
        ownerName = object.ownerName;
        cout << "Please enter the new owner's name: ";
        getline(cin, ownerName);
    }

    void display()
    {
        cout << "\nHere are the details for the selected vehicle:\n\n";
        cout << "Vehicle Registration Number: " << registrationNumber << endl
             << "Vehicle Model Name: " << modelName << endl
             << "Vehicle Owner Name: " << ownerName << endl;
    }

    ~Car()
    {
        cout << "DESTRUCTOR CALLED";
    }
};

int main()
{
    Car vehicle01("AJX-969", "Honda BRV", "Abeer Mahmood");
    Car vehicle02("BTQ-213", "Toyota Yaris", "Haider Abbas");

    vehicle01.display();
    vehicle02.display();

    Car vehicle03(vehicle02);
    vehicle03.display();
}
