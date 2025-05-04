#include "iostream"
#include "fstream"
#include "string"
using namespace std;

class InventoryItem
{
private:
    int itemID = 00;
    char itemName[20] = {0};
    string fileName;

public:
    InventoryItem(int id = 0, string name = " ")
    {
        itemID = id;
        int i;
        for (i = 0; i < name.length() && i < 20; i++)
        {
            itemName[i] = name[i];
        }
        itemName[i] = '\0';
    }

    void displayInformation()
    {
        cout << "ITEM ID: " << itemID << endl
             << "ITEM NAME: " << itemName << endl;
    }
};

int main()
{
    ofstream MyOutputFile("inventory.dat", ios::binary);
    if (!MyOutputFile)
    {
        cerr << "Error! File Not Opened." << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully for writing!" << endl
             << endl;
    }

    InventoryItem fisrtItem(0001, "Iphone 15");
    MyOutputFile.write((char *)&fisrtItem, sizeof(fisrtItem));
    MyOutputFile.close();

    ifstream MyInputFile("inventory.dat", ios::binary);
    if (!MyInputFile)
    {
        cerr << "Error! File Not Opened." << endl;
        exit(1);
    }
    else
    {
        cout << "File opened successfully for reading!" << endl
             << endl;
    }

    InventoryItem secondItem;
    MyInputFile.read((char *)&secondItem, sizeof(secondItem));
    MyInputFile.close();

    cout << "Here is the info of the first item: " << endl;
    fisrtItem.displayInformation();
    cout << endl
         << "And here is the info of the seconf item: " << endl;
    secondItem.displayInformation();

    return 0;
}
