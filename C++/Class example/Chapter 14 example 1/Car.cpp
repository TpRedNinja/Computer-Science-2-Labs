#include <iostream>
#include <string>
#include "Car.h"
#include "Passenger.h"
using namespace std;

Car::Car():m_make("Honda"),m_model("Civic"),m_seats(5),m_seats_taken(0) { // constructor with no args
    m_passengerPtr = new Passenger[m_seats]; // pointer to the 5 seats
}
Car::Car(string make, string model, int seats) // Constructor with args
:m_make(make),m_model(model),m_seats(seats),m_seats_taken(0) {
    m_passengerPtr = new Passenger[m_seats]; // pointer to the # of seats
}
Car::Car(const Car& car) { // copy constructor
    m_make = car.m_make;
    m_model = car.m_model;
    m_seats = car.m_seats;
    m_seats_taken = car.m_seats_taken;
    m_passengerPtr = new Passenger[m_seats];
    // copy each passenger from the car
    for (int i = 0; i < m_seats_taken; i++) {
        m_passengerPtr[i] = car.m_passengerPtr[i];
    }
}
void Car::addPassenger(Passenger passenger) {
    if (m_seats_taken < m_seats)
        m_passengerPtr[m_seats_taken++] = passenger;
    else
        cerr << "Too many passengers" << endl;
}
Car::~Car() {
    delete [] m_passengerPtr;
}

ostream& operator << (ostream& sout, const Car car) {
    sout << car.m_make << " " << car.m_model << endl;
    for (int i = 0; i < car.m_seats_taken; i++) {
        sout << car.m_passengerPtr[i] << endl;
    }
    return sout;
}

Car& Car::operator=(const Car& car)
{
    if (this != &car){
        m_make = car.m_make;
        m_model = car.m_model;
        m_seats = car.m_seats;
        // check if car seats are not equal
        if (m_seats != car.m_seats) {
            delete [] m_passengerPtr; // create new array to store passengers
            m_passengerPtr = new Passenger[car.m_seats];
            m_seats = car.m_seats;
        }
        for (int i = 0; i < m_seats; ++i) {
            m_passengerPtr[i] = car.m_passengerPtr[i];
        }
    } else
    {
        cerr << "Cannot assign Car" << endl;
    }
    //"this" is a pointer to the current object
    return *this; // returns this keyword
}