// Muhammad Abdullah 24K0977 - OOP Lab 05 Question 05

#include <iostream>
using namespace std;

class Guide
{
private:
    string fullName;
    int yearsOfExperience;
    string areaOfExpertise;

public:
    Guide()
    {
        fullName = "Unknown";
        yearsOfExperience = 0;
        areaOfExpertise = "None";
    }

    Guide(string name, int experience, string expertise)
    {
        fullName = name;
        yearsOfExperience = experience;
        areaOfExpertise = expertise;
    }

    string getFullName() const { return fullName; }
    string getExpertise() const { return areaOfExpertise; }
    int getExperience() const { return yearsOfExperience; }
};

class TourCompany
{
private:
    string agencyName;
    Guide *guideList;
    int totalGuides;
    int capacity = 100;

public:
    TourCompany()
    {
        agencyName = "Unnamed Agency";
        totalGuides = 0;
        guideList = new Guide[capacity];
    }

    TourCompany(string name)
    {
        agencyName = name;
        totalGuides = 0;
        guideList = new Guide[capacity];
    }

    void addGuide(Guide &newGuide)
    {
        if (totalGuides < capacity)
        {
            guideList[totalGuides] = newGuide;
            totalGuides++;
        }
        else
        {
            cout << "Limit reached! Cannot add more guides." << endl;
        }
    }

    void showDetails() const
    {
        cout << "Tour Company: " << agencyName << endl;
        cout << "Total Guides Available: " << totalGuides << endl;
        for (int i = 0; i < totalGuides; i++)
        {
            cout << "\nGuide #" << i + 1 << " Profile:\n";
            cout << "Name: " << guideList[i].getFullName() << endl;
            cout << "Experience Level: " << guideList[i].getExperience() << " years" << endl;
            cout << "Expertise Area: " << guideList[i].getExpertise() << endl;
        }
    }

    ~TourCompany()
    {
        delete[] guideList;
    }
};

int main()
{
    TourCompany company("Global Adventures");

    Guide guideA("Daniel Lee", 6, "Mountain Expeditions");
    Guide guideB("Emily Carter", 10, "Wildlife Safaris");
    Guide guideC("Jack Reynolds", 4, "Cultural Heritage");

    company.addGuide(guideA);
    company.addGuide(guideB);
    company.addGuide(guideC);
    company.showDetails();

    return 0;
}
