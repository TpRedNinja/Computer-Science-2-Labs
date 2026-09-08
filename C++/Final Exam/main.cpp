// this program will create a instance of a food object and then store the object in an array
//there is a total of 5 errors in all 3 file however this file contains 2 errors in total
#include "Food.h"
#include <iostream>
using namespace std;

// main function
int main() {
    // get number of times for iterations
    int num_of_items = 0;
    cout << "How many items are you adding?: ";
    cin >> num_of_items;
    // Error 4: Forgot to put the class name in front of the name of the array.
    Food all_items[10];   // create Food Array to store product name, price and calorie count
    cout << "At Line 15" << endl;
    string product;
    double cost;
    int health;
    cout << "At Line 19" << endl;
    // for loop to get each food object
    for (int i = 0; i < num_of_items; i++) { // Error 5: set i to number of items instead of 0
        cout << "In for loop" << endl;
        cout << "Enter the new food product: ";
        cin >> product;
        cout << "Enter the cost of " << product <<": ";
        cin >> cost;
        cout << "Enter the number of calories in " << product <<": ";
        cin >> health;

        all_items[i] = Food(product,cost,health);
        //cout << all_items[i].num_of_calories; testing
    }
    // display all food objects in the array
    for (int i =0; i < num_of_items; i++) {
        all_items[i].display();
    }
    cout << endl;
    return 0;
}