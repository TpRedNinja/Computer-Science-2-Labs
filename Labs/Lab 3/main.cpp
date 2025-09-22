// This program was made by Harris Domangue for CMSC-202-65 Lab #3 on sept 17th 2025
// This program will convert feet to inches or inches to feet
#include <iostream>
#include <iomanip>
using namespace std;

void feet_to_inches(double *);
void inches_to_feet(double *);
double const inches_in_feets = 12.0; // store how many inches are stored in 1 foot

int main()
{
    int choice; // get user choice
    double Number; // the number the user wants to convert
    double temp_number; // store the number before its converted
    double *ptr1 = &Number; // points to the address of number
    bool run = true; // bool to tell program


    cout << "This program will convert feet to inches or inches to feet" << endl;
    while (run)
    {
        do
        {
            // get the number the user wants to convert
            cout << "Please enter the number you want to convert (enter 0 or any number less than 0 to exit): ";
            cin >> Number;

            // end program early if 0 or less
            if (Number <= 0)
            {
                cout << "program is ending goodbye";
                run = false;
                break;
            }

            // get user input on what to convert their number to or to exit
            cout << "Enter 1 to convert feet to inches\nEnter 2 for inches to feet\nEnter 3 to exit the program" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            //input validation
            if (choice < 0 || choice > 3)
            {
                cout << "Error: Invalid input!" << endl;
            } else
            {
                // call different functions base off user input
                switch (choice)
                {
                    case 1:
                        temp_number = Number; // store the non-converted number
                        feet_to_inches(ptr1); // convert the number to inches
                        cout << fixed << setprecision(2) << temp_number << " feet is " << fixed << setprecision(2) << *ptr1 << " in inches" << endl;
                        break;
                    case 2:
                        temp_number = Number; // store the non-converted number
                        inches_to_feet(ptr1); // convert the number to feet
                        cout << fixed << setprecision(2) << temp_number << " inches is " << fixed << setprecision(2) << *ptr1 << " in feet" << endl;
                        break;
                    case 3:
                        cout << "program ending goodbye";
                        run = false;
                        break;
                }
            }
        } while (choice < 0 || choice > 3);
    }
    return 0;
}


void feet_to_inches(double *feet)
{
    *feet = *feet * inches_in_feets;
}


void inches_to_feet(double *inch)
{
    *inch = *inch / inches_in_feets;
}
