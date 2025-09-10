#include <iostream>
using namespace std;

int main() {
    // init the numbers
    int numA, numB;
    int choice, answer;

    // ask for user input for numA and numB
    cout << "Please enter the first number: " << endl;
    cin >> numA;
    cout << "Please enter the second number: " << endl;
    cin >> numB;

    // menu options for the user
    cout << "Enter 1 to add the numbers" << endl;
    cout << "Enter 2 to subtract the numbers" << endl;
    cout << "Enter 3 to multiply the numbers" << endl;
    cout << "Enter 4 to exit" << endl;
    cout << "Please enter the choice: ";
    cin >> choice;

    // create switch statements for choice
    switch (choice) {
        case 1:
            answer = numA + numB;
            cout << "The sum of the two numbers is:  " << answer << endl;
            break;
        case 2:
            answer = numA - numB;
            cout << "The difference of the two numbers is:  " << answer << endl;
            break;
        case 3:
            answer = numA * numB;
            cout << "The product of the two numbers is:  " << answer << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
    }

    return 0;
}