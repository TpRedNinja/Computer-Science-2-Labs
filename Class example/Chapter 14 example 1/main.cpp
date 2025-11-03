#include <iostream>
#include <string>
#include "Car.h"
#include "Passenger.h"
using namespace std;

int main() {

    // create passengers
    Passenger Chris("Chris");
    Passenger Bob("Bob");
    Passenger Donna("Donna");
    Passenger Justin("Justin");
    Passenger Cindy("Cindy");

    cout << Chris << endl; // displayed chris

    Car Nissan; // make a nissian object

    // add a few passengers to the nissan
    Nissan.addPassenger(Chris);
    Nissan.addPassenger(Bob);
    Nissan.addPassenger(Donna);

    cout << "Who is in the car?: " << Nissan << endl;

    // copy of nissan
    //Car Nissan2(Nissan);
    Car Nissan2 = Nissan;

    cout << "Nissan 1 copy: " << Nissan2 << endl;

    // copy of itself
    Nissan = Nissan;

    return 0;
}