#ifndef PROJECT_4_BOOK_H
#define PROJECT_4_BOOK_H
#include <string>
#include <iostream>
using namespace std;

class Book
{
    public:
        Book(); // constructor no args
        Book(int id, string title, string author, int num_of_pages, double cost, bool isCheckOut); // constructor with args
        Book(const Book& book); // copy constructor
        ~Book(); // deconstructor

        // Functions
        void View();
        bool Checkout();
        bool Checkin();

    private:
        int m_id;
        string m_title;
        string m_author;
        int m_num_of_pages;
        double m_cost;
        bool m_IsCheckOut;
};


#endif //PROJECT_4_BOOK_H