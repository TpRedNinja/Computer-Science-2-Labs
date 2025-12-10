#include <random>
#include <iostream>
#include <ctime>
#include "Pizza.h"
#include <string>

using namespace std;


PizzaOrders::PizzaOrders(){
    header = NULL;
}

PizzaOrders::~PizzaOrders(){
    Pizza* current = header;
    while(current != NULL){
        Pizza* nextOrder = current->nextOrder;
        delete current;
        current = nextOrder;
    }
    header = NULL;
    //destructor function
}

void PizzaOrders::AddNew(int customer_ID, string toppings, string size, bool debug){
    Pizza* current = header;
    Pizza* newOrder = new Pizza(customer_ID, toppings, size, false);
    if(debug == true){
        cout << "Your order ID is: " << customer_ID << endl;
    }
    if (!header){
        header = newOrder;
    }else{
        
        while (current->nextOrder != NULL){
            current = current -> nextOrder;
        }
        
        current -> nextOrder = newOrder;
        newOrder -> nextOrder = NULL;
        return;
    }
}

void PizzaOrders::removeOrder(int customer_ID){
    Pizza* current = header;
    if(header == NULL){
        cerr << "ERROR: LIST IS EMPTY" << endl;
        return;
    }
    if (header->cust_ID == customer_ID){
        if(header->nextOrder == NULL){
            header = NULL;
            cout << "Your order has been deleted!" << endl;
            return;
        }
        header = header -> nextOrder;
        delete current;
        cout << "Your order has been deleted!" << endl;
        return;
    }
    
    while (current != NULL){
        if (current->nextOrder->cust_ID == customer_ID){
            if(current -> nextOrder -> nextOrder == NULL){
                current -> nextOrder = NULL;
                return;
            }
            current->nextOrder = current->nextOrder->nextOrder;
            delete current->nextOrder;
            return;
        }
        
        current = current -> nextOrder;
    }
    cout << "Im sorry, your order was not found!" << endl;
}
void PizzaOrders::searchforpizza(int customer_ID){
    Pizza* current = header;
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

void PizzaOrders::completeOrder(int customer_ID){
    Pizza* current = header;
    if(header == NULL){
        cerr << "ERROR: LIST IS EMPTY" << endl;
        return;
    }
    while(current != NULL){
        if(current->cust_ID == customer_ID){
            if (current-> complete == false)
            {
                current->complete = true;
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

void PizzaOrders::displayIncomplete(){
    Pizza* current = header;
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