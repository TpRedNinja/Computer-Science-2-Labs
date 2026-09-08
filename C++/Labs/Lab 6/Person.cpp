//
// Created by jjdom on 10/15/2025.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Person.h"

using namespace std;

Person::Person()
{
    setName("John Doe");
}

Person::Person(string name)
{
    setName(name);
}

Person::Person(string name, int age, double weight, double height) :
m_name(name), m_age(), m_weight(), m_height()
{
    // empty constructor
}

// setting functions
void Person::setName(string name)
{
    m_name = name;
}
void Person::setAge(int age)
{
    m_age = age;
}
void Person::setWeight(double weight)
{
    m_weight = weight;
}
void Person::setHeight(double height)
{
    m_height = height;
}

// getter functions
string Person::getName()
{
    return m_name;
}
int Person::getAge()
{
    return m_age;
}
double Person::getWeight()
{
    return m_weight;
}
double Person::getHeight()
{
    return m_height;
}

string Person::toString()
{
    string output;
    output = "Name: " + m_name + "\nAge: " + to_string(m_age) +
        "\nWeight: " + to_string(m_weight) + " Pounds\nHeight: " + to_string(m_height) + " inches.";

    return output;
}

void Person::getHealth(double weight, double height, string name)
{
    double BMI;
    string health;
    BMI = (m_weight/pow(m_height, 2)) * 703;
    //cout << setprecision(2); // wanted to round to 1 decimal place. But it seems to freak out when I do that

    if (BMI < 18.5)
    {
        cout << m_name << " your BMI is: " << BMI << " . " << m_name << " you are underweight.";
    } else if (BMI > 18.5 && BMI < 25)
    {
        cout << m_name << " your BMI is: " << BMI << " . " << m_name << " you are at a healthy weight.";
    } else if (BMI > 25 && BMI < 30)
    {
        cout << m_name << " your BMI is: " << BMI << " . " << m_name << " you are overweight.";
    } else
    {
        cout << m_name << " your BMI is: " << BMI << " . " << m_name << " you are obese.";
    }

}

