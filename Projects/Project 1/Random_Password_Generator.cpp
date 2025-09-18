// This program was created on Sept 15th 2025 for CSMC2 by Harris
// This program will generate a 12 letter password and continue to do so until the user is satisfied
#include "Random_Password_Generator.h" // so other programs can use the main function
#include "main.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

//declare external variable
extern int choice;
extern bool ValidChoice;

string GenPass();

int main_1()
{
    cout << "This Program will generate a random 12-character password." << endl;
    cout << "Press enter to begin: ";

    // Ignore leftover input from previous cin operations
    cin.ignore();

    string temp;
    getline(cin, temp);

    srand(time(0));
    string password;
    string answer;
    do
    {
        string password = GenPass();
        cout << "Generated password: " << password << endl;
        do
        {
            cout << "Is this password good? (yes/no): ";
            cin >> answer;

            //lower case user input so it's easier to verify
            for (int i = 0; i < answer.length(); i++)
            {
                answer[i] = tolower(answer[i]); // NOLINT
            }

            // if user does not put in yes or no display this
            if (answer != "yes" && answer != "no")
            {
                cout << "Error: please input 'yes' or 'no'." << endl;
            }
        } while (answer != "yes" && answer != "no");

    } while(answer == "no");
    if (answer == "yes")
    {
        do
        {
            cout << "Press 0 to return to menu list\nEnter 1 to restart\nEnter 4 to exit"<< endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 0:
                    main();
                    ValidChoice = true;
                    break;
                case 1:
                    main_1();
                    ValidChoice = true;
                    break;
                case 4:
                    cout << "Ending Program goodbye";
                    ValidChoice = true;
                    break;
                default:
                    cout << "Invalid Choice. Please choose a number from the options" << endl;
                    ValidChoice = false;
                    break;
            }
        } while (!ValidChoice);
    }
    return 0;
}

char RandomLetter()
{
    return 'A' + (rand() % 26);
}

// generates a 12 character password
string GenPass()
{
    string password;
    // add 12 letters to the password
    for (int i = 0; i < 12; i++)
    {
        password += RandomLetter();
        if (i == 3 || i == 7)
            password += "-";
    }
    return password;
}