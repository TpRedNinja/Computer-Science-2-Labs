#include <iostream>
#include <string>
using namespace std;

int main() {
    // init list included here
    string employees[] = {"Spongebob", "Squidward", "Mr.Krabs"};
    int hours[3]; // this has a number declared for the size of the array
    int pay[] = {10, 50, 100};
    int size = sizeof(hours) / sizeof(hours[0]);

    // get the hours for each employee
    for (int i = 0; i < size; i++) {
        cout << "Hours " << employees[i] << " worked: ";
        cin >> hours[i];
    }

    // range based for loop to show the values entered
    int index = 0; // we should have just used a regular for loop.
    for (int h : hours) {
        int p = pay[index] * hours[index];
        cout << employees[index] << " worked " << h << " hours and made $" << p << " dollars" << endl;
        index ++;
    }

    return 0;
}