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
bool debug = false; // bool for if debug is on or not

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
void debugMode(Book books [], Customer customers []);

int main() {
    srand((time(0)));
    Book books [ArraySize];
    Customer customers [ArraySize];
    menu(books, customers);

    return 0;
}

void menu(Book books [], Customer customers []) {
    int choice;
    do
    {
        do {
            cout << "---------------------------------------------" << endl;
            cout << "Enter 1 to add a new Book." << endl;
            cout << "Enter 2 to add a Customer." << endl;
            cout << "Enter 3 to view a Book's info." << endl;
            cout << "Enter 4 to view Customer info." << endl;
            cout << "Enter 5 to Checkout a Book" << endl;
            cout << "Enter 6 to Check in a Book" << endl;
            cout << "Enter 7 to Exit the program" << endl;
            cout << "Enter 8 to activate debug mode" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cerr << "Error: Invalid Input! Please enter a number" << endl;
            }
            else if (choice < 1 || choice > 8)
                cerr << "Error: Invalid Choice! Please Choose a number from the options listed" << endl;
        } while (choice < 1 || choice > 8);

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
                break;
            case 6:
                Checkin(books, customers);
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            case 8:
                debugMode(books, customers);
                break;
            default:
                break;
        }

        if (choice == 7)
        {
            break;
        }
    } while (true);

}

void debugMode(Book books[], Customer customers[]) {
    static bool initialized = false; // ensures debug objects are only created once

    // toggle debug mode
    debug = !debug;
    cout << "Debug mode is now " << (debug ? "ON" : "OFF") << endl;

    if (debug && !initialized) {
        // only add debug objects once
        cout << "---------------------------------------------" << endl;
        cout << "Adding debug book and customer..." << endl;
        //cout << "---------------------------------------------" << endl;
        books[numBooks] = Book("Batman: Arkham Knight", "Rocksteady", 1900, 59.99);
        books[numBooks].View();
        numBooks++;

        cout << "---------------------------------------------" << endl;
        customers[numCustomers] = Customer("Bruce Wayne", "Wayne Manor");
        customers[numCustomers].View();
        numCustomers++;

        initialized = true; // mark that debug objects have been created
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

}

void CopyBook(Book books [], Customer customers []) {
    int Undefined = 0;
    int choice;
    string choiceStr;

    do
    {
        // check to make sure there is a book to be copied
        for (int i = 0; i < ArraySize; i++) {
            if (books[i].get_title() == "Undefined") {
                Undefined ++;
            }
        }
        // max array size so if they all have an "Undefined" title which is the default title then there is no book to copy
        // or if there is less than 2 books available to copy
        if (Undefined == 50 && numBooks == 0) {
            cerr << "Error: No books to copy" << endl;
            break;
        }
        choice = 0;
        do {
            do {
                cout << "Which book would you like to copy?(Select a number from 0 - " << numBooks - 1 << ")"<< endl;
                cin >> choice;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: Invalid Input! Please enter a number" << endl;
                }
                else if (choice < 0 || choice >= numBooks)
                    cerr << "Error: Invalid Choice! Please enter a number: from 0 to " << numBooks - 1 << endl;
            } while (choice < 0 || choice >= numBooks);

            cout << "Just to confirm you want to copy this book? (yes/no): " << endl;
            books[choice].View();
            cin >> choiceStr;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // lower case the whole string
            for (int i = 0; i < choiceStr.length(); i++) {
                if (isupper(choiceStr[i]))
                    choiceStr[i] = tolower(choiceStr[i]);
            }
            // if yes or similar word copy the book
            if (choiceStr == "yes" || choiceStr == "y" || choiceStr == "ye" || choiceStr == "yep") {
                books[numBooks] = Book(books[choice]);
                cout << "---------------------------------------------" << endl;
                cout << "Book copied successfully" << endl;
                cout << "New book details: " << endl;
                books[numBooks].View();
                numBooks++;
                cout << "---------------------------------------------" << endl;
            } else
                cout << "Copy Canceled" << endl;
        } while (choiceStr != "yes" && choiceStr != "y" && choiceStr != "ye" && choiceStr != "yep");
        do {
            cout << "Enter 1 to copy another book or 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail())
            {
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cerr << "Error: Invalid Input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid Choice! Please enter a number: 1 or 2" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);

}

void AddCustomer(Book books [], Customer customers []) {
    string name;
    string address;
    int choice;
    do {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the name of the customer you want to add: ";
        getline(cin, name);
        cout << "Enter the address of the customer you want to add: ";
        getline(cin, address);
        customers[numCustomers] = Customer(name, address);
        cout << "---------------------------------------------" << endl;
        cout << "New customer added" << endl;
        cout << "New Customer details: " << endl;
        customers[numCustomers].View(); // show the new customers details
        cout << "---------------------------------------------" << endl;
        numCustomers++;
        do {
            cout << "Enter 1 to add a new customer or 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid Input! Please enter a number" << endl;
            }
            else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid Choice! Please enter a number: 1 or 2" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);


}

void ViewBook(Book books[], Customer customers[]) {
    int choice;
    int bookNum;
    do {
        do {
            cout << "Enter the book number you would like to view(valid numbers are: 0 - " << numBooks - 1 << "): " << endl;
            cin >> bookNum;
            if (cin.fail()) {
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
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);

}

void ViewCustomers(Book books[], Customer customers[]) {
    int choice;
    int customerNum;
    do {
        do {
            cout << "Enter the customer number you would like to view(valid numbers are: 0 - " << numCustomers - 1 << "): " << endl;
            cin >> customerNum;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (customerNum < 0 || customerNum >= numCustomers)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (customerNum < 0 || customerNum >= numCustomers);
        customers[customerNum].View();
        do {
            cout << "Enter 1 to view another customer or enter 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (choice < 1 || choice > 2);
    } while (choice != 2);

}

void Checkout(Book books[], Customer customers[]) {
    int booknum; // book number the user wants to use
    int customernum; // customer number user wants to use
    int UndefinedBooks = 0; // number of undefined book objects in the array
    int UndefinedCustomers = 0; // number of undefined customer objects in the array
    int IneligibleCustomers = 0; // number of ineligible customers
    int choice;
    do {
        // check to make sure there is a book to be copied
        for (int i = 0; i < ArraySize; i++) {
            if (books[i].get_title() == "Undefined")
                UndefinedBooks ++;
            if (customers[i].get_name() == "John Doe" || customers[i].get_name() == "Jane Doe")
                UndefinedCustomers ++;
        }
        // check how many customers can check out a book
        for (int i = 0; i < numCustomers - 1; i++) {
            if (customers[i].get_date_check_out() != "" && customers[i].get_date_check_out() != "00/00/0000")
                IneligibleCustomers ++;
        }
        // max array size so if they all have an "Undefined" title which is the default title then there is no book to copy
        // or if there is less than 2 books available to copy
        if (UndefinedBooks == 50 && UndefinedCustomers == 50) {
            cerr << "Error: No books or customers initialized" << endl;
            cout << "Returning to menu...." << endl;
            break;
        } else if (UndefinedBooks == 50 && UndefinedCustomers < 50) {
            cerr << "Error: No books initialized" << endl;
            cout << "Returning to menu...." << endl;
            break;
        } else if (UndefinedBooks < 50 && UndefinedCustomers == 50) {
            cerr << "Error: No customers initialized or name equals john doe or jane doe" << endl;
            cout << "Returning to menu...." << endl;
            break;
        }else if (IneligibleCustomers == numCustomers) {
            cout << IneligibleCustomers << endl;
            cerr << "Error: No customers can checkout any books" << endl;
            cout << "Returning to menu...." << endl;
            break;
        }else {
            do {
                cout << "Which book would you like to checkout?(Enter a number from 0 to " << numBooks - 1 << "): " << endl;
                cin >> booknum;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: Invalid input! Please enter a number" << endl;
                } else if (booknum < 0 || booknum >= numBooks)
                    cerr << "Error: Invalid input! Please enter a valid number" << endl;
            } while (booknum < 0 || booknum >= numBooks);
            do {
                cout << "Which customer is checking the book out?(Enter a number from 0 to " << numCustomers - 1 << "): " << endl;
                cin >> customernum;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: Invalid input! Please enter a number" << endl;
                } else if (customernum < 0 || customernum >= numCustomers)
                    cerr << "Error: Invalid input! Please enter a valid number" << endl;
            } while (customernum < 0 || customernum >= numCustomers);

            cout << "Checking book out..." << endl;
            customers[customernum].Checkout(books[booknum]);
            do {
                cout << "Enter 1 to have another customer checkout or 2 to return to mainmenu" << endl;
                cin >> choice;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: Invalid input! Please enter a number" << endl;
                } else if (choice < 1 || choice > 2)
                    cerr << "Error: Invalid input! Please enter a valid number" << endl;
            } while (choice < 1 || choice > 2);
            if (choice == 2)
                break;
        }
    } while (choice != 2);


}

void Checkin(Book books[], Customer customers[]) {
    bool oneBooksCheckedOut = true; // bool to see if theirs at minimum 1 book checked out
    int choice;
    int totalNotCheckOutBooks;

    do {
        int undefinedBooks = 0;
        int customernum = 0;
        for (int i = 0; i < ArraySize; i++) {
            if (books[i].get_title() == "Undefined")
                undefinedBooks++;
        }
        if (undefinedBooks == 50) {
            cerr << "Error: No books are defined, no books can be checked in" << endl;
            cout << "Returning to menu...." << endl;
            oneBooksCheckedOut = false;
        }
        for (int i = 0; i < numBooks-1; i++) {
            if (!books[i].get_ischeckout()) {
                cout << "Made it here" << books[i].get_ischeckout() << endl;
                if (numBooks == 1) { // if there is only 1 book initialized
                    cerr << "Error: All books are check in" << endl;
                    cout << "Returning to menu...." << endl;
                    oneBooksCheckedOut = false;
                    break;
                } else // if theirs more than 1 book
                {
                    totalNotCheckOutBooks++;
                    continue;
                }
            }
        }
        if (totalNotCheckOutBooks == numBooks - 1) { // if it equals to total of numBooks then set flag to false
            cerr << "Error: No books are checked out" << endl;
            cout << "Returning to menu...." << endl;
            oneBooksCheckedOut = false;
        }

        while (oneBooksCheckedOut)
        {
            do {
                cout << "Which customer is checking their book in?(Enter number from 0 to " << numCustomers - 1 << "): " << endl;
                cin >> customernum;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: Invalid input! Please enter a number" << endl;
                } else if (customernum < 0 || customernum >= numCustomers)
                    cerr << "Error: Invalid input! Please enter a valid number" << endl;
            } while (customernum < 0 || customernum >= numCustomers);
            customers[customernum].Checkin();
            break;
        }
        do
        {
            cout << "Enter 1 to check another customers book in or 2 to return to menu" << endl;
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Invalid input! Please enter a number" << endl;
            } else if (choice < 1 || choice > 2)
                cerr << "Error: Invalid input! Please enter a valid number" << endl;
        } while (choice < 1 || choice > 2);
        if (choice == 2)
            break;

    } while (oneBooksCheckedOut);

}
