// This program was made by Harris Domangue on september 25th 2025 for CMSC-202
// This program will mimic the game mastermind
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

// prototype functions
void GenerateCode(int code[], int size); // function to generate the code
string CheckGuess(int code[], int guess[], int size); // function to check if it's correct or not as well as giving back a hint

int main()
{
    // variables
    bool run = true; // a bool to tell whether the program is running or not
    int size = 4; // the global constant size for arrays
    int round = 1; // counter for which round the game is one
    string colors[6] = {"White", "Pink", "Orange", "Yellow", "Green", "Purple"};
    int code[size]; // array to hold the code
    int guess[size]; // array to hold the guess of the user
    string Hint; // string for giving a hint to the user
    int start; // an int for user input to start
    int choice; // an int for user input to make a decision 1
    int choice2; // an int for user input to make a decision 2
    bool debug = false; // bool for to debug or not. Enter 3 for it to be true and to see the answer to the game
    string CorrectCode; // converts the master code to colors
    string GuessCode; // converts the users guess to colors

    // random thing
    srand(time(0)); // so the numbers are always random no matter what

    // keep the program running forever
    while (run)
    {
        cout << "This program is a game called mastermind" << endl;
        do
        {
            cout << "Enter 1 to start or 2 to stop: ";
            cin >> start;
            // input validation
            if (start != 1 && start != 2 && start != 3)
            {
                cout << "Error: Please enter 1 to start or 2 to stop" << endl;
            }
        } while (start != 1 && start != 2 && start != 3);

        if (start == 2)
        {
            run = false;

        }
        else
        {
            if (start == 3)
            {
               debug = true;
            }
            // generates the code
            GenerateCode(code, size);
            // continue until round is greater than 10
            while (round <= 10 && run && Hint != "You Win")
            {
                int i = 0;
                cout << "Round " << round << endl;
                cout << "Enter\n0 for White\n1 for Pink\n2 for Orange\n3 for Yellow\n4 for Green\n5 for Purple"<< endl;
                if (debug)
                {
                    string CorrectCode = "";
                    for (int i = 0; i < size; i++)
                    {
                        CorrectCode += colors[code[i]] + ",";
                    }
                    cout << "Correct Guess: " << CorrectCode << endl;
                }
                do
                {
                    // get user input
                    cout << "Color " << i + 1 << ":  ";
                    cin >> choice;

                    // input validation
                    if (choice < 0 || choice > 5)
                    {
                        cout << "Error: Please enter a number from 0 to 5" << endl;
                    } else
                    {
                        guess[i] = choice;
                        i++;
                    }
                } while (choice < 0 || choice > 5 || i < size);


                Hint = CheckGuess(code, guess, size);
                cout << Hint << endl;
                if (Hint == "You win")
                {
                    string CorrectCode = "";
                    string GuessCode = "";
                    for (int i = 0; i < size; i++)
                    {
                        CorrectCode += colors[code[i]] + ",";
                        GuessCode += colors[guess[i]] + ",";
                    }

                    cout << "User Guess: " << GuessCode << endl;
                    cout << "Correct Guess: " << CorrectCode << endl;
                    break;
                } else
                {
                    round ++;
                    // debugging purposes
                    string CorrectCode = "";
                    string GuessCode = "";
                    for (int i = 0; i < size; i++)
                    {
                        CorrectCode += colors[code[i]] + ",";
                        GuessCode += colors[guess[i]] + ",";
                    }

                    cout << "User Guess: " << GuessCode << endl;
                    if (debug)
                    {
                        cout << "Correct Guess: " << CorrectCode << endl;
                    }
                }
            }
            if (round > 10 && run == true && Hint != "You Win")
            {
                cout << "You ran out of guesses you lose" << endl;
                string CorrectCode = "";
                string GuessCode = "";
                for (int i = 0; i < size; i++)
                {
                    CorrectCode += colors[code[i]] + ",";
                    GuessCode += colors[guess[i]] + ",";
                }

                cout << "User Guess: " << GuessCode << endl;
                cout << "The correct code was: " << CorrectCode << endl;
            }

            // ask if they want to play again
            cout << "Do you want to play again?(1 for yes 2 for no): ";
            cin >> choice2;
            if (choice2 == 1)
            {
                main();
            } else if (choice2 == 2)
            {
                run = false;
            }else
            {
                cout << "Error: Please enter a valid number" << endl;
            }
        }
    }
    cout << "Program ending" << endl;
    return 0;
}

// function to generate the code
void GenerateCode(int code[], int size)
{
    // for loop to generate a random number and add it to code array
    for (int i = 0; i < size; i++)
    {
        code[i] = rand() % 6; // generates numbers from 0 to 5
    }
}

// returns a string for the hint and also checks the code array against the guess array to make the hint
string CheckGuess(int code[], int guess[], int size)
{
    // variable that are needed for this function
    string hint; // the hint that we return
    int CorrectPosAnColor = 0; // a counter so we know how many black pegs to add to hint. Pos means position
    int CorrectColor = 0; // Only increments if the Color is right and the position is wrong basically for white pegs.
    bool usedCode[4] = {false, false, false, false}; // An array that's parallel with the code array that are bools to tell if I marked it as used or not as in has it been assign a peg yet
    bool usedGuess[4] = {false, false, false, false}; // An array that's parrel with the guess array that are bools to tell if I marked it as used or not as in has it been assign a peg yet

    // for black pegs ie if the color is in the right position, and it's the right color
    for (int i = 0; i < size; i++)
    {
        if (guess[i] == code[i])
        {
            CorrectPosAnColor++;
            usedCode[i] = true; // mark this code peg as used
            usedGuess[i] = true; // mark this guess as used
        }
    }

    //for white pegs ie if the color is right but not in the correct position
    for (int i = 0; i < size; i++) // i variable is the guess position
    {
        if (usedGuess[i] == true) // if its already been assigned to something skip it ie if it's a black peg don't bother checking it.
            continue;

        for (int j = 0; j < size; j++) // j is the code position
        {
            if (guess[i] == code[j] && i != j && !usedCode[j])
            {
                CorrectColor++;
                usedCode[j] = true;
                usedGuess[i] = true;
                break;
            }
        }
    }

    // if theirs 4 black pegs just tell the user they win
    if (CorrectPosAnColor == 4)
    {
        hint = "You win";
    } else if (CorrectColor == 0 && CorrectPosAnColor == 0) // if they somehow don't get any of the colors right at all then tell them None of them were right
    {
        hint = "None of them were right";
    } else // all other cases
    {
        // to add B tbh may remove comma
        for (int i = 0; i < CorrectPosAnColor && CorrectPosAnColor > 0; i++)
        {
            hint += "B";
        }
        // to add W
        for (int i = 0; i < CorrectColor && CorrectColor > 0; ++i)
        {
            hint += "W";
        }
    }
    return hint;
}

