#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
using namespace std;

int main()
{
    ofstream MyOutputFile("sensor_log.txt");
    if (!MyOutputFile)
    {
        cerr << "Error!";
        exit(1);
    }

    MyOutputFile << "This is a text.\n";
    size_t pos = MyOutputFile.tellp();
    cout << "Pointer Position: " << pos << endl;

    MyOutputFile << "This is another text.\n";
    pos = MyOutputFile.tellp();
    cout << "Pointer Position: " << pos << endl;

    MyOutputFile << "This is the third line.\n";
    pos = MyOutputFile.tellp();
    cout << "Pointer Position: " << pos << endl;

    MyOutputFile << "Can you do a backflip?\n";
    pos = MyOutputFile.tellp();
    cout << "Pointer Position: " << pos << endl;

    MyOutputFile << "Sir Talha the Goat\n";
    pos = MyOutputFile.tellp();
    cout << "Pointer Position: " << pos << endl;

    MyOutputFile.close();

    stringstream buffer;

    ifstream MyInputFile("sensor_log.txt");
    buffer << MyInputFile.rdbuf();
    string content = buffer.str();
    cout << content;

    return 0;
}
