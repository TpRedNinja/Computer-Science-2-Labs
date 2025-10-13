/* This is a bank account struct using pointers*/
#include <iostream>
using namespace std;

struct BankAccount
{
    char *name;
    int number;
    double balance;
};

// function prototypes
void display(BankAccount account);
void deposit(BankAccount &account, double amount);
void withdraw(BankAccount &account, double amount);
double balance(BankAccount account);

int main()
{
    // Created our bank account
    BankAccount myAccount;
    myAccount.name = "Harris";
    myAccount.number = 1;
    myAccount.balance = 1289.55;

    cout << "Account Before: " << endl;
    display(myAccount);

    deposit(myAccount, 100.0);
    withdraw(myAccount, 10.0);
    cout << "----------------" << endl;
    cout << "Account After: " << endl;
    cout << "New Balance: " << balance(myAccount) << endl;

    return 0;
}

void display(BankAccount account)
{
    cout << "Account Info: " << endl;
    cout << "Account Owner: " << account.name << "\n";
    cout << "Account Number: " << account.number << "\n";
    cout << "Account Balance: " << account.balance << "\n";
}

void deposit(BankAccount &account, double amount)
{
    if (amount >= 0.0)
        account.balance += amount;
    else
        cout << "Deposit can not be less than zero";
}

void withdraw(BankAccount &account, double amount)
{
    // notice how we can NOT use dot since it is a pointer
    if (amount >= 0.0 && amount <= account.balance)
        account.balance -= amount;
    else
        cout << "Withdraw must be a positive number.";
}

double balance(BankAccount account)
{
    // notice how we can use dot since it's not a pointer
    return account.balance;
}