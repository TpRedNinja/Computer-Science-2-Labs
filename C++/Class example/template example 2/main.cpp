#include <iostream>
using namespace std;

template<typename T> void bubbleIt(T arr[], int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = size-1; i < j; j--)
        {
            if (arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]); // built in swap function
            }
        }
    }
}

template <typename T1> void display(T1 arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // create arrays to sort
    int i_array[5] = {3,2,5,1,4};
    double d_array[5] = {1.7, 4.2, 3.4, 2.8, 5.3};
    char c_array[5] = {'c', 'b', 'e', 'a', 'd'};

    int size = sizeof(i_array) / sizeof(i_array[0]);

    cout << "Integer Array (Before): " << endl;
    display(i_array, size);

    cout << "Double Array (Before): " << endl;
    display(d_array, size);

    cout << "Character Array (Before): " << endl;
    display(c_array, size);

    // sort all of our array using the template function
    bubbleIt(i_array, size);
    bubbleIt(d_array, size);
    bubbleIt(c_array, size);

    cout << "Integer Array (After): " << endl;
    display(i_array, size);

    cout << "Double Array (After): " << endl;
    display(d_array, size);

    cout << "Character Array (After): " << endl;
    display(c_array, size);


    return 0;
}