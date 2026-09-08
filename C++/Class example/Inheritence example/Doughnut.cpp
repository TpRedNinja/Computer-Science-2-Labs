#include "Doughnut.h"
#include <iostream>
#include <string>
using namespace std;

// finish up the no args constructor for doughnut
Doughnut::Doughnut() {
    m_doughnutType = Chocolate;
    m_bitesLeft = 5;
}
// finish up the enum constructor for doughnut
Doughnut::Doughnut(dType doughnut) {
    m_doughnutType = doughnut;
    m_bitesLeft = 5;
}
// finish the doughnut type return
Doughnut::dType Doughnut::getDoughnut() const {
    return m_doughnutType;
}
void Doughnut::dunk() const {
    dunk("milk");
}
void Doughnut::dunk(string drink) const {
    if (m_bitesLeft > 0)
        cout << "Dunking the doughnut in " << drink << "." << endl;
    else
        cout << "The doughnut is all gone!" << endl;
}
void Doughnut::bite() {
    if (m_bitesLeft > 0) {
        m_bitesLeft--;
        cout << "Yummy!" << endl;
    }
    if (m_bitesLeft == 0)
        cout << "The doughnut is gone!" << endl;
}
ostream& operator<<(ostream& os, const Doughnut& d) {
    switch (d.m_doughnutType) {
        case Doughnut::Plain:
            os << "Plain" << endl;
            break;
        case Doughnut::PowderedSugar:
            os << "PowderedSugar" << endl;
            break;
        case Doughnut::Glazed:
            os << "Glazed" << endl;
            break;
        case Doughnut::Jelly:
            os << "Jelly" << endl;
            break;
        case Doughnut::Chocolate:
            os << "Chocolate" << endl;
            break;
        case Doughnut::BostonCream:
            os << "BostonCream" << endl;
            break;
        default:
            os << "Unknown doughnut" << endl;
            break;
    }
    os << " has " << d.m_bitesLeft << " bites left." << endl;
    return os;
}

bool operator==(const Doughnut& d1, const Doughnut& d2) {
    return d1.getDoughnut() == d2.getDoughnut();
}

