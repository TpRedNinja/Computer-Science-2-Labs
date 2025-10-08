#include <iostream>
using namespace std;

int main()
{
    int num;
    double *ptr;

    cout << "What size array do you want to create?: ";
    cin >> num;
    ptr = new double[num];

    // store the fibonacci numbers into this array
    for (int i = 0; i < num; i++)
    {
        if (i == 0 || i == 1)
            ptr[i] = 1;
        else
            ptr[i] = ptr[i - 1] + ptr[i - 2];
    }

    cout << "Displaying the fibonacci array: " << endl;
    for (int i = 0; i < num; i++)
    {
        cout << ptr[i] << " ";
    }

    delete [] ptr; // Deallocate the hemp memory
    return 0;
}