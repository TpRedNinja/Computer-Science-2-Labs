#include <iostream>
using namespace std;

template <typename T> void displayAll(T x, T y, T z)
{
    cout << x << " " << y << " " << z << endl;
}
template <typename T> T getHighest(T x, T y, T z)
{
    if (x > y && x > z)
        return x; // if x is greater than y and z return x
    else if (y > z && y > x)
        return y; // if y is greater than x and z return y
    else if (z > x && z > y)
        return z; // if z is greater than y and x return z
}
template <typename T> T getLowest(T x, T y, T z)
{
    if (x < y && x < z)
        return x; // if x is greater than y and z return x
    else if (y < z && y < x)
        return y; // if y is greater than x and z return y
    else if (z < x && z < y)
        return z; // if z is greater than y and x return z
}

int main()
{
    displayAll(20, 10, 1);
    displayAll("Batman", "Robin", "Nightwing");
    displayAll(20.9991, 10.0, 1.1);
    cout << "Get highest strings: " << getHighest("Batman", "Robin", "Nightwing") << endl;
    cout << "Get highest ints: " << getHighest(1,3,2) << endl;
    cout << "Get highest doubles: " << getHighest(1.8, 1.89256789, 1.799999999999999) << endl;
    cout << "Get Lowest strings: " << getLowest("Batman", "Robin", "Nightwing") << endl;
    cout << "Get Lowest ints: " << getLowest(1,3,2) << endl;
    cout << "Get Lowest doubles: " << getLowest(1.8, 1.89256789, 1.791) << endl;
    return 0;
}