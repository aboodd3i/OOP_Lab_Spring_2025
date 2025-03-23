// Muhammad Abdullah | 24K 0977 | OOP Lab 07 | Question 03
#include <iostream>
using namespace std;

class Currency
{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; // Rate compared to base currency (USD)

public:
    Currency(double amt, string code, string symbol, double rate) : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase()
    {
        return amount * exchangeRate; // Convert to base currency (USD)
    }

    virtual double convertTo(Currency &targetCurrency)
    {
        double baseValue = convertToBase();             // Convert current currency to USD
        return baseValue / targetCurrency.exchangeRate; // Convert USD to target currency
    }

    virtual void displayCurrency()
    {
        cout << amount << " " << currencySymbol << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "USD", 1.0) {} // USD is the base currency (exchange rate = 1)

    void displayCurrency()
    {
        cout << amount << " USD" << endl;
    }
};

class Euro : public Currency
{
public:
    Euro(double amt) : Currency(amt, "EUR", "EUR", 1.1) {} // 1 EUR = 1.1 USD

    void displayCurrency()
    {
        cout << amount << " EUR" << endl;
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amt) : Currency(amt, "PKR", "PKR", 0.0036) {} // 1 PKR = 0.0036 USD

    void displayCurrency()
    {
        cout << amount << " PKR" << endl;
    }
};

int main()
{
    Dollar d(100);
    Euro e(50);
    Rupee r(10000);

    cout << "Initial Currencies:\n";
    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "\nConversions:\n";

    cout << "100 USD to EUR: " << d.convertTo(e) << " EUR\n";
    cout << "50 EUR to USD: " << e.convertTo(d) << " USD\n";
    cout << "10000 PKR to USD: " << r.convertTo(d) << " USD\n";
    cout << "100 USD to PKR: " << d.convertTo(r) << " PKR\n";

    return 0;
}
