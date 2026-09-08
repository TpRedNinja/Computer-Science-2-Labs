#ifndef INHERITENCE_EXAMPLE_FILLEDDOUGHNUT_H
#define INHERITENCE_EXAMPLE_FILLEDDOUGHNUT_H
#include "Doughnut.h"
#include <iostream>
using namespace std;

class FilledDoughnut : public Doughnut {
    public:
        FilledDoughnut();
        FilledDoughnut(const string &fillingType);
        // override the dunk functions
        static void dunk();
        void dunk(const string &drink) const;
        void mess();

    private:
        string m_fillingType;
};


#endif //INHERITENCE_EXAMPLE_FILLEDDOUGHNUT_H