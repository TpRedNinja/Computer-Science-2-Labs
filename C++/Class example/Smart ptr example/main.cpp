#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    string name = "Harris";
    int age = 19;
    int nextAge = 20;

    unique_ptr<int> currentAge(new int(age));

    // display current age
    cout << "My current age is: " << *currentAge << endl;

    // modify the current age pointer
    currentAge.reset(new int(nextAge));

    cout << "My age next year is: " << *currentAge << endl;

    return 0;
}
