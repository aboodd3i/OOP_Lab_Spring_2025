#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string line, type, ID, name, year, extraData, certification;
    int numLines = 0, yearInteger, batteryCapacityInteger;
    float softwareVersionFloat;
    ifstream ReadFile("C:/Users/Choudry Shb/Documents/Abdullah_FAST_NUCES/Semester_02/OOP_LAB/OOP_LAB_10/vehicle.txt");

    if (!ReadFile)
    {
        cout << "Could Not Open The File." << endl;
        return 1;
    }

    while (getline(ReadFile, line))
    {
        numLines++;
        if (line.empty())
        {
            continue;
        }

        istringstream stream(line);

        // extract comma seperated values
        getline(stream, type, ',');
        getline(stream, ID, ',');
        getline(stream, name, ',');
        getline(stream, year, ',');
        yearInteger = stoi(year);
        getline(stream, extraData, ',');
        getline(stream, certification, ',');

        cout << endl
             << "----- PRINTING DATA FOR VEHICLE #  " << numLines << " -----" << endl;
        cout << "Type: " << type << endl
             << "ID: " << ID << endl
             << "Name: " << name << endl
             << "Year: " << year << endl;

        if (type == "AutonomousCar")
        {
            // getting software version
            size_t colonPosition = extraData.find(":");
            if (colonPosition != string::npos)
            {
                string softwareVersion = extraData.substr(colonPosition + 1);
                softwareVersionFloat = stof(softwareVersion);
                cout << "Software Version : " << softwareVersionFloat << endl;
            }

            // getting certification
            size_t hyphenPosition = certification.find("-");
            if (hyphenPosition != string::npos)
            {
                string cert = certification.substr(hyphenPosition + 1);
                cout << "Certification: " << cert << endl;
            }
        }

        else if (type == "ElectricVehicle")
        {
            // getting software version
            size_t colonPosition = extraData.find(":");
            if (colonPosition != string::npos)
            {
                string batteryInformation = extraData.substr(colonPosition + 1);
                batteryCapacityInteger = stoi(batteryInformation);
                cout << "Battery Information : " << batteryCapacityInteger << endl;
            }

            // getting certification
            size_t hyphenPosition = certification.find("-");
            if (hyphenPosition != string::npos)
            {
                string cert = certification.substr(hyphenPosition + 1);
                cout << "Certification: " << cert << endl;
            }
        }

        else if (type == "HybridTruck")
        {
            // getting software version
            size_t colonPosition = extraData.find(":");
            size_t barPosition = extraData.find("|");
            size_t batteryColonPosition = extraData.find(":", barPosition);
            if (colonPosition != string::npos || barPosition != string::npos || batteryColonPosition != string::npos)
            {
                string cargoInfo = extraData.substr(colonPosition + 1, 5);
                cout << "Cargo Information : " << cargoInfo << endl;
                string batteryInfoHybrid = extraData.substr(batteryColonPosition + 1);
                cout << "Battery Information: " << batteryInfoHybrid << endl;
            }

            // getting certification
            size_t hyphenPosition = certification.find("-");
            if (hyphenPosition != string::npos)
            {
                string cert = certification.substr(hyphenPosition + 1);
                cout << "Certification: " << cert << endl
                     << endl;
            }
        }

        else
        {
            cout << "Error\n";
        }
    }

    ReadFile.close();
    cout << endl
         << "Resulting Year Integer Value: " << yearInteger << endl;
    cout << "File Closed Successfully" << endl;

    return 0;
}
