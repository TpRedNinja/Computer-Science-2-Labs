#include "Book.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// default constructor with no args
Book::Book() {
    m_id = 10000 + rand() % 90000;
    m_title = "Undefined";
    m_author = "Undefined";
    m_num_of_pages = 0;
    m_cost = 0.00;
    m_IsCheckOut = false;
}
// constructor with args
Book::Book(string title, string author, int num_of_pages, double cost) {
    m_id = 10000 + rand() % 90000;
    m_title = title;
    m_author = author;
    m_num_of_pages = num_of_pages;
    m_cost = cost;
    m_IsCheckOut = false;
}
// copy constructor
Book::Book(const Book &book) {
    m_id = 10000 + rand() % 90000;
    m_title = book.m_title;
    m_author = book.m_author;
    m_num_of_pages = book.m_num_of_pages;
    m_cost = book.m_cost;
    m_IsCheckOut = book.m_IsCheckOut;
}
// de-constructure
Book::~Book() {
    cout << "Book Destructor called" << endl;
}

// Functions
void Book::View() { // display details about the book
    string yesorno;
    if (m_IsCheckOut)
        yesorno = "Yes";
    else
        yesorno = "No";
    cout << "Book id: " << m_id << "\nBook Title: " << m_title << "\nBook Author: " << m_author <<
        "\nBook number of pages: " << m_num_of_pages << " pages\nBook cost: $" << m_cost <<
            "\nIs Book Checkout: " << yesorno << endl;
}

//Checkout function
void Book::Checkout() {
    if (m_IsCheckOut)
        cerr << "Error: Book is already checkout. Please choose a different book" << endl;
    else {
        m_IsCheckOut = true;
        cout << "Book " << m_title << " is now checkout" << endl;
    }


}
// checkin function
void Book::Checkin() {
    if (!m_IsCheckOut)
        cerr << "Error: Book is already checkin. Please choose a different book" << endl;
    else{
        m_IsCheckOut = false;
        cout << "Book " << m_title << " is now checkin" << endl;
    }
}

// getter functions
int Book::get_id() {
    return m_id;
}
string Book::get_title() {
    return m_title;
}
string Book::get_author() {
    return m_author;
}
int Book::get_num_of_pages() {
    return m_num_of_pages;
}
double Book::get_cost() {
    return m_cost;
}
bool Book::get_ischeckout() {
    return m_IsCheckOut;
}

// setter functions
void Book::set_id(int id) {
    m_id = id;
}
void Book::set_title(string title) {
    m_title = title;
}
void Book::set_author(string author){
    m_author = author;
}
void Book::set_num_of_pages(int num_of_pages) {
    m_num_of_pages = num_of_pages;
}
void Book::set_cost(double cost) {
    m_cost = cost;
}
void Book::set_ischeckout(bool IsCheckOut) {
    m_IsCheckOut = IsCheckOut;
}