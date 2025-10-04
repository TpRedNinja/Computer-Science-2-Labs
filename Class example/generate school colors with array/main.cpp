#include <iostream>
using namespace std;


void display_school_colors(string school_colors[], int length)
{
    cout << "Your school colors are:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << school_colors[i] << endl;
    }
}

void pick_colors(string *colorKey, string schoolColors[], int KeyLength, int length)
{
    srand(time(0));
    do
    {
        cout << "Generating School Colors" << endl;
        for (int i = 0; i < length; i++)
        {
            schoolColors[i] = colorKey[rand() % KeyLength];
        }
    } while (schoolColors[0] == schoolColors[1]);

}

int main()
{
    string colorKey[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple", "White", "Black"};
    string schoolColors[2];
    int keyLength = sizeof(colorKey) / sizeof(colorKey[0]);

    string *colorPtr = colorKey; // store our array as a pointer

    pick_colors(colorPtr, schoolColors, keyLength, 2);
    display_school_colors(schoolColors, 2);

    return 0;
}