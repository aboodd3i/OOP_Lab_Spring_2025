// Muhammad Abdullah 24K0977 - OOP Lab 05 Question 03

#include <iostream>
using namespace std;

class Professor
{
private:
    string name, department;

public:
    Professor()
    {
        name = "Full Name";
        department = "Deprartment";
    }

    Professor(string n, string d)
    {
        name = n;
        department = d;
    }

    string getName()
    {
        return name;
    }
    string getDepartment()
    {
        return department;
    }
};

class University
{
private:
    string name;
    Professor *professor;
    int count, max = 50;

public:
    University(string n)
    {
        name = n;
        count = 0;
        professor = new Professor[max];
    }

    ~University()
    {
        delete[] professor;
        cout << "\n\nDESTRUCTOR CALLED!\n\n";
    }

    void display()
    {
        cout << "\nHere are the university details:\n\n"
             << "Name: " << name << endl;
        cout << "List of professors: " << endl;
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << professor[i].getName() << " (" << professor[i].getDepartment() << ")\n";
        }
    }

    void addNewTeacher(Professor &object)
    {
        if (count < max)
        {
            professor[count] = object;
            count++;
        }
        else
        {
            cout << "Cannot Add More Professors.\n";
        }
    }
};

int main()
{
    University first("--FAST NUCES - Main Karachi Campus--");
    Professor teacher01("Talha Shahid", "Computer Science");
    Professor teacher02("Atiya Jokio", "Computer Science");
    Professor teacher03("Mariam Aftab", "Computer Science");
    Professor teacher04("Shahid Ashraf", "Computer Science");
    Professor teacher05("Shehzad Sheikh", "AI");
    Professor teacher06("Huma Hafeez", "AI");
    Professor teacher07("Fahad Hussain", "AI");
    Professor teacher08("Muhammad Hasham", "AI");
    Professor teacher09("Javeria Ahmed", "AI");
    Professor teacher10("Muhammad Kashif", "SE");
    Professor teacher11("Omer Farooq", "SE");
    Professor teacher12("Simra Farooq", "SE");
    Professor teacher13("Iftikhar Sheikh", "SE");

    first.addNewTeacher(teacher01);
    first.addNewTeacher(teacher02);
    first.addNewTeacher(teacher03);
    first.addNewTeacher(teacher04);
    first.addNewTeacher(teacher05);
    first.addNewTeacher(teacher06);
    first.addNewTeacher(teacher07);
    first.addNewTeacher(teacher08);
    first.addNewTeacher(teacher09);
    first.addNewTeacher(teacher10);
    first.addNewTeacher(teacher11);
    first.addNewTeacher(teacher12);
    first.addNewTeacher(teacher13);

    first.display();

    return 0;
}
