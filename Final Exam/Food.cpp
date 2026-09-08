// this is the Food class file it has a total of 2 errors in it
#include "Food.h"
#include <iostream>
using namespace std;

Food::Food(string n, double p, int c){ //Error 2: forgot to include datatypes string, int & double
    name = n;
    wholesale = p;
    num_of_calories = c;
    price = p * profit + p;

}
Food::Food(){
    name = "";
    wholesale = 0.00;
    num_of_calories = 0;
    price = 0 * profit + 0;
}
void Food:: display(){
    std::cout <<"\nItem: "<<name<<"\nPrice: $"<<price<<"\nCalories: "<< num_of_calories << "\n"; //Error 3: forgot semicolon

}