#include "fstream"
#include "iostream"
#include "sstream"
using namespace std;

int main()
{
    ofstream MyOutputFile("large_log.txt", ios::out);
    MyOutputFile << "This is the first line." << endl
                 << "This is the second test line." << endl
                 << "Sir Talha is awesome.";
    MyOutputFile.close();

    ifstream MyInputFile("large_log.txt", ios::in);
    if (!MyInputFile)
    {
        cerr << "Error!" << endl;
        exit(1);
    }

    char ch[11];
    char ch1[11];
    MyInputFile.read(ch, 10);
    cout << "First 10 characters: " << ch << endl;
    cout << "Current Position: " << MyInputFile.tellg() << endl
         << endl;
    MyInputFile.read(ch1, 10);
    cout << "Next 10 Characters: " << ch1 << endl;
    cout << "New Position: " << MyInputFile.tellg() << endl;
    MyInputFile.close();

    return 0;
}
