#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "Harris";
    int age = 19;
    double salary = 1000000.00;
    char CName[20];

    cout << sizeof(name) << endl;
    cout << sizeof(age) << endl;
    cout << sizeof(salary) << endl;
    cout << sizeof(CName) << endl;

    return 0;
}
