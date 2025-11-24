#include <iostream>
#include <cctype>
#include "Book.h"
#include "Customer.h"
#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>
using namespace std;

// global variables
const int ArraySize = 50;
int numBooks = 0; // store the number how many books we have
int numCustomers = 0; // store the number of customers we have

// prototype functions
// need to add these "Book books [ArraySize], Customer customers [ArraySize]" as args so we can call menu with no issues
void menu(Book books [], Customer customers []);
void AddBook(Book books [], Customer customers[]);
void CopyBook(Book books [], Customer customers[]);
void AddCustomer(Book books[], Customer customers[]);
void ViewBook(Book books [], Customer customers []);
void ViewCustomers(Book books [], Customer customers []);
void Checkout(Book books [], Customer customers []);
void Checkin(Book books [], Customer customers []);

int main() {
    srand((time(0)));
    Book books [ArraySize];
    Customer customers [ArraySize];
    menu(books, customers);

    return 0;
}

void menu(Book books [], Customer customers []) {
    int choice;
    do {
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
            cerr << "Error: Invalid Choice! Please Choose a number from the options listed" << endl;
    } while (choice < 1 || choice > 7);

    switch (choice)
    {
        case 1:
            AddBook(books, customers);
            break;
        case 2:
            AddCustomer(books, customers);
            break;
        case 3:
            ViewBook(books, customers);
            break;
        case 4:
            ViewCustomers(books, customers);
            break;
        case 5:
            Checkout(books, customers);
        case 6:
            Checkin(books, customers);
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            break;
    }
}

void AddBook(Book books [], Customer customers []) {
    int choice;
    string title;
    string author;
    int num_of_pages;
    double cost;
    do
    {
        do {
            cout << "Enter 1 to add a new Book.\nEnter 2 to copy a book" << endl;
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cerr << "Error: Invalid Input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid Input! Please enter a number: 1 or 2" << endl;
        } while (choice < 1 || choice > 2);

        if (choice == 2)
            CopyBook(books, customers);
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline
            cout << "Enter the title of the book: ";
            getline(cin, title);
            cout << "Enter the author of the book: ";
            getline(cin, author);
            do
            {
                cout << "Enter the cost of the book: ";
                cin >> cost;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "\nError: Invalid Input! Please enter a number" << endl;
                } else if (cost <= 0)
                    cerr << "\nError: Invalid Input! Please enter a number that is greater than 0" << endl;
            } while (cost <= 0);
            do
            {
                cout << "Enter the number of pages: ";
                cin >> num_of_pages;
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "\nError: Invalid Input! Please enter a number" << endl;
                }
                if (num_of_pages <= 0)
                    cerr << "\nError: Invalid Input! Please enter a number that is greater than 0" << endl;
            } while (num_of_pages <= 0);

            // add the book to the array
            books[numBooks] = Book(title, author, num_of_pages, cost);
            cout << "New book added" << endl;
            cout << "New Book details" << endl;
            books[numBooks].View();
            numBooks++;
            choice = 0;
            do
            {
                cout << "Enter 1 to add a new book or copy a book or 2 to return to menu" << endl;
                cin >> choice;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: Invalid Input! Please enter a number" << endl;
                }
                else if (choice < 1 || choice > 2)
                    cerr << "Error: Invalid Choice! Please enter a number: 1 or 2" << endl;
            } while (choice < 1 || choice > 2);

        }
    } while (choice != 2);
    menu(books, customers);
}

void CopyBook(Book books [], Customer customers [])
{
    int Undefined = 0;
    int choice;
    string choiceStr;

    do
    {
        // check to make sure there is a book to be copied
        for (int i = 0; i < ArraySize; i++)
        {
            if (books[i].get_title() == "Undefined")
            {
                Undefined ++;
            }
        }
        // max array size so if they all have an "Undefined" title which is the default title then there is no book to copy
        // or if there is less than 2 books available to copy
        if ((Undefined == 50 && numBooks == 0) || numBooks < 2)
        {
            if (Undefined == 50 && numBooks == 0)
                cerr << "Error: No books to copy" << endl;
            else
                cerr << "Error: Not enough books please make sure theirs at least 2 books already added" << endl;
            break;
        }
        choice = 0;
        do
        {
            do
            {
                cout << "Which book would you like to copy?(Select a number from 0 - " << numBooks - 1 << ")"<< endl;
                cin >> choice;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: Invalid Input! Please enter a number" << endl;
                }
                else if (choice < 0 || choice >= numBooks)
                {
                    cerr << "Error: Invalid Choice! Please enter a number: from 0 to " << numBooks - 1 << endl;
                }
            } while (choice < 0 || choice >= numBooks);

            cout << "Just to confirm you want to copy this book? (yes/no): " << endl;
            books[choice].View();
            cin >> choiceStr;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // lower case the whole string
            for (int i = 0; i < choiceStr.length(); i++)
            {
                if (isupper(choiceStr[i]))
                    choiceStr[i] = tolower(choiceStr[i]);
            }
            // if yes or similar word copy the book
            if (choiceStr == "yes" || choiceStr == "y" || choiceStr == "ye" || choiceStr == "yep")
            {
                books[numBooks] = Book(books[choice]);
                cout << "---------------------------------------------" << endl;
                cout << "Book copied successfully" << endl;
                cout << "New book details: " << endl;
                books[numBooks].View();
                cout << "---------------------------------------------" << endl;
            } else
                cout << "Copy Canceled" << endl;
        } while (choiceStr != "yes" && choiceStr != "y" && choiceStr != "ye" && choiceStr != "yep");
        do
        {
            cout << "Enter 1 to copy another book or 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail())
            {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cerr << "Error: Invalid Input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid Choice! Please enter a number: 1 or 2" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);
    menu(books, customers);
}

void AddCustomer(Book books [], Customer customers [])
{
    string name;
    string address;
    int choice;
    do
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the name of the customer you want to add: ";
        getline(cin, name);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the address of the customer you want to add: ";
        getline(cin, address);
        customers[numCustomers] = Customer(name, address);
        cout << "---------------------------------------------" << endl;
        cout << "New customer added" << endl;
        cout << "New Customer details: " << endl;
        customers[numCustomers].View(); // show the new customers details
        cout << "---------------------------------------------" << endl;
        numCustomers++;
        do
        {
            cout << "Enter 1 to add a new customer or 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid Input! Please enter a number" << endl;
            }
            else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid Choice! Please enter a number: 1 or 2" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);
    menu(books, customers);

}

void ViewBook(Book books[], Customer customers[])
{
    int choice;
    int bookNum;
    do
    {
        do
        {
            cout << "Enter the book number you would like to view(valid numbers are: 0 - " << numBooks << "): " << endl;
            cin >> bookNum;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (bookNum < 0 || bookNum >= numBooks)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (bookNum < 0 || bookNum >= numBooks);
        books[bookNum].View();
        do
        {
            cout << "Enter 1 to view another book or enter 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);
    menu(books, customers);
}

void ViewCustomers(Book books[], Customer customers[])
{
    int choice;
    int customerNum;
    do
    {
        do
        {
            cout << "Enter the customer number you would like to view(valid numbers are: 0 - " << numCustomers << "): " << endl;
            cin >> customerNum;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (customerNum < 0 || customerNum >= numCustomers)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (customerNum < 0 || customerNum >= numCustomers);
        customers[customerNum].View();
        do
        {
            cout << "Enter 1 to view another customer or enter 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);
    menu(books, customers);
}

void Checkout(Book books[], Customer customers[]) {
    int booknum;
    int customernum;
    cout << "Which customer is checking out a book?(Enter numbers from 0 - " << numCustomers << "): " << endl;
    cin >> customernum;
    if (customers[customernum].get_date_check_out() == "00/00/0000")
    {

    }
}

void Checkin(Book books[], Customer customers[])
{
    cout << "In progress. Returning to menu...." << endl;
    menu(books, customers);
}
