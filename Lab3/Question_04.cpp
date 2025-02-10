#include<iostream>
#include<string>
using namespace std;

class Laptop {
private:
string brand, processor, model;
int ram, storage;

public:
Laptop()  {
cout << "\nEnter your laptop's Brand: ";
cin >> brand;
cout << "\nEnter your laptop's Model: ";
cin >> model;
cout << "\nEnter your laptop's Processor: ";
cin >> processor;
cout << "\nEnter your laptop's RAM: ";
cin >> ram;
cout << "\nEnter your laptop's Storage: ";
cin >> storage;
}

void turnOn(int status) {
if (status == 1) {
cout << "\nLaptop is already on.";
}
else {
cout << "Turning on" ;
status == 1;
cout << "\nLaptop turned on successfully";
}
}

void turnoff(int status) {
if (status == 0) {
cout << "\nLaptop is already off.";
}
else {
cout << "\nTurning off" ;
status == 1;
}
}

void runProgram(string selection, int status){
if (status == 0) {
cout << "\nUnable to run program. Please turn on your laptop.";
return;
}
cout << "\nRunning " << selection;
}

void displaySpecifications() {
cout << "\nBrand: " << brand;
cout << "\nModel: " << model;
cout << "\nProcessor: " << processor;
cout << "\nAvailable RAM: " << ram;
cout << "\nAvailable Storage: " << storage;
}

};

int main()
{
cout << "\n\n---LAPTOP SPECIFICATION CHEKCKER---\n\n";

cout << "\nLet's enter details for Bilal's Laptop\n";
Laptop laptopBilal;
cout << "\nLet's enter details for Ayesha's Laptop\n";
Laptop laptopAyesha;



while (true) {
    cout << "\nMain Menu\n\n";
    cout << "\t1. Turn on Bilal's Laptop\n\t2. Turn on Ayesha's Laptop\n\t3. Turn off Bilal's Laptop\n\t4. Turn off Ayesha's Laptop\n\t5. Run a Program on Bilal's Laptop\n\t6. Run a Program on Ayesha's Laptop\n\t7. Display Specifications for Bilal's Laptop\n\t8. Display Specifications for Ayesha's Laptop\n\t9. Exit";
    cout << "\nPlease enter your choice: ";
    int choice, statusBilal, statusAyesha; 
    string name; 
    cin >> choice;
    switch (choice)
    {
    case 1:
    statusBilal = 1;
    laptopBilal.turnOn(statusBilal);
    break;

    case 2:
    statusAyesha = 1;
    laptopAyesha.turnOn(statusAyesha);
    break;

    case 3:
    statusBilal = 0;
    laptopBilal.turnoff(statusBilal);
    break;

    case 4:
    statusAyesha = 0;
    laptopAyesha.turnoff(statusAyesha);
    break;

    case 5:
    cout << "\nPlease type the name of the program you want to run: ";
    cin >> name;
    laptopBilal.runProgram(name, statusBilal);
    break;

    case 6:
    cout << "\nPlease type the name of the program you want to run: ";
    cin >> name;
    laptopAyesha.runProgram(name, statusAyesha);
    break;

    case 7:
    cout << "\nFollowing are the specifications for Bilal's Laptop: ";
    laptopBilal.displaySpecifications();
    break;

    case 8:
    cout << "\nFollowing are the specifications for Ayesha's Laptop: ";
    laptopAyesha.displaySpecifications();
    break;

    case 9:
    cout << "Thank You.";
    return;
    break;
            
    default:
    cout << "\nPlease enter the right choice.";
    }
}
    return 0;
}
