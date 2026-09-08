#include <iostream>
#include <assert.h>
using namespace std;

// two prototypes
int sum2(int *data, int i, int j);
int find(int *data, int len, int x);
const int LENGTH = 5;

int main() {

    // create our array
    int arr[LENGTH] = {1, 2, 3, 4, 5};
    int index;

    cout << "1, 3 Added " << sum2(arr, 1, 3) << endl;
    //cout << "-2, 1 Added " << sum2(arr, -2, 1) << endl;

    if ( (index = find(arr, LENGTH, 2)) < 0)
        cerr << "Integer not found in array." << endl;
    else
        cout << "Found 2 at: " << index << endl;

    if ( (index = find(arr, LENGTH, -4)) < 0)
        cerr << "Integer not found in array." << endl;
    else
        cout << "Found -4 at: " << index << endl;

    return 0;
}

int sum2(int *data, int i, int j) {
    assert(i >= 0 && i < LENGTH && j >= 0 && j < LENGTH);
    int total = 0;
    for (int k = i; k < j; k++)
        total += data[k];
    return total;
}

int find(int *data, int len, int x) {
    for (int i = 0; i < len; i++)
        if (data[i] == x)
            return i; // return the index location
    return -1;
}