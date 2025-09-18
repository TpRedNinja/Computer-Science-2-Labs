// This program was created on Sept 15th 2025 for CSMC2 by Harris
// This program will be a rock paper scissors game
#include "Rock_Paper_Scissors.h" // so other programs can use the main function
#include "main.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

// global constant
const int Rock = 1, Paper = 2, Scissors = 3;
extern int choice;
extern bool ValidChoice;
int round = 1; // to track which round we are on

//prototype functions
int ComputerRockPaperScissors();
void MenuPrompT();

int main_3()
{
    // define variables

    int UserScore = 0, ComputerScore = 0; // scores for user and computer
    int URPS; // int for the user which number they put in, URPS = User-Rock-Paper-Scissors
    int CRPS; // int for the computer which number they put in, CRPS = Computer-Rock-Paper-Scissors

    cout << "This program you will play Rock Paper Scissors against the computer" << endl;
    cout << "The player who wins 2/3 from 3 rounds wins!" << endl;
    cout << "Press enter when you are ready to begin: ";

    // Ignore leftover input from previous cin operations
    cin.ignore();

    string temp;
    getline(cin, temp);

    do
    {
        cout << "Round " << round << endl;
        cout << "Enter 1 for Rock\nEnter 2 for Paper\nEnter 3 for Scissors" << endl;
        cin >> URPS;

        // input validation
        while (URPS != Rock && URPS != Paper && URPS != Scissors)
        {
            cout << "Error: please input 1, 2, or 3" << endl;
        }

        // display user choice
        switch (URPS)
        {
            case 1:
                cout << "Player played Rock" << endl;
                break;
            case 2:
                cout << "Player played Paper" << endl;
                break;
            case 3:
                cout << "Player played Scissors" << endl;
                break;
        }

        // computer move
        srand(time(NULL));
        CRPS = ComputerRockPaperScissors();

        switch (CRPS)
        {
            case 1:
                cout << "Computer played Rock" << endl;
                break;
            case 2:
                cout << "Computer played Paper" << endl;
                break;
            case 3:
                cout << "Computer played Scissors" << endl;
                break;
        }

        //determine winnner
        if (URPS == CRPS)
        {
            UserScore++;
            ComputerScore ++;
            cout << "Round was a draw" << endl;
        } else if ((URPS - CRPS + 3) % 3 == 1)
        {
            UserScore++;
            round++;
            cout << "You won this round" << endl;
        } else
        {
            ComputerScore++;
            round++;
            cout << "Computer won this round" << endl;
        }

    } while (round <= 3 );

    if (UserScore > ComputerScore)
        cout << "You win" << endl;
    else if (ComputerScore > UserScore)
        cout << "You lose" << endl;
    else
        cout << "Game was a draw!" << endl;

    MenuPrompT();

    return 0;
}

int ComputerRockPaperScissors()
{
    int RPS, lower = 1, upper = 3;
    RPS = lower + rand() % (upper - lower + 1);

    return  RPS;
}

void MenuPrompT()
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
                round = 0;
                ValidChoice = true;
                main_3();
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
