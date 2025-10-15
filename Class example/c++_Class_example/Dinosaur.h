//
// Created by jjdom on 10/15/2025.
//

#ifndef C___CLASS_EXAMPLE_DINOSAUR_H
#define C___CLASS_EXAMPLE_DINOSAUR_H

#include <string>
using namespace std;

class Dinosaur
{
public:
    Dinosaur(); // default constructor
    Dinosaur(string description);
    Dinosaur(string description, int weight, bool carnivore);

    void setDescription(string description);
    void setWeight(int weight);
    void setCarnivore(bool carnivore);

    string getDescription();
    int getWeight();
    bool getCarnivore();

    string toString(); // to String method

private:
    string m_description;
    int m_weight;
    bool m_carnivore;

};

#endif //C___CLASS_EXAMPLE_DINOSAUR_H