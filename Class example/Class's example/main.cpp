// This program is an all-in-one carpet class

#include <iomanip>
#include  <iostream>
#include <limits>
using namespace std;

class Carpet
{
private:
    double length;
    double width;
    double price;
    bool onSale;
public:
    Carpet()
    {
        length = 0;
        width = 0;
        price = 0;
        onSale = false;
    }

    Carpet(double l, double w, double p, bool s )
    {
        length = l;
        width = w;
        price = p;
        onSale = s;
    }

    // class Destructor
    ~Carpet()
    {
        cout << "Carpet Destructor Called" << endl;
    }

    // copy constructor
    Carpet(const Carpet &carpet)
    {
        length = carpet.length;
        width = carpet.width;
        price = carpet.price;
        onSale = carpet.onSale;
    }

    double getArea()
    {
        return length * width;
    }

    double getPrice()
    {
        double cost;
        if (onSale)
            cost = getArea() * price * .75;
        else
            cost = getArea() * price;
        return cost;
    }

    bool getOnSale()
    {
        return onSale;
    }

    void setOnSale(bool onSale)
    {
        this->onSale = onSale; // this uses the 'this' keyword
    }

    void display()
    {
        cout << setprecision(2) << fixed;
        cout << "Carpet Area: " << getArea() << "square feet" << endl;
        cout << "Carpet Price: $" << getPrice() << endl;
    }

};

int main()
{
    // create a customer carpet here
    Carpet CustomerCarpet = Carpet(10,6,1.49,true);

    cout << "The Carpet's Area is: " << CustomerCarpet.getArea() << " square feet" << endl;
    cout << setprecision(2) << fixed;
    cout << "The Price is: $" << CustomerCarpet.getPrice() << endl;
    if (CustomerCarpet.getOnSale())
        cout << "The Carpet is on sale!" << endl;
    else
        cout << "The Carpet is not on sale" << endl;

    // create a copy of carpet
    cout << "\nCopy Carpet" << endl;
    Carpet CopyCustomerCarpet = Carpet (CustomerCarpet);
    CopyCustomerCarpet.display(); // display copy


    return 0;
}