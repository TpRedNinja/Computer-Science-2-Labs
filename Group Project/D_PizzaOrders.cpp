#include "D_PizzaOrders.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

D_PizzaOrders::D_PizzaOrders() {
    header = NULL;
}
D_PizzaOrders::~D_PizzaOrders() {
    D_Pizza* current = header;
    while(current != NULL){
        D_Pizza* nextOrder = current->nextOrder;
        delete current;
        current = nextOrder;
    }
    header = NULL;
}
void D_PizzaOrders::D_AddNew(int customer_ID, string toppings, string size, bool debug) {
    D_Pizza* current = header;
    D_Pizza* newOrder = new D_Pizza(customer_ID, toppings, size, false);
    D_Pizza* d_prevOrder = nullptr;
    if(debug == true) {
        cout << "Your order ID is: " << customer_ID << endl;
    }
    if (!header) {
        header = newOrder;
    } else {
        while (current -> nextOrder!= NULL) {
            current = current-> nextOrder;
        }
        current -> nextOrder = newOrder;
        newOrder -> prevOrder = current;
        newOrder -> nextOrder = NULL;
    }
}
void D_PizzaOrders::D_removeOrder(int customer_ID) {
    D_Pizza* current = header;
    // case 0: empty list
    if(header == NULL){
        cerr << "ERROR: LIST IS EMPTY" << endl;
        return;
    }
    // case 1 removing the head of the list
    if (current->cust_ID == customer_ID) {
        if (current->nextOrder == NULL) { // when the head is the only one
            header = NULL;
            delete current;
            cout << "Your order has been deleted!" << endl;
            return;
        }
        // removing the head but its not the only one
        header = current->nextOrder; // move the header forward
        current->prevOrder = NULL; // set the prev order to null to remove the order from the list
        delete current;
        cout << "Your order has been deleted!" << endl;
        return;
    }
    // case 2: removing from the middle or end of the list
    while (current != NULL) {
        if (current->cust_ID == customer_ID) {
            D_Pizza* prevOrder = current->prevOrder;
            D_Pizza* nextOrder = current->nextOrder;

            // removing the last order
            if (nextOrder == NULL) {
                prevOrder->nextOrder = NULL;
                delete current;
                cout << "Your order has been deleted!" << endl;
                return;
            }
            // removing middle order
            prevOrder->nextOrder = nextOrder;
            nextOrder->prevOrder = prevOrder;
            delete current;
            cout << "Your order has been deleted!" << endl;
            return;
        }
        current = current->nextOrder;
    }
    // case 3: not found
    cout << "I'm sorry, your order was not found!" << endl;
}
void D_PizzaOrders::D_searchforpizza(int customer_ID) {
    D_Pizza* current = header;
    if(header == NULL){
        cerr << "ERROR: LIST IS EMPTY" << endl;
        return;
    }
    while(current != NULL){
        if(current->cust_ID == customer_ID){
            cout << "Toppings: " << current->topping << endl;
            cout << "Size: " << current->sizes << endl;
            cout << "Complete?: ";
            if (current->complete == true){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            cout << "Found in " << endl;
            return;
        }
        current = current -> nextOrder;
    }
    cout << "Im sorry, your order was not found!" << endl;
}
void D_PizzaOrders::D_completeOrder(int customer_ID) {
    D_Pizza* current = header;
    if(header == NULL){
        cerr << "ERROR: LIST IS EMPTY" << endl;
        return;
    }
    while(current != NULL){
        if(current->cust_ID == customer_ID){
            if (current-> complete == false)
            {
                current -> complete = true;
                cout <<"Your order is ready to be picked up!" << endl;
                return;
            } else
            {
                cerr << "ERROR: Pizza is already complete!" << endl;
            }
        }
        current = current -> nextOrder;
    }
    cout << "Im sorry, your order was not found!" << endl;
}
void D_PizzaOrders::D_displayIncomplete() {
    D_Pizza* current = header;
    if(header == NULL){
        cerr << "ERROR: LIST IS EMPTY" << endl;
        return;
    }
    while(current != NULL){
        if(current->complete == false){
            cout << "Order ID: " << current->cust_ID << endl;
            cout << "Toppings: " << current->topping << endl;
            cout << "Size: " << current->sizes << endl;
            cout << "--------------------------------------" << endl;
        }
        current = current -> nextOrder;
    }
}
