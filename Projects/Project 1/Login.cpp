// This program was created on Sept 15th 2025 for CSMC2 by Harris
// This program will simulate a login screen
#include "Login.h" // so other programs can use the main function
#include "main.h" // so I can call main
#include <iostream> // need
#include <string> // need
#include <iomanip> // dont technically need but eh
#include <cstdlib> // need for random I don't know why it's greyed out
using namespace std;

//declare external variable
extern int choice;
extern bool ValidChoice;
bool ValidLogin;
int attempts = 3; // how many attempts the user has

// prototype functions
int CheckPasswordNumbers(string);
int CheckPasswordSpecial(string);
bool VerifyLogin(string, string);
void MenuPrompt();

int main_2()
{
    string username, password; // get username and password
    bool ValidPassword; // bool if the password can be considered valid

    cout << "This Program will simulate creating a account" << endl;
    cout << "Create a username: ";
    cin >> username;
    do
    {
        cout << "Make sure your password is 10 characters long and includes 2 numbers and 1 special character" << endl;
        cout << "Create a password: ";
        cin >> password;

        int numbers = CheckPasswordNumbers(password);
        int special = CheckPasswordSpecial(password);

        if (password.length() >= 10 && special >= 1 && numbers >= 2)
        {
            ValidPassword = true;
        } else
        {
            cout << "Invalid password." << endl;
            ValidPassword = false;
        }

    } while (!ValidPassword);

    do
    {
        cout << "You have " << attempts << " attempts to sign in before you are locked out." << endl;
        ValidLogin = VerifyLogin(username, password);
    } while (!ValidLogin && attempts > 0);
    if (attempts == 0)
    {
        cout << "you have ran out of attempts. Your account is now locked." << endl;
        MenuPrompt();
    }
    if (ValidLogin)
    {
        cout << "You have successfully logged in.\nWelcome: " << username << endl;
        MenuPrompt();
    }
    return 0;
}

int CheckPasswordNumbers(string password)
{
    int number = 0; // integer for how many numbers are in the password
    char numbers[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    for (int i = 0; i < password.length(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (password[i] == numbers[j])
            {
                number++;
                break;
            }
        }
    }

    return number;
}

int CheckPasswordSpecial(string password)
{
    int special = 0; // integer for how many special characters
    char specials[] = {'!', '@', '#', '$', '%', '&', '*'};

    for (int i = 0; i < password.length(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (password[i] == specials[j])
            {
                special++;
            }
        }
    }
    return special;
}

bool VerifyLogin(string CorrectUsername, string CorrectPassword)
{
    string username, password;
    cout << "Enter your Username: ";
    cin >> username;
    cout << "Enter your Password: ";
    cin >> password;

    if (username == CorrectUsername && password != CorrectPassword)
    {
        attempts--;
        cout << "Incorrect password" << endl;
        return false;
    } else if (username != CorrectUsername && password == CorrectPassword)
    {
        attempts--;
        cout << "Incorrect username" << endl;
        return false;
    } else if (username != CorrectUsername && password != CorrectPassword)
    {
        attempts--;
        cout << "Incorrect username & password" << endl;
        return false;
    } else
    {
        return true;
    }
}

void MenuPrompt()
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
                attempts = 3;
                ValidChoice = true;
                ValidLogin = false;
                main_2();
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