#include <iostream>
#include <string>
#include "Doughnut.h"
//#include "Doughnut.cpp"
using namespace std;

int main() {
    Doughnut doughnut1(Doughnut::Chocolate);
    Doughnut doughnut2(Doughnut::Chocolate);

    bool sameDoughnut = doughnut1 == doughnut2;
    cout << "These are the same doughnuts: " << sameDoughnut << endl;

    // display our doughnut
    cout << doughnut1 << endl;

    // dunk the doughnut
    doughnut1.dunk();

    // take 9 bites from the doughnut
    for (int i = 0; i < 9; i++)
        doughnut1.bite();

    cout << doughnut1 << endl;

    return 0;
}