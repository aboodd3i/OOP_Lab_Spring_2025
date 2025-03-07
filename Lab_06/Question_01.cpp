// OOP Lab 06 Question 01 - BCS2H 24K0977

#include <iostream>
using namespace std;

class Employees
{
protected:
    string name;
    float salary;

public:
    Employees() // default
    {
        name = " ";
        salary = 0.0;
    }
    Employees(string name, float salary) : name(name), salary(salary) {} // parametarised

    void displayDetails()
    {
        cout << endl
             << "Name: " << name << endl
             << "Salary: $" << salary << endl;
    }
};

class Managers : public Employees
{
private:
    float bonus, salaryAfterBonus;

public:
    Managers()
    {
        bonus = 0.0;
        salaryAfterBonus = 0.0;
    }
    Managers(string name, float salary, float bonus) : Employees(name, salary), bonus(bonus)
    {
        salaryAfterBonus = salary * (1 + (bonus / 100));
    }

    void displayDetails()
    {
        Employees::displayDetails();
        cout << "Bonus: " << bonus << "%" << endl
             << "Salary After Bonus: $" << salaryAfterBonus << endl;
    }
};

int main()
{
    Managers m1("Muhammad Abdullah", 12000, 10);
    Managers m2("Muhammad Saad Sohail", 15500, 15.5);

    m1.displayDetails();
    m2.displayDetails();
}
