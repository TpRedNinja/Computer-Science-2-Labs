//
// Created by jjdom on 10/15/2025.
//

#ifndef LAB_6_PERSON_H
#define LAB_6_PERSON_H

#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person(string name);
    Person(string name, int age, double weight, double height);

    void setName(string name);
    void setAge(int age);
    void setWeight(double weight);
    void setHeight(double height);

    string getName();
    int getAge();
    double getWeight();
    double getHeight();
    void getHealth(double weight, double height, string name);

    string toString();

private:
    string m_name;
    int m_age;
    double m_weight;
    double m_height;
};


#endif //LAB_6_PERSON_H