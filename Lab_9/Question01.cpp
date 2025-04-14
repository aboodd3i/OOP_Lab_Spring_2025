#include "iostream"
using namespace std;

class Vehicle
{
protected:
    string model;
    double rate;

public:
    Vehicle(double rate, string model) : rate(rate), model(model) {}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle
{
public:
    Car(double rate, string model) : Vehicle(rate, model) {}

    double getDailyRate() override
    {
        return rate;
    }
    void displayDetails() override
    {
        cout << "The model of the car is: " << model << endl
             << "The daily rate of car is: " << getDailyRate() << endl;
    }
};

class Bike : public Vehicle
{
public:
    Bike(double rate, string model) : Vehicle(rate, model) {}
    double getDailyRate() override
    {
        return rate;
    }
    void displayDetails() override
    {
        cout << "The model of the bike is: " << model << endl
             << "The daily rate of bike is: " << getDailyRate() << endl;
    }
};

int main()
{
    Bike bike(500, "Yamaha YBR 125G");
    Car car(1500, "Honda Civic");

    bike.displayDetails();
    car.displayDetails();
}
