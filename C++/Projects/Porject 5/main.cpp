#include <iostream>
#include <string>
#include <ctime>
#include <stack>
#include <queue>
#include "Books.h"
#include "Customer.h"
using namespace std;

// prototype function
void ViewStackBooks(stack <Book>& shelf1, Customer Bob);
void ViewQueueBooks(queue <Book>& shelf2, Customer Bob);
void CheckoutBookStack(stack <Book>& shelf1, Customer Bob);
void CheckoutBookQueue(queue <Book>& shelf2, Customer Bob);
void CheckinBookStack(stack <Book>& shelf1, Customer Bob);
void CheckinBookQueue(queue <Book>& shelf2, Customer Bob);

// global variable
bool run = true;

int main()
{
    stack <Book> Shelf1;
    queue <Book> Shelf2;
    // add books to stack and queue
    Shelf1.push(Book("Book 1","in stack"));
    Shelf1.push(Book("Book 2","in stack"));
    Shelf1.push(Book("Book 3","in stack"));
    Shelf2.push(Book("Book 4","in queue"));
    Shelf2.push(Book("Book 5","in queue"));
    Shelf2.push(Book("Book 6","in queue"));
    int choice;
    Customer Bob ("Bob");
    do
    {
        do
        {
            cout << "Menu Options" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Enter 1 to view Books on stack" << endl;
            cout << "Enter 2 to view Books on queue" << endl;
            cout << "Enter 3 to checkout Books on stack" << endl;
            cout << "Enter 4 to checkout Books on queue" << endl;
            cout << "Enter 5 to checkin Books on stack" << endl;
            cout << "Enter 6 to checkin Books on queue" << endl;
            cout << "Enter 7 to exist" << endl;
            cout << "----------------------------------------" << endl;
            cin >> choice;
            if (choice < 1 || choice > 7)
            {
                cerr << "Error: Invalid choice please choose a number from 1 to 7" << endl;
            }
        } while (choice < 1 || choice > 7);
        switch (choice)
        {
            case 1:
                ViewStackBooks(Shelf1, Bob);
                break;
            case 2:
                ViewQueueBooks(Shelf2, Bob);
                break;
            case 3:
                CheckoutBookStack(Shelf1, Bob);
                break;
            case 4:
                CheckoutBookQueue(Shelf2, Bob);
                break;
            case 5:
                CheckinBookStack(Shelf1, Bob);
                break;
            case 6:
                CheckinBookQueue(Shelf2, Bob);
                break;
            case 7:
                run = false;
                break;
        }
    } while (run);

    cout << "Program ending...." << endl;
    return 0;
}

void ViewStackBooks(stack <Book>& shelf1, Customer Bob)
{
    for (int i = 0; i < 3; i++)
    {
        shelf1.top().View();
        shelf1.pop();
        cout << "----------------------------------------" << endl;
    }
}
void ViewQueueBooks(queue <Book>& shelf2, Customer Bob)
{
    for (int i = 0; i < 3; i++)
    {
        shelf2.front().View();
        shelf2.pop();
        cout << "----------------------------------------" << endl;
    }
}
void CheckoutBookStack(stack <Book>& shelf1, Customer Bob)
{
    int choice;
    do
    {
        do
        {
            cout << "Which Book would you like to checkout? Enter 1 to choose a book enter 2 to view the books on the stack" << endl;
            cin >> choice;
            if (choice < 1 || choice > 2)
            {
                cerr << "Error: Invalid choice please choose 1 or 2" << endl;
            }
        } while (choice < 1 || choice > 2);
        if (choice == 2)
        {
            ViewStackBooks(shelf1, Bob);
        }
    } while (choice != 1);
    string name;
    bool bookinstack = false;
    do
    {
        cin.ignore();
        cout << "Enter name the name of the book you would like to checkout" << endl;
        getline(cin, name);
        cout << "Made it to line 128" << endl;
        do
        {
            if (!shelf1.empty())
            {
                cout << "Made it to line 138" << endl;
                shelf1.pop();
            } else
            {
                cout << "Made it to line 142" << endl;
                cerr << "Error: Book couldn't be found in the stack" << endl;
            }
        } while (name != shelf1.top().get_title() && !shelf1.empty());
        if (shelf1.empty())
        {
            break;
        }
        if (name == shelf1.top().get_title())
        {
            cout << "Made it to line 133" << endl;
            Bob.Checkout(shelf1.top());
            bookinstack = true;
        }
        cout << "Made it to line 146" << endl;
    } while (!bookinstack);

    cout << "Made it to line 149" << endl;
    cout << "Book successfully checked out" << endl;

}
void CheckoutBookQueue(queue <Book>& shelf2, Customer Bob)
{
    int choice;
    do
    {
        do
        {
            cout << "Which Book would you like to checkout? Enter 1 to choose a book enter 2 to view the books on the queue" << endl;
            cin >> choice;
            if (choice < 1 || choice > 2)
            {
                cerr << "Error: Invalid choice please choose 1 or 2" << endl;
            }
        } while (choice < 1 || choice > 2);
        if (choice == 2)
        {
            ViewQueueBooks(shelf2, Bob);
        }
    } while (choice != 1);
    string name;
    bool bookinqueue = false;
    do
    {
        cin.ignore();
        cout << "Enter name the name of the book you would like to checkout" << endl;
        getline(cin, name);
        cout << "Made it to line 175" << endl;
        do
        {
            if (!shelf2.empty())
            {
                cout << "Made it to line 185" << endl;
                shelf2.pop();
            } else
            {
                cout << "Made it to line 189" << endl;
                cerr << "Error: Book couldn't be found in the stack" << endl;
            }
            cout << "Made it to line 192" << endl;
        } while (name != shelf2.front().get_title() && !shelf2.empty());
        if (shelf2.empty())
        {
            break;
        }
        if (name == shelf2.front().get_title())
        {
            cout << "Made it to line 180" << endl;
            Bob.Checkout(shelf2.front());
            bookinqueue = true;
        }
        cout << "Made it to line 194" << endl;
    } while (!bookinqueue);

    cout << "Made it to line 197" << endl;
    cout << "Book successfully checked out" << endl;
}
void CheckinBookStack(stack <Book>& shelf1, Customer Bob)
{
    bool bookinqueue = false;
    do
    {
        do
        {
            if (!shelf1.empty())
            {
                cout << "Made it to line 241" << endl;
                shelf1.pop();
            } else
            {
                cout << "Made it to line 245" << endl;
                cerr << "Error: Book couldn't be found in the stack" << endl;
            }
            cout << "Made it to line 248" << endl;
        } while (Bob.get_book()->get_title() != shelf1.top().get_title() && !shelf1.empty());
        if (Bob.get_book()->get_title() == shelf1.top().get_title())
        {
            cout << "Made it to line 252" << endl;
            Bob.Checkout(shelf1.top());
            bookinqueue = true;
        }
        cout << "Made it to line 256" << endl;
    } while (!bookinqueue);

    cout << "Made it to line 259" << endl;
    cout << "Book successfully checked in" << endl;
}
void CheckinBookQueue(queue <Book>& shelf2, Customer Bob)
{
    bool bookinqueue = false;
    do
    {
        do
        {
            if (!shelf2.empty())
            {
                cout << "Made it to line 241" << endl;
                shelf2.pop();
            } else
            {
                cout << "Made it to line 245" << endl;
                cerr << "Error: Book couldn't be found in the stack" << endl;
            }
            cout << "Made it to line 248" << endl;
        } while (Bob.get_book()->get_title() != shelf2.front().get_title() && !shelf2.empty());
        if (Bob.get_book()->get_title() == shelf2.front().get_title())
        {
            cout << "Made it to line 252" << endl;
            Bob.Checkout(shelf2.front());
            bookinqueue = true;
        }
        cout << "Made it to line 256" << endl;
    } while (!bookinqueue);

    cout << "Made it to line 259" << endl;
    cout << "Book successfully checked in" << endl;
}
