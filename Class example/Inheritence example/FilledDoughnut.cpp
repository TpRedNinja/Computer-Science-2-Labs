#include "FilledDoughnut.h"
#include "Doughnut.h"
#include <iostream>
using namespace std;

FilledDoughnut::FilledDoughnut() : Doughnut(Doughnut::Jelly) {
    m_fillingType = "Chocolate";
}

FilledDoughnut::FilledDoughnut(const string &fillType) : Doughnut(Doughnut::Jelly) {
    m_fillingType = fillType;
}

void FilledDoughnut::dunk() {
    cerr << "Dont Dunk filled doughnuts you weirdo" << endl;
}
void FilledDoughnut::dunk(const string &drink) const
{
    Doughnut::dunk(drink); // call the function in the base class
}

void FilledDoughnut::mess() {
    cout << "The Doughnut is spilling!" << endl;
    if (m_bitesLeft > 0) {
        m_bitesLeft --;
    }
    else {
        cout << "The Doughnut is empty" << endl;
    }
}

