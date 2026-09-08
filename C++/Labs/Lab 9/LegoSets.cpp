#include "LegoSets.h"

LegoSets::LegoSets(){
}

LegoSets::LegoSets(string title, double price, int num_of_pieces){
    l_title = title;
    l_price = price;
    l_amount = num_of_pieces;
}

void LegoSets::setTitle(string title){
    l_title = title;
}

void LegoSets::setPrice(double price){
    l_price = price;
}

void LegoSets::setAmount(int amount){
    l_amount = amount;
}

string LegoSets::getTitle(){
    return l_title;
}

double LegoSets::getPrice(){
    return l_price;
}

int LegoSets::getAmount(){
    return l_amount;
}
