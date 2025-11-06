#include <algorithm>
#include <iostream>
#include <utility> // gives access to swap
using namespace std;

void sortArray(int startPoint, int to_sort[], int size);
void printArray(int to_sort[], int size);
void resetArray(int to_sort[], int copy_to_sort[], int size);
bool debug = false;
bool run = true;

int main()
{
    int to_sort[] = { 4 ,8, 1, 5, 2, 10, 9, 6, 7, 3 }; // array we need to sort
    int copy_to_sort[] = { 4, 8, 1, 5, 2, 10, 9, 6, 7, 3 }; // copy of the array we need to sort
    int size = sizeof(to_sort) / sizeof(to_sort[0]); // the size of the array
    int startPoint; // user input for the start point

    while (run)
    {
        int choice, choice2;
        do
        {
            cout << "Would you like to enter debug mode? 1 for yes 2 for no: ";
            cin >> choice2;
            if (choice2 < 1 || choice2 > 2)
                cout << "Error: invalid input" << endl;
        } while (choice2 < 1 || choice2 > 2);

        switch (choice2)
        {
            case 1:
                debug = true;
                break;
            case 2:
                debug = false;
                break;
        }

        cout << "This program we will be sorting an array using the user insertion algorithm" << endl;
        cout << "We are gonna sort this array: ";
        printArray(to_sort, size); // print the unsorted array
        do
        {
            cout << "please select a index to start with: ";
            cin >> startPoint;

            if (startPoint < 0 || startPoint >= size)
            {
                cout << "Error: not in array scope" << endl;
            }
        } while (startPoint >= size || startPoint < 0);

        cout << "Sorting ..." << endl;
        sortArray(startPoint, to_sort, size);

        cout << "sorted array: ";
        printArray(to_sort, size);
        do
        {
            cout << "would you like to run this again? 1 for yes 2 for no: ";
            cin >> choice;
            if (choice < 1 || choice > 2)
                cout << "Error: invalid input" << endl;
        } while (choice < 1 || choice > 2);

        switch (choice)
        {
            case 1:
                resetArray(to_sort, copy_to_sort, size);
                break;
            case 2:
                run = false;
                break;
        }

    }
    return 0;
}

void sortArray(int startPoint, int to_sort[], int size)
{
    int current = startPoint;
    bool changesMade;
    int loop1, loop2 = 0;
    do
    {

        loop1 = loop2+1;
        loop2 = loop1;
        changesMade = false;
        // move left in the array from the start point
        while (current > 0 && to_sort[current] < to_sort[current-1])
        {
            swap(to_sort[current], to_sort[current-1]);
            if (debug)
                printArray(to_sort, size); // print the array
            current--;
            changesMade = true;
        }

        // move right in the array from the start point
        while (current < size-1 && to_sort[current] > to_sort[current+1])
        {
            swap(to_sort[current], to_sort[current+1]);
            if (debug)
                printArray(to_sort, size); // print the array
            current++;
            changesMade = true;
        }
        if (debug)
            cout << "---------------------------------" << endl;
        if (changesMade && loop1 != loop2 || loop1 == loop2)
        {
            for (int i = 0; i < size-1; i++)
            {
                if (to_sort[i] > to_sort[i+1])
                {
                    swap(to_sort[i], to_sort[i+1]);
                    changesMade = true;
                    if (debug)
                        printArray(to_sort, size); // print the array
                }
            }
        }
    } while (changesMade);
}

void printArray(int to_sort[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            cout << "to_sort = { " << to_sort[i] << ", ";
        else if ( i == size - 1)
            cout << to_sort[i] << " }" << endl;
        else
            cout << to_sort[i] << ", ";
    }
}

void resetArray(int to_sort[], int copy_to_sort[], int size)
{
    for (int i = 0; i < size; i++)
        to_sort[i] = copy_to_sort[i];
}