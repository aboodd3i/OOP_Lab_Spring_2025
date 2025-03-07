// OOP Lab 06 Question 04 - BCS2H 24K0977
#include <iostream>
using namespace std;

class Account
{
protected:
    string accountNumber;
    float balance;

public:
    Account(string accountNumber, int balance) : accountNumber(accountNumber), balance(balance) {} // parameterised

    void displayDetails()
    {
        cout << endl
             << "Account Number: " << accountNumber << endl
             << "Available Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    SavingsAccount(string accountNumber, int balance, float interestRate) : Account(accountNumber, balance), interestRate(interestRate) {} // parameterised

    void displayDetails()
    {
        Account::displayDetails();
        cout << "Account Type: Savings Account" << endl
             << "Interest Rate: " << interestRate << "%" << endl
             << "Balance After Interest: $" << (balance * (1 + interestRate)) << endl;
    }
};

class CheckingAccount : public Account
{
private:
    float overDraftLimit;

public:
    CheckingAccount(string accountNumber, int balance, float overDraftLimit) : Account(accountNumber, balance), overDraftLimit(overDraftLimit) {} // parameterised

    void displayDetails()
    {
        Account::displayDetails();
        cout << "Account Type: Checking Account" << endl
             << "Over Draft Limit: " << overDraftLimit << endl;
    }
};

int main()
{
    CheckingAccount c1("1234 5678 9011 1213", 12000, 1000);
    SavingsAccount s1("0000 1111 2222 3333 4444", 50000, 2.3);
    SavingsAccount s2("5555 6666 7777 8888", 100000, 1.5);

    c1.displayDetails();
    s1.displayDetails();
    s2.displayDetails();
}
