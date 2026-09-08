#include <iostream>
using namespace std;


template <typename T1, typename T2> T1 maxValue (T1 x, T2 y)
{
    return (x > y) ? x : y;
}
int main()
{
    // call max value function
    cout << maxValue(3, 7) << endl; // pass ints
    cout << maxValue(19.8, 72.34) << endl; // pass doubles
    cout << maxValue('h', 'z') << endl; // pass chars
    cout << maxValue(5, 5.1) << endl; // does not work as expected
    return 0;
}
