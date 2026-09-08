#include "Passenger.h"
#include <string>
using namespace std;

Passenger::Passenger(): m_name("No Name"){}
Passenger::Passenger(string name): m_name(name){}
ostream& operator << (ostream& sout, const Passenger passenger)
{
    sout << passenger.m_name;
    return sout;
}
