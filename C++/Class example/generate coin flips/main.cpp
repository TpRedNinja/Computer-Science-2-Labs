#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int flip(); // prototype for flip function
bool check(int,int,int); // prototype for checking
void bar(int); // prototype for a bar string

int main() {
    srand(time(NULL));
    int count, number_of_flips = 0;
    int number_of_simulations = 0;

    // get how many simulations the user wants to do
    cout << "Enter number of test cases: ";
    cin >> number_of_simulations;

    for (int i = 0; i < number_of_simulations; i++) {
        number_of_flips = 1;
        while (!check(flip(),flip(),flip())) {
            number_of_flips++;
        }
        cout << "Simulation "<< i+1 << ": ";
        bar(number_of_flips);
    }

    return 0;
}

int flip() {
    int number, lower = 0, upper = 1;
    number = rand() % (upper - lower + 1);
    return number;
}

bool check(int num1, int num2, int num3) {
    if (num1 == num2 && num2 == num3 && num1 == num3)
        return true;
    else
        return false;
}
void bar(int num) {
    string bar = "";
    for (int i = 0; i < num; i++) {
        bar.append("|");
    }
    cout << bar << endl;
}