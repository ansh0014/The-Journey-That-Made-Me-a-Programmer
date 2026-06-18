#include <iostream>
using namespace std;
class BankException : public exception
{
    string msg;

public:
    BankException(string msg)
    {
        this->msg = msg;
    }
    const char *what() const noexcept override
    {
        return msg.c_str();
    }
};
class Customer
{
    string name;
    int balance, account_number;

public:
    Customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }
    // deposit
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully" << endl;
        }
    }
    void withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully" << endl;
        }
        else if (amount > balance)
        {
            throw BankException("Insufficient balance");
        }
        else
        {
            throw BankException("Invalid amount");
        }
    }
};
int main()
{
    Customer c1("Anshul", 1000, 101);
    try
    {

        c1.withdraw(2000);
    }
    catch (const BankException &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
