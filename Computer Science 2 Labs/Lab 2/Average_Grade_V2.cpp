// NOLINT(clang-diagnostic-narrowing, clang-diagnostic-integer-division)
/*
 * This program was written by Harris Domangue for CMSC-202-65 Lab # 2 on Sept 10th 2025
 * The purpose of this program is to find the average grade of the user and tell them if they passed or failed
*/

#include <iostream> // Need this for user input(i think)
#include <string> // Need this to use string
#include <iomanip>
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
    int count = 0; // Number of assignments the user enter
    double score = 0; // Score of each assignment the user enters
    double total = -1; // Total score of each assignment added together
    double average = -1; // set average to -1 for reasons I forget why
    int assignments; // How many assignments the user has
    cout << "How many assignments do you have? ";
    cin >> assignments;

    for (int i = 0; i < assignments; i++)
    {
        count ++;
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
                total = score;
            } else
            {
                total += score;
            }
        }
    }
    if (total > -1)
    {
        average = total / count;
    } else {
        average = 0;
    }
    return average;
}

// This function finds out which letter grade the user got for their average
string GetUserGrade(double average)
{
    string grade;
    if (average >= 60) {
        grade = "Congratulations you have passed this course! :)";
    } else {
        grade = "You have failed this course! :(";
    }

    return grade;
}

// Main function calls other functions and displays output and stuff
int main()
{
    cout << "This program will get your grade average and tell you if you passed or failed.\n";
    while (true)
    {
        if (StopProgram == false)
        {
            cout << "To end the program type 'stop' as your name or enter '-2' as a score\n";
            string username = GetUserName();
            double average = 0;
            if (average >= 0 && StopProgram == false)
            {
                double average = GetUserScore(); // the exact average number that's more than 2 decimal places
                if (average > 0) {
                    string grade = GetUserGrade(average);
                    cout << setprecision(2) << fixed;
                    cout << "Total score is " << average << endl;
                    cout << grade << endl;
                } else {
                    cout << "Error could not calculate average due to Assignments scores ending prematurely" << endl;
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