#ifndef PROJECT_4_BOOK_H
#define PROJECT_4_BOOK_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Book
{
    public:
        Book(); // constructor no args
        Book(string title, string author, int num_of_pages, double cost); // constructor with args
        Book(const Book& book); // copy constructor
        ~Book(); // deconstructor

        // Functions
        void View();
        void Checkout();
        void Checkin();

        // getter functions
        int get_id();
        string get_title();
        string get_author();
        int get_num_of_pages();
        double get_cost();
        bool get_ischeckout();

        // setter functions
        void set_id(int id);
        void set_title(string title);
        void set_author(string author);
        void set_num_of_pages(int num_of_pages);
        void set_cost(double cost);
        void set_ischeckout(bool IsCheckOut);


    private:
        int m_id;
        string m_title;
        string m_author;
        int m_num_of_pages;
        double m_cost;
        bool m_IsCheckOut;
};


#endif //PROJECT_4_BOOK_H