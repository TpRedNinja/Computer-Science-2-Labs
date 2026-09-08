#include <iostream>
using namespace std;
class BankAccount
{
    public:
        BankAccount(); // default constructor
        BankAccount(string name, int number, double balance); // main constructor
        BankAccount(string name); // name only constructor
        void SetAccount(string name, int number, double balance);
        void deposit(double amount); // deposit
        void withdraw(double amount); // withdraw
        string accountInfo(); // return the state of the object
        double balance(); // return the balance
    private:
        string m_name;
        int m_number;
        double m_balance;
};
int main()
{
    // create an account
    BankAccount account1("Harris", 202, 1000);

    // add amount and show info
    account1.deposit(1500.00); // deposit money
    cout << account1.accountInfo(); // display info

    // withdraw and show balance
    account1.withdraw(450.00);
    cout << "Account Balance: " << account1.balance();

    // withdraw and show balance  (can't do this because its private)
    // account1.m_balance -= 100.0;

    return 0;
}

BankAccount::BankAccount()
{
    // default constructor - does nothing
}
BankAccount::BankAccount(string name)
{
    m_name = name;
    m_number = 0;
    m_balance = 0;
}
BankAccount::BankAccount(string name, int number, double balance)
{
    m_name = name;
    m_number = number;
    if (balance < 0)
        m_balance = balance;
    else
        m_balance = balance;
}
void BankAccount::SetAccount(string name, int number, double balance)
{
    m_name = name;
    m_number = number;
    if (balance < 0)
        m_balance = balance;
    else
        m_balance = balance;
}
void BankAccount::deposit(double amount)
{
    if (amount > 0)
        m_balance += amount;
    else
        cout << "You can't deposit less than 0!" << endl;
}
void BankAccount::withdraw(double amount)
{
    if (amount > m_balance)
        cout << "You can't withdraw than " << m_balance << endl;
    else
        m_balance -= amount;
}
double BankAccount::balance()
{
    return m_balance;
}
string BankAccount::accountInfo()
{
    string info;
    info += "Account #: " + to_string(m_number) + "\n";
    info += "Name: " + m_name + "\n";
    info += "Balance: " + to_string(m_balance) + "\n";
    return info;
}


