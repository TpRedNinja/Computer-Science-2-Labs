#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* nextCar;
    Node(int val): data(val), nextCar(nullptr){}
};

class MyTrain {
    public:
        Node* engine;
        MyTrain(): engine(nullptr){}
        ~MyTrain() {
            Node* current = engine;
            while (current != nullptr) {
                Node* nextCar = current -> nextCar;
                delete current;
                current = nextCar;
            }
            engine = nullptr;
            cout << "Train destroyed" << endl;
        }

        // link car into place
        void linkCars(int value) {
            Node* newNode = new Node(value);
            // check if the train engine is pointing to null.
            if (!engine)
                engine = newNode;
            else
            {
                Node* current = engine;
                while (current -> nextCar)
                    current = current -> nextCar;
                current -> nextCar = newNode;
            }
        }
        void station() {
            Node* current = engine;
            while (current) {
                cout << "[" << current -> data << "]-";
                current = current -> nextCar;
            }
            cout << endl;
        }
        int size() {
            Node* current = engine;
            int total = 0;
            while (current) {
                total ++;
                current = current -> nextCar;
            }
            return total;
        }
        bool isEmpty() {
            if (!engine)
                return true;
            return false;
        }
        void removeCar(int value) {
            if (!engine)
                return; // ends method
            else if (engine -> data == value) {
                Node* temp = engine;
                engine = engine -> nextCar;
                delete temp;
                return; // ends method
            }
            Node* current = engine;
            while (current -> nextCar && current -> nextCar -> data != value) {
                current = current -> nextCar;
            }
            if (current -> nextCar) {
                Node* temp = current -> nextCar;
                current -> nextCar = current -> nextCar -> nextCar;
                delete temp;
            }
        }
};

int main() {
    cout << "This is a linked train list" << endl;
    MyTrain Bob; // train head

    // train is pulling something
    cout << "The train is pulling cars: " << !Bob.isEmpty() << endl;

    // add a few cars to the train
    for (int i = 0; i < 10; i++) {
        Bob.linkCars(i);
    }

    // display our train at the station
    cout << "The train is pulling into the station with: " << Bob.size() << " cars" << endl;
    Bob.station();

    Bob.removeCar(0);
    Bob.station();

    Bob.removeCar(9);
    Bob.station();

    return 0;
}