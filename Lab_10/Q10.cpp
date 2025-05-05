#include "fstream"
#include "iostream"
#include "sstream"
using namespace std;

int main()
{
    ofstream MyOutputFile("data_records.txt", ios::out);
    MyOutputFile << "RECORD 1\n"
                 << "RECORD 2\n"
                 << "RECORD 3\n"
                 << "RECORD 4\n";
    MyOutputFile.close();

    ifstream MyInputFile("data_records.txt", ios::in);
    if (!MyInputFile)
    {
        cerr << "Error!" << endl;
        exit(1);
    }

    MyInputFile.seekg(20, ios::beg);
    cout << "Current Position: " << MyInputFile.tellg() << endl;

    string content;
    getline(MyInputFile, content);
    cout << content;

    MyInputFile.close();
    return 0;
}
