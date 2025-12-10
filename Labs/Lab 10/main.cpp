#include <algorithm>
#include <iostream>
#include <utility> // gives access to swap
using namespace std;

void sortArray(int startPoint, int to_sort[], int size);
void printArray(int to_sort[], int size);
void resetArray(int to_sort[], int copy_to_sort[], int size);
bool debug = false; // to enable to disable some debug statements
bool run = true; // to determine if the program is running or not
bool yeet = false; // just to disable some debug statements
int timesCalled = 0;

int main()
{
    int to_sort[] = { 4 ,8, 1, 5, 2, 10, 9, 6, 7, 3 }; // array we need to sort
    int copy_to_sort[] = { 4 ,8, 1, 5, 2, 10, 9, 6, 7, 3 }; // copy of the array we need to sort
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

        cout << "This program we will be sorting an array using the highest to lowest or lowest to highest algorithm" << endl;
        cout << "We are gonna sort this array: ";
        printArray(to_sort, size); // print the unsorted array
        do
        {
            cout << "Do you want to start with the lowest number or the highest number? (Enter 1 for lowest and 2 for highest): ";
            cin >> startPoint;

            if (startPoint < 1 || startPoint > 2)
            {
                cerr << "Error: please select 1 or 2" << endl;
            }
        } while (startPoint > 2 || startPoint < 1);

        cout << "Sorting ..." << endl;
        sortArray(startPoint, to_sort, size);

        cout << "sorted array: ";
        printArray(to_sort, size);
        if (debug)
            cout << "total times: " << timesCalled << endl;
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
                timesCalled = 0;
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
    bool lowest = false;
    bool highest = false;
    int maxIndex, minIndex ;

    if (startPoint == 1) { // start with the lowest number and go up
        lowest = true;
    } else if (startPoint == 2) { // start with the highest number and go down
        highest = true;
    }

    if (lowest)
    {
        minIndex = 0;
        for (int i = 0; i < size; i++)
        {
            if (to_sort[i] < to_sort[minIndex])
                minIndex = i;
        }
        swap(to_sort[minIndex], to_sort[0]); // swap index 2 and 0
        if (debug && yeet)
            cout << to_sort[0] << ", " << to_sort[minIndex] << endl;
        if (debug)
            printArray(to_sort, size);
        for (int i = 1; i < size; i++)
        {
            if (debug && yeet)
                cout << i << endl;
            for (int j = i + 1; j < 10; j++)
            {
                if (to_sort[j] < to_sort[i]) {
                    if (debug && yeet)
                        cout << to_sort[i] << ", " << to_sort[j] << endl;
                    swap(to_sort[j], to_sort[i]);
                    if (debug)
                        printArray(to_sort, size);
                } else if (to_sort[j] > to_sort[i]) {
                    if (debug && yeet)
                        cout << "j is less than i" << endl;
                    continue;
                }
            }
        }
    } else if (highest)
    {
        maxIndex = 0;
        for (int i = 0; i < size; i++)
        {
            if (to_sort[i] > to_sort[maxIndex])
                maxIndex = i;
        }
        swap(to_sort[maxIndex], to_sort[size - 1]); // swap index 5 and 9
        if (debug && yeet)
            cout << to_sort[9] << ", " << to_sort[maxIndex] << endl;
        if (debug)
            printArray(to_sort, size);
        for (int i = size - 2; i >= 0; i--)
        { // i is the index
            if (debug && yeet)
                cout << i << endl;
            for (int j = i - 1; j >= 0; j--)
            { // j is the index - 1
                if (to_sort[j] > to_sort[i]) {
                    if (debug && yeet)
                        cout << to_sort[i] << ", " << to_sort[j] << endl;
                    swap(to_sort[j], to_sort[i]);
                    if (debug)
                        printArray(to_sort, size);
                } else if (to_sort[j] < to_sort[i]) {
                    if (debug && yeet)
                        cout << "j is greater than i" << endl;
                    continue;
                }
            }
        }
    }
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
    cout << "------------------------------------------------" << endl;
    timesCalled++;
}

void resetArray(int to_sort[], int copy_to_sort[], int size)
{
    for (int i = 0; i < size; i++)
        to_sort[i] = copy_to_sort[i];
}