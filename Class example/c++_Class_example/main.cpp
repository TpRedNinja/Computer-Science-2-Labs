#include <iostream>
#include "Dinosaur.h"
using namespace std;

int main()
{
    Dinosaur trex;
    cout << trex.toString() << endl;

    trex.setDescription("Tyrannosaurus Rex");
    trex.setWeight(10000);
    trex.setCarnivore(true);

    cout << trex.toString() << endl;


    return 0;
}
