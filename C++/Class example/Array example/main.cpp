#include <iostream>
using namespace std;

int main()
{
    int myArray[] = {10, 20, 30, 40, 50}; //create an array
    int *intPrt; // create pointer

    void *voidPrt; // void pointer

    //This is legal
    intPrt = myArray;

    // we could also do this
    // intPrt = &myArray[0];

    // we can not do this though
    // myArray = intPrt;

    // lets dereference our pointer
    cout << "Value: " << *intPrt << endl;
    cout << "Address: " << intPrt << endl;

    cout << *intPrt++ << endl; // add one to it
    // use pointer arithmetic
    cout << *(intPrt + 2) << endl;
    cout << "Value: " << *intPrt << endl;
    cout << "Address: " << intPrt << endl;

    voidPrt = myArray; // use the void pointer

    int array_size = sizeof(myArray) / sizeof(myArray[0]);
    //dereference the void ptr
    for (int i = 0; i < array_size; i++)
    {
        cout << "Added " << i << " " << *((int *) voidPrt + i) << endl;
    }



    return 0;
}