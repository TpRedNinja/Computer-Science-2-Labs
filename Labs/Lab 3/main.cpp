// this program was made by Harris Domangue for CMSC-202-65 Lab #3 on sept 17th 2025
// this program will convert feet to inches or inches to feet
#include <iostream>
#include <string>
using namespace std;

void feet_to_inches(int);
void feet_to_inches(float);
void inches_to_feet(int);
void inches_to_feet(float);

int main()
{
    int choice;
    int choice2;
    bool Float;
    int Ifeet;
    int* ptr1 = &Ifeet;
    float DFeet;
    float* ptr2 = &DFeet;
    int Int_Inches;
    float FInches;
    cout << "This program will convert feet to inches or inches to feet" << endl;
    cout << "Enter 1 to convert feet to inches or 2 for inches to feet" << endl;
    cin >> choice;

    /*switch (choice)
    {
        case 1:
            cout << "Will you number contain a decimal?\nEnter 1 for yes and 2 for no" << endl;
            cin >> choice2;
            switch (choice2)
            {
                case 1:
                    Float = true;
                    break;
                case 2:
                    Float = false;
                    break;
            }
            cout << "Please enter the number of feet you want to convert to inches: ";
            if (Float)
            {
                cin >> DFeet;
                feet_to_inches(DFeet);
            } else
            {
                cin >> Ifeet;
                feet_to_inches(Ifeet);
            }

            break;
        case 2:
            cout << "Will you number contain a decimal?\nEnter 1 for yes and 2 for no" << endl;
            cin >> choice2;
            switch (choice2)
            {
                case 1:
                    Float = true;
                    break;
                case 2:
                    Float = false;
                    break;
            }
            cout << "Please enter the number of inches you want to convert to feet: ";
            if (Float)
            {
                cin >> DFeet;
                feet_to_inches(DFeet);
            } else
            {
                cin >> Ifeet;
                feet_to_inches(Ifeet);
            }
            break;
    }*/

    return 0;
}
