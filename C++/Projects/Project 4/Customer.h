#ifndef PROJECT_4_CUSTOMER_H
#define PROJECT_4_CUSTOMER_H
#include "Book.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

class Customer
{
    public:
        // constructors
        Customer(); // no args constructor
        Customer(string name, string address); // args constructor
        Customer(const Customer& customer); // copy constructor
        ~Customer(); // de-constructor

        // functions
        void View();
        void Checkout(Book &bookToCheckout);
        void Checkin();

        // getter functions
        int get_id();
        string get_name();
        string get_address();
        string get_date_check_out();
        Book* get_book();

        // setter functions
        void set_id(int id);
        void set_name(string name);
        void set_address(string address);
        void set_date_check_out(string date_check_out);
        void set_book(Book* book);


    private:
        // member variables
        int m_id;
        string m_name;
        string m_address;
        string m_date_check_out;
        Book* m_book;

        // function to get the users system date
        string getSystemDate();
};


#endif //PROJECT_4_CUSTOMER_H