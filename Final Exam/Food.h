#ifndef FINAL_EXAM_FOOD_H
#define FINAL_EXAM_FOOD_H
//This is the Food Header file it has a total of 1 error
#include <string> // Error 1: Didnt include string
using namespace std;

class Food{
private:
    double profit = .6;
    string name; // Error 1: Didnt include string
    double wholesale;
    int num_of_calories;
    double price;

public:
    Food();
    Food(string n,double p,int c); // Error 1: Didnt include string
    void display();
};
#endif //FINAL_EXAM_FOOD_H