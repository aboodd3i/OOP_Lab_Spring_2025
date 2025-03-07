// OOP Lab 06 Question 03 - BCS2H 24K0977
#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {} // parameterised

    void displayDetails()
    {
        cout << endl
             << "Name: " << name << endl
             << "Age: " << age << endl;
    }
};

class Teacher : public Person
{
protected:
    string subject;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {} // parametised

    void displayDetails()
    {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : public Person
{
protected:
    string researchArea;

public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {} // parametised

    void displayDetials()
    {
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Researcher, public Teacher
{
private:
    int publications;

public:
    Professor(string name, int age, string subject, string researchArea, int publications) : Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {} // parameterised

    void displayDetails()
    {
        Teacher::displayDetails();
        Researcher::displayDetials();
        cout << "Number of Publications: " << publications << endl;
    }
};

int main()
{
    Professor p1("Muhammad Rahim", 35, "Applied Physics", "Physics", 5);
    Professor p2("Talha Shahid", 26, "Object Oriented Programming", "C++", 13);

    p1.displayDetails();
    p2.displayDetails();
}
