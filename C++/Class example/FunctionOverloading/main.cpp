#include <iostream>
#include <string>
using namespace std;

const int MILES = 5280;

//prototypes for miles to feet
int miles_to_feet(int);
double miles_to_feet(double);

int main()
{
    int num_of_miles;
    string number;

    cout << "Enter the number of miles you traveled: ";
    cin >> number;

    if (number.find('.') > 50)
    {
        num_of_miles = stoi(number);
    } else
    {
        double num_of_miles = stoi(number);
    }

    cout << "You traveled " << miles_to_feet(num_of_miles) << " feet." << endl;

    return 0;
}

int miles_to_feet(int miles)
{
    return MILES * miles;
}

double miles_to_feet(double miles)
{
    return MILES * miles;
}

