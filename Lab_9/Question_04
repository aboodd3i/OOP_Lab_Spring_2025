#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCard(string num) {
        cardNumber = num;
    }

    bool processPayment(double amount) override {
        if (amount > 0) {
            cout << "Credit Card " << cardNumber << " charged Rs. " << amount << endl;
            return true;
        }
        cout << "Invalid Credit Card Payment" << endl;
        return false;
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;

public:
    DigitalWallet(double bal) {
        balance = bal;
    }

    bool processPayment(double amount) override {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Digital Wallet payment of Rs. " << amount << " successful. Remaining balance: Rs. " << balance << endl;
            return true;
        }
        cout << "Insufficient Wallet Balance" << endl;
        return false;
    }
};

int main() {
    CreditCard myCard("1234-5678-9876-5432");
    DigitalWallet myWallet(500.0);

    myCard.processPayment(200.0);
    myWallet.processPayment(300.0);
    myWallet.processPayment(250.0);

    return 0;
}
