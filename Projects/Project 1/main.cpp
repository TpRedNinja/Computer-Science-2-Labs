/*
 * This file will call 3 other programs depending on what the user choose. Other 3 programs are:
 * "Rock, Paper, Scissors", Login screen, & generating a random password
*/
#include "Random_Password_Generator.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
// global variable
int choice; // the number the user puts in

int main()
{


    // give the user options
    cout << "Enter 1 for Random Password generator\nEnter 2 for Login\n"
            "Enter 3 to play Rock Paper Scissors\nEnter 4 to exit"<< endl;
    cout << "Please Enter a number base off which program you want to view: ";
    cin >> choice;

    if (choice == 1)
    {
        main_1();
    } else
    {
        cout << "Program ending";
    }
    // switch base off the user input
    /*switch (choice)
    {
        case 1: // random password generator
            main_1();
            break;
        case 2: // login screen
            break;
        case 3: // rock paper scissors vs computer
            break;
        case 4:
            break;
        default:
            break;
    }*/
    return 0;
}