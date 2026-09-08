#ifndef CHAPTER_14_EXAMPLE_1_CAR_H
#define CHAPTER_14_EXAMPLE_1_CAR_H
#include "Passenger.h"
#include <string>

class Car
{
    public:
        Car(); // no-args constructor
        Car(string male, string model, int seats);
        Car(const Car &car); // copy constructor
        void addPassenger(Passenger passenger);
        friend ostream& operator<<(ostream& sout, const Car car);
        Car& operator=(const Car& car);
        ~Car(); // create destructor
    private:
        string m_make;
        string m_model;
        int m_seats;
        int m_seats_taken;
        Passenger *m_passengerPtr;
};


#endif //CHAPTER_14_EXAMPLE_1_CAR_H