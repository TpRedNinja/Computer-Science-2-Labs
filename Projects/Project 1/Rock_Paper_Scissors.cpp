// This program was created on Sept 15th 2025 for CSMC2 by Harris
// This program will be a rock paper scissors game
#include "Rock_Paper_Scissors.h" // so other programs can use the main function
#include "main.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

//declare external variable
extern int choice;
extern bool ValidChoice;


int main_3()
{
    const int Rock = 1, Paper = 2, Scissors = 3;
    cout << "This program you will play Rock Paper Scissors against the computer" << endl;
    cout << "The person who wins 2 rounds wins. Each round is best 2/3" << endl;
    cout << "Press enter when you are ready to begin: ";

    // Ignore leftover input from previous cin operations
    cin.ignore();

    string temp;
    getline(cin, temp);

    cout << "Enter 1 for Rock\nEnter 2 for Paper\nEnter 3 for Scissors: ";
    int RPS; // int for the user
    cin >> RPS;


    return 0;
}