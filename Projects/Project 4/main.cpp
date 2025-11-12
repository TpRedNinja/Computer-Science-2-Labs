#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout << "---------------------------------------------" << endl;
        cout << "Enter 1 to add a new Book." << endl;
        cout << "Enter 2 to add a Customer." << endl;
        cout << "Enter 3 to view a Book's info." << endl;
        cout << "Enter 4 to view Customer info." << endl;
        cout << "Enter 5 to checkout a Book" << endl;
        cout << "Enter 6 to Check in a Book" << endl;
        cout << "Enter 7 to Exit the program" << endl;
        cout << "---------------------------------------------" << endl;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cerr << "Error: Invalid Input! Please enter a number" << endl;
        }
        else if (choice < 1 || choice > 7)
        {
            cerr << "Error: Invalid Choice! Please Choose a number from the options listed" << endl;
        }
    } while (choice < 1 || choice > 7);
    return 0;
}