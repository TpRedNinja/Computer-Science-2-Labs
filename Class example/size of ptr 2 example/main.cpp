#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "Harris";
    int age = 19;
    int nextAge = 20;

    int* currentAge = &age;

    // display current age
    cout << "My current age is: " << *currentAge << endl;

    // modify the current age pointer
    currentAge = &nextAge;

    cout << "My age next year is: " << *currentAge << endl;

    // dynamic memory allocation
    int* agePtr = new int(18);

    currentAge = agePtr; // modify the pointer again
    cout << "My age last year was: " << *currentAge << endl;
    delete currentAge; // deallocate memory

    currentAge = new int(17);
    cout << "My age 2 years ago was: " << *currentAge << endl;
    delete currentAge; // deallocate memory

    return 0;
}
