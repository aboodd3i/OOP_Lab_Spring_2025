#include "fstream"
#include "iostream"
#include "sstream"
using namespace std;

int main()
{
    ofstream MyOutputFile("config.txt", ios::out);
    MyOutputFile << "AAAAA" << "BBBBB" << "CCCCC";
    cout << "Orignal file content: " << "AAAAABBBBBCCCCC" << endl;
    MyOutputFile.close();

    fstream MyFile("config.txt", ios::in | ios::out);
    if (!MyFile)
    {
        cerr << "Error!" << endl;
        exit(1);
    }

    MyFile.seekp(5);
    MyFile << "XXXXX";
    cout << "New Data Updated!" << endl;
    MyFile.close();

    ifstream MyInputFile("config.txt", ios::in);
    string content;
    getline(MyInputFile, content);
    cout << "Updated data: " << content;
    MyInputFile.close();

    return 0;
}
