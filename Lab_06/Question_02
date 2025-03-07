// OOP Lab 06 Question 02 - BCS2H 24K0977
#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string brand;
    int speed;

public:
    Vehicle() // default
    {
        brand = " ";
        speed = 0;
    }
    Vehicle(string brand, int speed) : brand(brand), speed(speed) {} // parameterised

    void displayDetails()
    {
        cout << endl
             << "Displaying Details: " << endl
             << "Brand: " << brand << endl
             << "Top Speed: " << speed << "kph" << endl;
    }
};

class Car : public Vehicle
{
protected:
    int seats;

public:
    Car()
    { // default
        seats = 0;
    }
    Car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {} // parameterised

    void displayDetails()
    {
        Vehicle::displayDetails();
        cout << "Seating Capacity: " << seats << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryLife;

public:
    ElectricCar()
    { // default
        batteryLife = 0;
    }
    ElectricCar(string brand, int speed, int seats, int batteryLife) : Car(brand, speed, seats), batteryLife(batteryLife) {} // parametirsed

    void displayDetails()
    {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " Kilometers" << endl;
    }
};

int main()
{
    ElectricCar car1("Tesla Model X", 180, 7, 500);
    ElectricCar car2("Tesla Plaid", 250, 4, 650);
    ElectricCar car3("Lucid Air Grand Touring", 235, 4, 600);

    car1.displayDetails();
    car2.displayDetails();
    car3.displayDetails();
}
