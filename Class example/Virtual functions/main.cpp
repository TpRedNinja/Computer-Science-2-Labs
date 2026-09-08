#include <iostream>
#include <string>
using namespace std;

class SeaAnimal {
    protected:
        string where;
        int size;
        int distance;
    public:
        ~SeaAnimal() {
            cout << "Base Class Destructor Called (SeaAnimal)" << endl;
        }
        SeaAnimal() { // No-args Constructor
            cout << "Base Class Constructor Called (SeaAnimal)" << endl;
            where = "ocean";
            size = 5;
            distance = 0;
        }
        SeaAnimal(string where, int size) { // Args Constructor
            this -> where = where;
            this -> size = size;
            distance = 0;
        };
        int from_shore() {
            return distance;
        }
        // virtual functions to return
        virtual void swim() {
            distance ++;
        }

        virtual void print() {
        }
};

class Fish : public SeaAnimal {
    private:
        string color;
        int speed;
    public:
        ~Fish() {
            cout << "Derived Class Destructor Called (Fish)" << endl;
        }
        Fish() { // No-args Constructor
            cout << "Derived Class Constructor Called (Fish)" << endl;
            color = "red";
            speed = 2;
        }
        Fish(string color, int speed, string ocean, int size) : SeaAnimal(ocean, size), color(color), speed(speed) { // Args Constructor
        }

        // override the void swin function
        void swim() {
            distance += speed;
        }

        void print() {
            cout << "Ocean Location: " << where << endl;
            cout << "Fish Size: " << size << endl;
            cout << "From Shore: " << distance << endl;
            cout << "Fish Speed: " << speed << endl;
            cout << "Fish Color: " << color << endl;
        }
};

int main() {
    Fish Sharky("Blue", 5, "Atlantic", 10);

    for (int i = 0; i < 10; ++i)
        Sharky.swim();

    cout << Sharky.from_shore() << endl; // print off where sharky is from the shore

    Sharky.print();

    return 0;
}