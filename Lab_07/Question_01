// Muhammad Abdullah | 24K 0977 | OOP Lab 07 | Question 01
#include <iostream>
using namespace std;

class Account
{
protected:
    float balance;
    string accountHolderName, accountType, accountNumber;

public:
    Account(string accNum, string accName, string accType, float balance) : accountNumber(accNum), accountHolderName(accName), accountType(accType), balance(balance)
    {
        cout << "\n\nNew Account Created!\nDetails:\n\tAccount Title: " << accountHolderName << endl
             << "\tAccount Type: " << accountType << endl
             << "\tAccount Number: " << accountNumber << endl
             << "\tBalance Available: $" << balance << endl
             << endl;
    }

    virtual void deposit(int amount)
    {
        balance += amount;
        cout << "$" << amount << " deposited to account number: " << accountNumber << "." << endl
             << "Available Balance: $" << balance << ".\n";
    }

    virtual void withdraw(int amount)
    {
        if (balance > amount)
        {
            balance -= amount;
            cout << "$" << amount << " withdrawn from account number: " << accountNumber << "." << endl
                 << "Available Balance: $" << balance << ".\n";
        }
        else
        {
            cout << "Insufficient Balance!\nYour current balance is $" << balance << endl;
        }
    }

    virtual void calculateInterest()
    {
        // Interest calculation
    }

    virtual void printStatement()
    {
        cout << "Account Ttile: " << accountHolderName << endl
             << "Account Type: " << accountType << endl
             << "Account Number: " << accountNumber << endl
             << "Available Balance: $" << balance << endl;
    }

    void getAccountInfo()
    {
        printStatement();
    }

    ~Account()
    {
        cout << "\nDestructor for ACCOUNT called.\n";
    }
};

class SavingsAccount : public Account
{
private:
    float interestRate, minimumBalance, interestAmount;

public:
    SavingsAccount(string accNum, string accName, string accType, float balance, float interest, float minBal) : Account(accNum, accName, accType, balance), interestRate(interest), minimumBalance(minBal)
    {
        cout << "Savings Account Created Successfully!" << endl;
    }

    void calculateInterest() override
    {
        cout << "The interest rate for a savings account is: " << interestRate << "% (per annum)." << endl;
        interestAmount = balance * interestRate / 100;
        cout << "The amount you receive in interest is $" << interestAmount << endl;
        cout << "Previous Balance (before interest): $" << balance << endl;
        balance += interestAmount;
        cout << "New Balance (after interest): $" << balance << endl;
    }

    void withdraw(int amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            balance -= amount;
            cout << "$" << amount << " withdrawn from account number: " << accountNumber << "." << endl
                 << "Available Balance: $" << balance << ".\n";
        }
        else
        {
            cout << "Insufficient Balance!\nYour current balance is $" << balance << endl;
        }
    }

    void deposit(int amount) override
    {
        balance += amount;
        cout << "$" << amount << " deposited to account number: " << accountNumber << "." << endl
             << "Available Balance: $" << balance << ".\n";
    }

    void printStatement() override
    {
        cout << endl;
        Account::printStatement();
        cout << "Interest Rate Applied: " << interestRate << endl
             << "Minimum Required Balance: " << minimumBalance << endl
             << endl;
    }

    ~SavingsAccount()
    {
        cout << "\nDestructor for SAVINGS ACCOUNT called.\n";
    }
};

class CheckingAccount : public Account
{
};

class FixedDepositAccount : public Account
{
private:
    string maturityDate;
    float fixedInterestRate, interestAmount;

public:
    FixedDepositAccount(string accNum, string accName, string accType, float balance, string date, float interest) : Account(accNum, accName, accType, balance), maturityDate(date), fixedInterestRate(interest)
    {
        cout << "Fixed Deposit Account Created Successfully!" << endl;
    }

    void calculateInterest() override
    {
        cout << "The interest rate for a savings account is: " << fixedInterestRate << "% (per annum)." << endl;
        interestAmount = balance * fixedInterestRate / 100;
        cout << "The amount you receive in interest is $" << interestAmount << endl;
        cout << "Previous Balance (before interest): $" << balance << endl;
        balance += interestAmount;
        cout << "New Balance (after interest): $" << balance << endl;
    }

    void withdraw(int amount) override
    {
        if (balance > amount)
        {
            balance -= amount;
            cout << "$" << amount << " withdrawn from account number: " << accountNumber << "." << endl
                 << "Available Balance: $" << balance << ".\n";
        }
        else
        {
            cout << "Insufficient Balance!\nYour current balance is $" << balance << endl;
        }
    }

    void deposit(int amount) override
    {
        balance += amount;
        cout << "$" << amount << " deposited to account number: " << accountNumber << "." << endl
             << "Available Balance: $" << balance << ".\n";
    }

    void printStatement() override
    {
        cout << endl;
        Account::printStatement();
        cout << "Fixed Interest Rate Applied: " << fixedInterestRate << endl
             << "Maturity Date: " << maturityDate << endl
             << endl;
    }

    ~FixedDepositAccount()
    {
        cout << "\nDestructor for FIXED DEPOSIT ACCOUNT called.\n";
    }
};

int main()
{
    SavingsAccount account1("0000 1111 2222 3333", "Muhammad Abdullah Choudhry", "Savings Account", 12000.00, 2.5, 1000);
    FixedDepositAccount account2("1234 5678 8765 4321", "Muhammad Saad Sohail", "Fixed Deposit Account", 5000, "15 March, 2028", 1.5);

    cout << "\n\n--- RUNNNING TEST FOR THE SAVINGS ACCOUNT ---\n\n";
    account1.calculateInterest();
    account1.deposit(1000);
    account1.printStatement();
    account1.withdraw(5000);
    account1.printStatement();

    cout << "\n\n--- RUNNNING TEST FOR THE FIXED DEPOSIT ACCOUNT---\n\n";
    account2.calculateInterest();
    account2.deposit(4000);
    account2.printStatement();
    account2.withdraw(6000);
    account2.printStatement();

    return 0;
}
