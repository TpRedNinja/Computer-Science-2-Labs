#include <iostream>
using namespace std;

int main()
{
    int age = 19;
    int *ageptr = &age;

    // display the pointers values
    cout << "Number store at the address: " << *ageptr << endl;
    cout <<  "Address store by this pointer: " << ageptr + 1 << endl;
    return 0;
}