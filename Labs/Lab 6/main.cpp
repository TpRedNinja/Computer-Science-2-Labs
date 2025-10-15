#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main()
{
    // variables to get user input
    string name;
    int age;
    double weight;
    double height;
    string health;

    Person p;
    cout << "This program will calculate your BMI and tell you it." << endl;

    // get the users name, age, weight, and height
    // get users first name
    cout << "please enter your first name: ";
    cin >> name;
    p.setName(name); // send name over so its set

    // get users game
    cout << "please enter your age: ";
    cin >> age;
    p.setAge(age); // send the age over so its set

    // get users weight in pounds
    cout << "please enter your weight(in pounds): ";
    cin >> weight;
    p.setWeight(weight); // send the weight over so its set

    // get the users height in inches
    cout << "please enter your height(in inches): ";
    cin >> height;
    p.setHeight(height); // set the heigh over so its set


    // get users health and display it
    p.getHealth(weight, height, name);

    return 0;
}