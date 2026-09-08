#include <iostream>
using namespace std;

const int RESPONSE_LENGTH = 80;

// prototype
bool isYes(char response[], int responseLength);

int main()
{
    char response[RESPONSE_LENGTH];

    cout << "Do you like C++?: ";
    cin >> response;

    if (isYes(response, RESPONSE_LENGTH))
        cout << "Good thing you are taking CMSC-202!" << endl;
    else
        cout << "You should have taken CIS-232 then." << endl;
    return 0;
}

bool isYes(char response[], int responseLength)
{
    int i = 0;
    while (response[i] == ' ')
    {
        ++i;
    }

    // switch statement
    switch (response [i])
    {
        case 'y':
            return true;
        case 'Y':
            return true;
        default:
            return false;
    }
}