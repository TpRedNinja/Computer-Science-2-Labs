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

//prototype functions
int ComputerRockPaperScissors();

int main_3()
{
    // define variables
    extern int choice;
    extern bool ValidChoice;
    int round = 1; // to track which round we are on
    int UserScore = 0, ComputerScore = 0; // scores for user and computer
    int URPS; // int for the user which number they put in, URPS = User-Rock-Paper-Scissors
    int CRPS; // int for the computer which number they put in, CRPS = Computer-Rock-Paper-Scissors

    cout << "This program you will play Rock Paper Scissors against the computer" << endl;
    cout << "The person who wins 2 rounds wins. Each round is best 2/3" << endl;
    cout << "Press enter when you are ready to begin: ";

    // Ignore leftover input from previous cin operations
    cin.ignore();

    string temp;
    getline(cin, temp);

    do
    {
        cout << "Enter 1 for Rock\nEnter 2 for Paper\nEnter 3 for Scissors: ";
        cin >> URPS;
        if (URPS != Rock && URPS != Paper && URPS != Scissors)
        {
            cout << "Error: please input 1, 2, or 3" << endl;
        }
    } while (URPS != Rock && URPS != Paper && URPS != Scissors);

    srand(time(NULL));
    CRPS = ComputerRockPaperScissors();



    return 0;
}

int ComputerRockPaperScissors()
{
    int RPS, lower = 1, upper = 3;
    RPS = rand() % (upper - lower + 1);

    return  RPS;
}
