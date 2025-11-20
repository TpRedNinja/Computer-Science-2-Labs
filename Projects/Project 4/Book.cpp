#include "Book.h"
Book::Book()
{
    m_id = 0;
    m_title = "Undefined";
    m_author = "Undefined";
    m_num_of_pages = 0;
    m_cost = 0.00;
    m_IsCheckOut = false;
}
Book::Book(int id, string title, string author, int num_of_pages, double cost, bool isCheckOut)
{
    m_id = id;
    m_title = title;
    m_author = author;
    m_num_of_pages = num_of_pages;
    m_cost = cost;
    m_IsCheckOut = isCheckOut;
}
