#include "Customer.h"
#include "Book.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;
// default constructor no args
Customer::Customer() : m_book(nullptr) {
    m_id = 10000 + rand() % 90000;
    string defaultNames [] = {"John Doe", "Jane Doe"}; // default names
    m_name = defaultNames[rand() % 2]; // randomly pick between the 2 names
    m_address = "Null Avenue";
    m_date_check_out = "00/00/0000";
}
// constructor with args
Customer::Customer(string name, string address) : m_book(nullptr) {
    m_id = 10000 + rand() % 90000;
    m_name = name;
    m_address = address;
    m_date_check_out = "00/00/0000";
}
// copy constructor
Customer::Customer(const Customer &customer) {
    m_id = 10000 + rand() % 90000;
    m_name = customer.m_name;
    m_address = customer.m_address;
    m_date_check_out = customer.m_date_check_out;
    m_book = customer.m_book;
}
// de-constructor
Customer::~Customer() {
    cout << "Customer Deconstructor called" << endl;
}

// functions
void Customer::View() {
    cout << "Customer id: " << m_id << "\nCustomer name: " << m_name << "\nCustomer address: " <<
        m_address << "\nCustomer book checkout on: " << m_date_check_out <<
            "\nCustomer current book: " << endl;
    if (m_book)
        m_book->View();

}
// get the users system date
string Customer::getSystemDate() {
    time_t now = time(0);          // get current system time
    tm* ltm = localtime(&now);     // convert to local time

    int year = 1900 + ltm->tm_year; // tm_year is years since 1900
    int month = 1 + ltm->tm_mon;    // tm_mon is 0-11
    int day = ltm->tm_mday;

    stringstream date;
    date << month << "/" << day << "/" << year; // format MM/DD/YYYY
    return date.str();
}

void Customer::Checkout(Book &bookToCheckout) {
    if (bookToCheckout.get_ischeckout()) {
        cerr << "Error: Book is already checked out." << endl;
        return;
    }

    bookToCheckout.Checkout(); // mark the book as checked out
    m_book = &bookToCheckout; // assign the book to the customer
    m_date_check_out = getSystemDate(); // set the date it was check out

    cout << "Customer " << m_name << " checkout " << m_book->get_title() <<
        " it was checkout on " << m_date_check_out << endl;
}

void Customer::Checkin() {
    if (!m_book || (!m_book->get_ischeckout() && (m_date_check_out == "00/00/0000" || m_date_check_out == "")))  {
        cerr << "Error: Customer has no book checked out." << endl;
        return;
    }
    m_book->Checkin();
    m_book = nullptr;
    m_date_check_out = "";

    cout << "Customer " << m_name << " has checked in their book." << endl;

}

// getter functions
int Customer::get_id() {
    return m_id;
}
string Customer::get_name() {
    return m_name;
}
string Customer::get_address() {
    return m_address;
}
string Customer::get_date_check_out() {
    return m_date_check_out;
}
Book* Customer::get_book() {
    return m_book;
}

// setter functions
void Customer::set_id(int id) {
    m_id = id;
}
void Customer::set_name(string name) {
    m_name = name;
}
void Customer::set_address(string address) {
    m_address = address;
}
void Customer::set_date_check_out(string date_check_out) {
    m_date_check_out = date_check_out;
}
void Customer::set_book(Book* book) {
    m_book = book;
}
