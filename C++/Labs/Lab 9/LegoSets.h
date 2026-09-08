//File: LegoSets.h
#include <iostream>
#include <string>
using namespace std;

class LegoSets
{
public:
    //Default Constructor for Classes
    LegoSets();
    //Overloaded Constructor for Classes
    LegoSets(string title, double price, int num_of_pieces );

    //void function that sets the name of the lego set
    void setTitle(string item);

    //void function that sets the price of the legoset
    void setPrice(double price);

    //void function that sets the number of pieces the legoset has
    void setAmount(int amount);
    //Returns the title of lego set as a string
    string getTitle();

    //Returns the price of lego set as a double
    double getPrice();

    //Returns the number of peices in the set as an int
    int getAmount();

private:
    string l_title; //name of the set
    double l_price; //price of the set
    int l_amount; //amount of pieces in the set
};


