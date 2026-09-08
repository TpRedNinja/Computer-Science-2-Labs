#include <iostream>
#include "Food.h"

#include "Food.h"
using namespace std;

int main()
{
    cout << "This Program creates food items using Food Class" << endl;

    // create our instances
    Food F1 = Food();
    Food F2 = Food("Hotdog", 1.99);
    Food F3 = Food("Cheeseburger", 2.95, 700);

    F1.display();
    F2.display();
    F3.display();
    return 0;
}