//
// Created by jjdom on 10/15/2025.
//

#include <iostream>
#include <string>
#include "Dinosaur.h"

using namespace std;

// default constructor
Dinosaur::Dinosaur()
{
    setDescription("A Generic Dinosaur");
}
Dinosaur::Dinosaur(string description)
{
    setDescription(description);
}

Dinosaur::Dinosaur(string description, int weight, bool carnivore) :
m_description(description), m_weight(weight), m_carnivore(carnivore)
{
    // empty constructor body
}

// setter functions
void Dinosaur::setDescription(string description)
{
    m_description = description;
}
void Dinosaur::setWeight(int weight)
{
    m_weight = weight;
}
void Dinosaur::setCarnivore(bool carnivore)
{
    m_carnivore = carnivore;
}

// getter functions
string Dinosaur::getDescription()
{
    return m_description;
}
int Dinosaur::getWeight()
{
    return m_weight;
}
bool Dinosaur::getCarnivore()
{
    return m_carnivore;
}

string Dinosaur::toString()
{
    string output;
    output = "Dinosaur Description: " + m_description +
        "\nWeight is: " + to_string(m_weight) + " pounds\n";

    if (m_carnivore)
        output += "\nRun.";

    return output;
}




