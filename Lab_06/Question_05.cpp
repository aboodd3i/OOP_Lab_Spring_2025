// OOP Lab 06 Question 05 - BCS2H 24K0977
#include <iostream>
using namespace std;

class Device
{
private:
    string isOn;

protected:
    int deviceID;
    bool status;

public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status)
    { // parameterised

        if (status == 1)
        {
            isOn = "Device is ON";
        }
        else
        {
            isOn = "Device is OFF";
        }
    }

    void displayDetails()
    {
        cout << endl
             << "Device ID: " << deviceID << endl
             << "Current Status: " << isOn << endl;
    }
};

class SmartPhone : public Device
{
protected:
    float screenSize;

public:
    SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Display Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public Device
{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int deviceID, bool status, bool heartRateMonitor) : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails()
    {
        cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch
{
private:
    int stepCounter;

public:
    SmartWearable(int deviceID, bool status, bool heartRateMonitor, float screenSize, int stepCounter) : SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails()
    {
        SmartPhone::displayDetails();
        SmartWatch::displayDetails();
        cout << "Steps: " << stepCounter << endl;
    }
};

int main()
{
    SmartWearable w1(12345678, true, 148, 6.78, 10000);

    w1.displayDetails();

    return 0;
}
