#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* nextCar;
    Node* prevCar;
    Node(int val): data(val), nextCar(nullptr), prevCar(nullptr){}
};

class MyTrain {
    public:
        Node* engine;
        Node* caboose;
        MyTrain(): engine(nullptr), caboose(nullptr){}
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
            if (!engine) {
                engine = newNode;
            }
            else
            {
                Node* current = engine;
                while (current -> nextCar) {
                    current = current -> nextCar;
                }
                current -> nextCar = newNode;
                newNode -> prevCar = current;
            }
            caboose = newNode; // set to the newest node
        }

        void station() { // show the train
                Node* current = engine;
                cout << "\n  O" << endl;
                cout << " o" << endl;
                while (current){
                    cout << "-[ " << current -> data << " ]-";
                    current = current -> nextCar;
                }
                cout << endl;
            }

        void space(char letter,int size){
                for (int i = 0; i < size; i++){
                    cout << ' ';
                }
                cout << letter << endl;
            }

        void backup(){
            space('O',7*size()-5);
            space('o',7*size()-4);
            Node* current = caboose;
            while (current){
                cout << "-[ " << current -> data << " ]-";
                current = current -> prevCar;
                ///cout << current << endl;
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
                engine -> prevCar = nullptr;
                delete temp;
                return; // ends method
            }
            Node* current = engine;
            while (current -> nextCar && current -> nextCar -> data != value) {
                current = current -> nextCar;
            }
            if (current -> nextCar) {
                Node* temp = current -> nextCar;
                temp -> nextCar -> prevCar = temp -> prevCar;
                current -> nextCar = current -> nextCar -> nextCar;
                delete temp;
            }
        }

        void LinkInsert(int search, int value) {
            if (engine) {
                Node* newNode = new Node(value);

                Node* current = engine;
                while (current -> nextCar && current -> data != search) {
                    current = current -> nextCar;
                }
                if (current -> data == search) {
                    newNode -> nextCar = current -> nextCar;
                    newNode -> prevCar = current;
                    current -> nextCar -> prevCar = newNode;
                }
                // add to the end
                current -> nextCar = newNode;
            }
        }
};

int main() {
    cout << "This is a linked train list" << endl;
    MyTrain Bob; // train head

    // train is pulling something
    cout << "The train is pulling cars: " << !Bob.isEmpty() << endl;

    // add a few cars to the train
    for (int i = 0; i < 5; i++) {
        Bob.linkCars(i+1);
    }

    // display our train at the station
    cout << "The train is pulling into the station with: " << Bob.size() << " cars" << endl;
    Bob.station();

    //Bob.removeCar(0);
    //Bob.station();

    Bob.removeCar(2);
    Bob.station();

    Bob.LinkInsert(2,7);
    Bob.station();

    Bob.backup();

    return 0;
}