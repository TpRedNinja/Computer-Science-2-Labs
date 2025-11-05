#ifndef INHERITENCE_EXAMPLE_DOUGHNUT_H
#define INHERITENCE_EXAMPLE_DOUGHNUT_H
#include <iostream>
#include <string>
using namespace std;

class Doughnut
{
    public:
        typedef enum {Plain, PowderedSugar, Glazed, Chocolate,Jelly, BostonCream} dType;
        Doughnut(); // no-args constructor
        Doughnut(dType doughnut); // argument with enum
        dType getDoughnut() const;

        void dunk() const;
        void dunk(string drink) const;
        void bite();

        // overload << operator
        friend ostream& operator<<(ostream& os, const Doughnut& d);
    private:
        dType m_doughnutType;
        int m_bitesLeft;
};
// this goes outside the class completely
// overload == operator
bool operator==(const Doughnut& d1, const Doughnut& d2);

#endif //INHERITENCE_EXAMPLE_DOUGHNUT_H