#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    
    const double RATE = 6.9; // constant variable
    double deposit; // input variable
    
    // get the deposit value from the user
    // this is a prompt display
    cout << "Enter the amount you'd like to deposit: ";
    cin >> deposit;
    
    double newbalance;
    newbalance = deposit + deposit * (RATE/100);
    cout << setprecision(2) << fixed;
    cout << "Your new balance is $" << newbalance << endl; 
    
    return 0;
}