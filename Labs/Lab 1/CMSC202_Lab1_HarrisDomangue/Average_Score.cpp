// NOLINT(clang-diagnostic-narrowing, clang-diagnostic-integer-division)
/*
 * This program was written by Harris Domangue for CMSC-202-65 Lab # 1 on Sept 5th 2025
 * The purpose of this program is to find the average grade of the user
 * Side note 1: figured out how to change the comment line color because grey is hard to read imo
 * Side note 2: I Figured out how to make the beginning brace to be on a new line that's just a me preference again
*/

#include <iostream> // Need this for user input(i think)
#include <string> // Need this to use string
using namespace std; // Need this so I don't have to do std::

// variable for all functions to use
bool StopProgram = false; // flag for if the user wants to end the program

// Function to validate whether the users name is correct
string GetUserName()
{
    string name; // To store the users name
    string answer; // stores if the username is correct
    bool IsCorrect = false; // stores whether we got the name correct

    cout << "Please enter your name: ";
    cin >> name;
    // lower case the name to check the condition
    for (int i = 0; i < name.length(); i++)
    {

        name[i] = tolower(name[i]); // NOLINT
    }
    if (name == "stop") // checks if the user wants to end the program by entering stop
    {
        StopProgram = true;
        IsCorrect = true;
    } else
    {
        // upper case the first letter for displaying the name
        for (int i = 0; i < 1; i++)
        {
            name[i] = toupper(name[i]); // NOLINT
        }
        cout << "Your name is " << name << " is that correct?\nEnter(Yes/No): ";
        cin >> answer;
    }
    // check if we got the users name correct
    while (IsCorrect == false)
    {
        for (int i = 0; i < answer.length(); i++)
        {
            answer[i] = tolower(answer[i]); //NOLINT
        }
        if (answer == "yes")
        {
            IsCorrect = true;
        }
        else if (answer == "no")
        {
            IsCorrect = false;
            cout << "Sorry for getting your name wrong. Please reenter your name: ";
            cin >> name;
            cout << "Your name is " << name << " is that now correct?\nEnter(Yes/No): ";
            cin >> answer;
        } else
        {
            IsCorrect = false;
            cout << "Error! Wrong input. Please try again.\n";
            cout << "Please enter yes or no to the prompt \n";
            cout << "Your name is " << name << " is that correct? \nEnter Yes or No: ";
            cin >> answer;
        }
    }
    return name;
}
/* This function asks for the users score for each assignment they have until they enter -1.
 * Also calculates the average score the user got
*/
double GetUserScore()
{
    int count = 1; // Number of assignments the user enter
    double score = 0; // Score of each assignment the user enters
    double total = -1; // Total score of each assignment added together
    double average = -1;

    while (true)
    {
        cout << "Please enter your score for Assignment #" << count << "(Enter -1 to stop, -2 to exit program): ";
        cin >> score;

        if (score < -2 || score > 100)
        {
            cout << "Please enter a score between 0 and 100.\n";
        } else if (score == -1)
        {
            count -= 1; // adjust count for normal average calculation
            break; // exit while loop
        } else if (score == -2)
        {
            StopProgram = true;
            break; // exit the function early and exit the while loop
        } else
        {
            if (total == -1)
            {
                total = 0;
            } else
            {
                total += score;
            }
            count++;
        }
    }
    if (total > -1)
    {
        average = total / count;
    }
    return average;
}

// This function finds out which letter grade the user got for their average
string GetUserGrade(double average)
{
    string grade;
    if (average >= 90) // grades from 90-100%
    {
        grade = "A";
    } else if (average > 80) // grades of 80-89.99%
    {
        grade = "B";
    } else if (average > 70) // grades of 70-79.99%
    {
        grade = "C";
    } else if (average > 60) // grades of 60-69.99%
    {
        grade = "D";
    } else // grades less than 60%
    {
        grade = "F";
    }
    return grade;
}

// Main function calls other functions and displays output and stuff
int main()
{
    cout << "The purpose of this program is to find your average grade\n";
    while (true)
    {
        if (StopProgram == false)
        {
            cout << "To end the program type 'stop' as your name or enter '-2' as a score\n";
            string username = GetUserName();
            double ExactAverage = GetUserScore(); // the exact average number that's more than 2 decimal places
            int TempAverage = ExactAverage * 100; // NOLINT // convert it into an int so that way we can only keep up to 2 decimal places
            double average = TempAverage / 100; //NOLINT // to convert it to only have two decimal places without rounding
            if (average >= 0)
            {
                string grade = GetUserGrade(average);
                if (grade == "A" || grade == "B")
                {
                    cout << "Good Job "<< username << "! You got a " << average << "%. Which is a " << grade << ". Keep up the good work :).";
                } else if (grade == "C")
                {
                    cout << "Okay Job "<< username << ". You got a " << average << "%. Which is a " << grade << ". Try to get your grade up I believe in you :).";
                } else
                {
                    cout << username << "you got a " << average << "%. Which is a " << grade << ". Try to do better next time I believe in you :).";
                }
            }
        } else
        {
            break; // break if true which is the only other option lol.
        }

    }
    cout << "Program ending"; // let the user know the program is ending
    return 0; // need to return 0 here because it's the norm. Theirs probably a better reason but that's mine
}