#include <algorithm>
#include <iostream>
using namespace std;

int sortArray(int startPoint, int to_sort[], int size);

int main()
{
    int to_sort[] = { 4 ,8, 1, 5, 2, 10, 9, 6, 7, 3 }; // array we need to sort
    int size = sizeof(to_sort) / sizeof(to_sort[0]); // the size of the array
    int startPoint; // user input for the start point
    int to_sort_sorted; // sorted array

    cout << "This program we will be sorting an array using the insertion algorithm" << endl;
    cout << "We are gonna sort this array: ";
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
            cout <<"to_sort = { " << to_sort[i] << " ";
        else if ( i == size - 1)
            cout << to_sort[i] << " }" << endl;
        else
            cout << to_sort[i] << ", ";
    }
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
    to_sort_sorted = sortArray(startPoint, to_sort, size);

    return 0;
}

int sortArray(int startPoint, int to_sort[], int size)
{
    int to_sort_sorted[] = {};
    int i;
    if (startPoint == size - 1)
        i = startPoint-1;
    else
        i = startPoint+1;

    if (to_sort[startPoint] > to_sort[i])
    {

    }

    return to_sort_sorted[size];
}