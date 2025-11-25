#include <iostream>
#include <string>
#include <vector>
#include "LegoSets.h"
using namespace std;

//COMPLETE THIS FUNCTION
void fillVector(vector<LegoSets> &legoList){
    int amount;
    string name;
    double price;
    int quantity;

     // ask for amount of lego sets items
    cout << "How many Lego Sets do you have?: ";
    cin >> amount;
    if (cin.peek() == '\n')
        cin.ignore();

    for (int i = 0; i < amount; i++){
        // ask for name, price, quantity of each item and
        // add completed lego set item to vector
        }
}


//COMPLETE THIS FUNCTION

void printVector(vector<LegoSets> &legoList){
    // print each item's name, price, and quantity with correct
  // precision for price
  // USE ITERATOR


}

void checkStatus(vector<LegoSets> &legoList){

    //DEFINE ENUM HERE BASED ON NAMES BELOW
    enum {nonMem,bronze,silver};

    int listSize = legoList.size();

    switch (listSize) {
        case nonMem: cout << "You did not purchase enough items to become a member." << endl;
            break;
        case bronze: cout << "You purchased enough items to become a bronze member." << endl;
            break;
        case silver: cout << "You purchased enough items to become a silver member." << endl;
            break;
        default: cout << "You purchased enough items to become a gold member!" << endl;
    }
}

int main(){
    vector<LegoSets> legoList; //Creates a new vector of Groceries

    fillVector(legoList); //Populates the vector of Lego Sets

    printVector(legoList);

    cout << endl;

    checkStatus(legoList); //calls function defined above (must define enum)

    return 0;
}


