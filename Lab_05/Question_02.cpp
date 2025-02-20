// Muhammad Abdullah 24K0977 - OOP Lab 05 Question 02

#include <iostream>
using namespace std;

class Patient
{
private:
    int ID, amount, *arrayOfTests;
    string name;

public:
    Patient(string name, int id, int num, int *arr)
    {
        ID = id;
        this->name = name;
        amount = num;
        arrayOfTests = new int(amount);
        for (int i = 0; i < amount; i++)
        {
            arrayOfTests[i] = arr[i];
        }
    }

    Patient(const Patient &object)
    {
        ID = object.ID + 1;
        name = object.name;
        amount = object.amount;
        arrayOfTests = new int(amount);
        for (int i = 0; i < amount; i++)
        {
            arrayOfTests[i] = object.arrayOfTests[i];
        }
    }

    ~Patient()
    {
        delete[] arrayOfTests;
        cout << "\n\nDESTRUCTOR HAS BEEN CALLED\n\n";
    }

    void display()
    {
        cout << "Patient ID: " << ID << endl
             << "Patient Name: " << name << endl
             << "Patient's Results: " << endl;
        for (int i = 0; i < amount; i++)
        {
            cout << arrayOfTests[i] << ", ";
        }
        cout << endl;
    }
};

int main()
{
    int results[] = {100, 29, 69, 120, 19};
    int numOfResults = 5;

    Patient patient01("Muhammad Abdullah", 0001, numOfResults, results);
    patient01.display();

    Patient patient02(patient01);
    patient02.display();
}
