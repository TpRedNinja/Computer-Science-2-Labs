/*
 * This file will call 3 other programs depending on what the user choose. Other 3 programs are:
 * "Rock, Paper, Scissors", Login screen, & generating a random password
*/
#include "Random_Password_Generator.h"
#include "Login.h"
#include "Rock_Paper_Scissors.h"
#include "main.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
// global variable
int choice; // the number the user puts in
bool ValidChoice; // bool if we have a valid choice or not

int main()
{
    do
    {
        // give the user options
        cout << "Enter 1 for Random Password generator\nEnter 2 for Login\n"
                "Enter 3 to play Rock Paper Scissors\nEnter 4 to exit"<< endl;
        cout << "Please Enter a number base off which program you want to view: ";
        cin >> choice;

        // switch base off the user input
        switch (choice)
        {
            case 1: // random password generator
                main_1();
                break;
            case 2: // login screen
                main_2();
                break;
            case 3: // rock paper scissors vs computer
                main_3();
                break;
            case 4: // end program
                cout << "Program Ending";
                ValidChoice = true;
                break;
            default: // reprompt the user
                cout << "Invalid Choice. Please choose a number from the options" << endl;
                ValidChoice = false;
                break;
        }
    } while (!ValidChoice);

    return 0;
}