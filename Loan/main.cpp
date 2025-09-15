#include <iostream>
#include <string>
using namespace std;

int main() {
    //init our variables
    double debt, salary, loanAmount;
    int years;
    char isEmployed;

    // display to user
    cout << "This Program will help you get a loan!" << endl;

    do {
        // get the salary from the user
        cout << "Enter your salary: ";
        cin >> salary;

        // get number of years on job
        cout << "Enter the number of years on the job: ";
        cin >> years;

        // get debt amount
        cout << "Enter the amount of debt you have: ";
        cin >> debt;

        // get employment status
        cout << "Are you currently employed? y for yes  n for no: ";
        cin >> isEmployed;
    } while (salary < 0 || debt < 0 || years < 0);

    if (isEmployed == 'y') {
        if (salary >= 35000 && years >= 2) {
            loanAmount = salary * .35;
            loanAmount -= debt;

            if (loanAmount <= 0)
                cout << "You do not qualify for a loan." << endl;
            else
                cout << "You qualify for a loan: $" << loanAmount << endl;
        } else if (years < 2) {
            cout << "You have not had your job long enough for the loan";
        } else {
            cout << "You do not have earn enough to qualify for a loan.";
        }
    } else {
        cout << "You must currently be employed for a loan.";
    }
    return 0;
}