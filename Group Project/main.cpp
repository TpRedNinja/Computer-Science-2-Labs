/* This program was created by Shelbie Kakalec and Harris for CMSC-202 on December 8th, 2025.
The purpose of this programs is to create a pizza restaurant with incomplete and complete orders.*/
#include <iostream>
#include <random>
#include "Pizza.h"
#include "D_PizzaOrders.h"
#include <ctime>
#include <string>
using namespace std;

// single linked list functions
void addPizza(PizzaOrders&, int, string, string, bool);
void deletePizza(PizzaOrders&, int);
void searchPizza(PizzaOrders&, int);
void completePizza(PizzaOrders&, int);
void displayIncompletePizza(PizzaOrders&);
// double linked list functions
void D_addPizza(D_PizzaOrders&, int, string, string, bool);
void D_deletePizza(D_PizzaOrders&, int);
void D_searchPizza(D_PizzaOrders&, int);
void D_completePizza(D_PizzaOrders&, int);
void D_displayIncompletePizza(D_PizzaOrders&);
// global variables
static int ordernum = 10000; // order id
bool doubleLink = false; // if the user chose a double link list

int main()
{
    PizzaOrders PzaOdrList;
    D_PizzaOrders D_PzaOdrList;
    int choice;
    int SD;
    int customer_ID;
    string toppings;
    string size;
    bool debug;
    cout << "Do you want to use a single link list or double link list(1 for single 2 for double): ";
    cin >> SD;
    if (SD == 2)
    {
        doubleLink = true;
    }
    if (doubleLink)
    {
        D_PzaOdrList.D_AddNew(ordernum,"test one","cheese", false);
        ordernum++;
        D_PzaOdrList.D_AddNew(ordernum,"test two","cheese",false);
        ordernum++;
        D_PzaOdrList.D_AddNew(ordernum,"test three","cheese", false);
        ordernum++;
    } else
    {
        PzaOdrList.AddNew(ordernum,"test one","cheese", false);
        ordernum++;
        PzaOdrList.AddNew(ordernum,"test two","cheese",false);
        ordernum++;
        PzaOdrList.AddNew(ordernum,"test three","cheese", false);
        ordernum++;
    }
    do{
        cout << "---------------------------------------------" << endl;
        cout << "Enter 1 to add an order." << endl;
        cout << "Enter 2 to delete an order." << endl;
        cout << "Enter 3 to search for an order." << endl;
        cout << "Enter 4 to complete an order." << endl;
        cout << "Enter 5 to display non-complete orders." << endl;
        cout << "Enter 6 to exit the program." << endl;
        cout << "---------------------------------------------" << endl;
        cin >> choice;
        if (!doubleLink)
        {
            if (choice == 1){
                addPizza(PzaOdrList, customer_ID, toppings, size, debug);
            }else if (choice == 2){
                deletePizza(PzaOdrList, customer_ID);
            }else if (choice == 3){
                searchPizza(PzaOdrList, customer_ID);
            }else if (choice == 4){
                completePizza(PzaOdrList, customer_ID);
            }else if (choice == 5){
                displayIncompletePizza(PzaOdrList);
            }else if (choice == 6){
                cout << "Bye bye!!" << endl;
                break;
            }else{
                cout << "Sorry!! that's an invalid number!!" << endl;
            }
        } else
        {
            if (choice == 1){
                D_addPizza(D_PzaOdrList, customer_ID, toppings, size, debug);
            }else if (choice == 2){
                D_deletePizza(D_PzaOdrList, customer_ID);
            }else if (choice == 3){
                D_searchPizza(D_PzaOdrList, customer_ID);
            }else if (choice == 4){
                D_completePizza(D_PzaOdrList, customer_ID);
            }else if (choice == 5){
                D_displayIncompletePizza(D_PzaOdrList);
            }else if (choice == 6){
                cout << "Bye bye!!" << endl;
                break;
            }else{
                cout << "Sorry!! that's an invalid number!!" << endl;
            }
        }

    } while(choice != 6);

    return 0;
}

void addPizza(PizzaOrders& PzaOdrList, int customer_ID, string toppings, string size, bool debug){
    cout << "Please put in the size of your pizza: ";
    cin.ignore();
    getline(cin, size);
    cout << "Please put in the toppings on your pizza: ";
    getline(cin, toppings);
    customer_ID = ordernum;
    debug = true;
    PzaOdrList.AddNew(customer_ID, toppings, size, debug);
    ordernum++;
}
void D_addPizza(D_PizzaOrders& D_PzaOdrList, int customer_ID, string toppings, string size, bool debug) {
    cout << "Please put in the size of your pizza: ";
    cin.ignore();
    getline(cin, size);
    cout << "Please put in the toppings on your pizza: ";
    getline(cin, toppings);
    customer_ID = ordernum;
    debug = true;
    D_PzaOdrList.D_AddNew(customer_ID, toppings, size, debug);
    ordernum++;
}
void deletePizza(PizzaOrders& PzaOdrList, int customer_ID){
    cout << "Please put in your Customer ID: ";
    cin >> customer_ID;
    PzaOdrList.removeOrder(customer_ID);
}
void D_deletePizza(D_PizzaOrders& D_PzaOdrList, int customer_ID) {
    cout << "Please put in your Customer ID: ";
    cin >> customer_ID;
    D_PzaOdrList.D_removeOrder(customer_ID);
}

void searchPizza(PizzaOrders& PzaOdrList, int customer_ID) {
    cout << "Please put in your Customer ID: ";
    cin >> customer_ID;
    PzaOdrList.searchforpizza(customer_ID); //done
}
void D_searchPizza(D_PizzaOrders& D_PzaOdrList, int customer_ID) {
    cout << "Please put in your Customer ID: ";
    cin >> customer_ID;
    D_PzaOdrList.D_searchforpizza(customer_ID);
}
void completePizza(PizzaOrders& PzaOdrList, int customer_ID) {
    cout << "Please put in your Customer ID: ";
    cin >> customer_ID;
    PzaOdrList.completeOrder(customer_ID);
}
void D_completePizza(D_PizzaOrders& D_PzaOdrList, int customer_ID) {
    cout << "Please put in your Customer ID: ";
    cin >> customer_ID;
    D_PzaOdrList.D_completeOrder(customer_ID);
}
void displayIncompletePizza(PizzaOrders& PzaOdrList){     //done
    PzaOdrList.displayIncomplete();
}
void D_displayIncompletePizza(D_PizzaOrders& D_PzaOdrList) {
    D_PzaOdrList.D_displayIncomplete();
}
