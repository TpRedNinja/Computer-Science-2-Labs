#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cout << "This program will add a stack of 5 plates and you can view and remove plates." << endl;

    stack <string> dishes;
    dishes.push("Plate 1");
    dishes.push("Plate 2");
    dishes.push("Plate 3");
    dishes.push("Plate 4");
    dishes.push("Plate 5");

    // view the top plate
    cout << dishes.top()<< endl;

    stack <string> tempDishes; // create our temp stack here
    tempDishes = dishes;
    cout << "Display Dishes Stack" << endl;
    while (! tempDishes.empty()){
        cout << tempDishes.top() << endl;
        tempDishes.pop();
    }




    return 0;
}
