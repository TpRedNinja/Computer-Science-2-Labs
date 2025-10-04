#include <iomanip>
#include <iostream>

using namespace std;

// constant hourly
const double HOURLY_PAY= 18.75;

void paycheck(int, double);

int main()
{
    // create hour variables
    int day = 1;
    int hours;
    double total_pay = 0;

    //display to user
    cout << "This program will tell you how much you earned." << endl;

    do
    {
        cout << "Enter -1 to exit" << endl;
        cout << "Enter the hours worked on day #" << day << ": " << endl;
        cin >> hours;
        if (hours >= 0)
        {
            paycheck(hours, total_pay);
            day++;
        }
    } while (hours >= 0);

    cout << setprecision(2) << fixed << endl;
    cout << "Your total pay is " << total_pay << endl;


    return 0;
}

void paycheck(int hours, double total_pay)
{
    double full_pay = HOURLY_PAY * hours;
    static int day = 1;

    cout << setprecision(2) << fixed << endl;
    cout << "Your total pay for day#" << day << " is: " << full_pay << endl;
    total_pay += full_pay;
    day ++; // add to day count static
}