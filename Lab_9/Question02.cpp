#include "iostream"
using namespace std;

class SmartDevice {
protected:
bool status;     

public:
SmartDevice(bool status) : status(status) {}

virtual void turnOn() = 0;
virtual void turnOff() = 0;
virtual void getStatus() = 0;
};

class LightBulb : public SmartDevice{
    private:
    bool isOn;
    int brightness;

    public:
    LightBulb(bool status, int brightness) : SmartDevice(status), isOn(status), brightness(brightness) {}
    void turnOn() override {
        if (isOn) {
            cout << "The Bulb is already on!!!\n";
            return;
        }
        isOn = 1;
        cout << "Light Bulb Turned On at Brightness of " << brightness << "%!\n";
    }
     void turnOff() override {
        if (!isOn) {
            cout << "The Bulb is already off!!!\n";
            return;
        }
        isOn = 0;
        cout << "Light Bulb Turned Off!\n";
    }
    void getStatus() override {
        if (isOn) {
            cout << "The Bulb is Currently On at Brightness of " << brightness << "%.\n";
        }
        else{ 
            cout << "The Bulb is Currently Off.\n";
        }
    }

};

class Thermostat : public SmartDevice{
    private:
    bool isOn;
    int temp;

    public:
    Thermostat(bool status, int temp) : SmartDevice(status), isOn(status), temp(temp) {}
    void turnOn() override {
        if (isOn) {
            cout << "The Thermostat is already on!!!\n";
            return;
        }
        isOn = 1;
        cout << "Thermostat Turned On at Temperature of " << temp << " F!\n";
    }
     void turnOff() override {
        if (!isOn) {
            cout << "The Thermostat is already off!!!\n";
            return;
        }
        isOn = 0;
        cout << "Thermostat Turned Off!\n";
    }
    void getStatus() override {
        if (isOn) {
            cout << "The Thermostat is Currently On at Temperature of " << temp << " F.\n";
        }
        else{ 
            cout << "The Thermostat is Currently Off.\n";
        }
    }

};

int main() {
    LightBulb bulb(1, 69);
    Thermostat thermostat(0, 16);

    bulb.getStatus();
    thermostat.getStatus();

    bulb.turnOn();
    thermostat.turnOn();

    bulb.getStatus();
    thermostat.getStatus();

    bulb.turnOff();
    thermostat.turnOff();

    bulb.getStatus();
    thermostat.getStatus();

    return 0;


}
