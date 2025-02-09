#include <iostream>
#include <string>
using namespace std;

class MarkerPens
{
private:
    string brand, color;
    int inkLevel;
    bool refill;

public:
    MarkerPens(string b, string c, int i, bool r)
    {
        brand = b;
        color = c;
        inkLevel = i;
        refill = r;
    }

    void write(int inkToUse)
    {
        if (inkLevel == 0)
        {
            cout << "Ink Levels are zero. Please call the refill function.";
        }
        else if (inkLevel < inkToUse)
        {
            cout << "You do not have enough ink to write." << endl
                 << "Would you like to call the refill function? (Y/N)" << endl;
            char choice;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                refill = true;
                refillInk(refill);
                cout << "Please call the write function again to write.";
            }
        }
        else
        {
            inkLevel -= inkToUse;
            cout << "writing with " << color << " marker. Current ink levels are: " << inkLevel << "%";
        }
    }

    void refillInk(bool refill)
    {
        if (refill)
        {
            inkLevel = 100;
            cout << color << " marker has been refilled to 100%";
        }
        else
        {
            cout << "This marker is not refillable! Please make the status of 'Refill' is true.";
        }
    }

    void checkStatus()
    {
        cout << "Following are te details for the chosen marker: " << endl;
        cout << "Brand: " << brand << endl;
        cout << "Color: " << color << endl;
        cout << "Ink Level: " << inkLevel << endl;
    }
};

int main()
{
    string markerBrand, markerColor;
    int markerInkLevel;
    bool markerRefill;

    cout << "--- MARKER PENS INVENTORY RECORDER! ---";

    cout << "\n\nLet's add a new marker to your inventory!\n";

    cout << "Please enter the brand of the marker: ";
    cin >> markerBrand;
    cout << "Please enter the color of the marker: ";
    cin >> markerColor;
    cout << "The new marker has an ink level of 100%";
    markerInkLevel = 100;
    markerRefill = (markerInkLevel == 0);

    MarkerPens marker1(markerBrand, markerColor, markerInkLevel, markerRefill);

    int choice, percentage;

    while (true)
    {
        cout << "\nMain Menu:\n";
        cout << "1. Write\n";
        cout << "2. Refill Marker\n";
        cout << "3. Check Status\n";
        cout << "4. Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Please enter the percentage of ink you will be using: ";
            cin >> percentage;
            marker1.write(percentage);
            break;

        case 2:
            markerRefill = true;
            marker1.refillInk(markerRefill);
            break;

        case 3:
            marker1.checkStatus();
            break;

        case 4:
            cout << "Exiting the program. Thank You!";
            return 0;

        default:
            cout << "Invalid Choice. Try Again.";
        }
    }
}
