#include <iostream>
#include <string>
using namespace std;

#ifndef CHAPTER_14_EXAMPLE_1_PASSENGER_H
#define CHAPTER_14_EXAMPLE_1_PASSENGER_H


class Passenger
{
    public:
        Passenger(); // constructor
        Passenger(string name); // get name and constructs passenger
        friend ostream& operator << (ostream& sout, const Passenger passenger);

    private:
        string m_name;
};


#endif //CHAPTER_14_EXAMPLE_1_PASSENGER_H