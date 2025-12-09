#include "D_PizzaOrders.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

D_PizzaOrders::D_PizzaOrders()
{
    header = NULL;
}
D_PizzaOrders::~D_PizzaOrders()
{
    Pizza* current = header;
    while(current != NULL){
        Pizza* nextOrder = current->nextOrder;
        delete current;
        current = nextOrder;
    }
    header = NULL;
}
void D_PizzaOrders::D_AddNew(int customer_ID, string toppings, string size, bool debug)
{
    Pizza* current = header;
    Pizza* newOrder = new Pizza(customer_ID, toppings, size, debug);
    Pizza* prevOrder = nullptr;
    if (!header)
    {
        header = newOrder;
    } else
    {
        while (current -> nextOrder!= NULL)
        {
            prevOrder = current;
            current = current-> nextOrder;
        }
        current -> nextOrder = newOrder;
        newOrder -> nextOrder = NULL;
    }
}
bool D_PizzaOrders::D_isCompleted()
{

}
void D_PizzaOrders::D_removeOrder(int customer_ID)
{
    Pizza* current = header;
}



