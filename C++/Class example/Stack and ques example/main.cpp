#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

string fNames[10] = {"James", "Michael", "Robert", "John", "David", "Mary", "Patricia", "Jennifer", "Linda",
    "Elizabeth"};

string lNames[10] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez",
    "Martinez"};

string grocery[16] = {"chicken", "beef", "fish", "soup", "rice", "bread", "flour", "cereal", "spices",
    "honey", "sugar", "milk", "eggs", "cheese", "butter", "pasta"};

int count = 1;

class Customer {
    private:
        string fname;
        string lname;
        int line;
        stack<string> basket;
    public:
        Customer() {
            int f = rand() % 10;
            int l = rand() % 10;
            fname = fNames[f];
            lname = lNames[l];
            line = count;
            count ++;
        }
        bool isEmpty() {
            return basket.empty();
        }
        void displayInfo() {
            cout << line << " " << "fname: " << fname << " " << lname << " entered the store.\n" << endl;
            //shop();
        }
        // shop method
        void shop() {
            int items = rand() % 5 + 1;
            for (int i = 0; i < items; i++) {
                string item = grocery[rand() % 16];
                cout << fname << " got " << item << endl;
                basket.push(item);
            }
            cout << "Customer #" << line << " is heading to checkout.\n" << endl;
        }
        // buy method
        void buy() {
            cout << line << " " << "fname: " << fname << " " << lname << " is purchasing\n" << endl;
            //cout << basket.empty() << endl;
            while (! basket.empty()) {
                cout << "at line 54" << endl;
                cout << "Scanning: " << basket.top() << endl;
                basket.pop(); // pop basket item
                cout << "-------------------" << endl;
            }
        }
};

int main() {
    srand(time(0));
    // make a queue of customers
    queue <Customer> Checkout;

    // add 3 customers
    for (int i = 0; i < 3; i++) {
        Customer customer;
        customer.shop();
        Checkout.push(customer);
        //cout << "just shopped basket is " << Checkout.back().isEmpty() << endl;
    }
    // to iterate over each customer
    while (!Checkout.empty()) {
        //cout << Checkout.front().isEmpty() << endl;
        cout << "made it to line 76" << endl;
        Checkout.front().buy();
        Checkout.pop();
    }



    return 0;
}

/*class Customer{
	private:
        string fname;
        string lname;
        int line;
        stack <string> basket;
    public:
    	Customer() {
        	int f = rand() % 10;
            int l = rand() % 10;
            fname = fNames[f];
            lname = lNames[l];
            line = count;
            count ++;
        }
        void displayInfo(){
        	cout << line << " " << fname << " " << lname << " entered the store.\n";
		}
        // shop method
        void shop(){
            int items = rand() % 5 + 1;
            for (int i = 0; i < items; i++){
            	string item = grocery[rand() % 16];
                cout << fname << " got " << item << endl;
                basket.push(item);
            }
            cout << "Customer #" << line << " is heading to checkout.\n" << endl;
        }
        // buy method
        void buy(){
			cout << line << " " << fname << " " << lname << " is purchasing\n";

            while (! basket.empty()){
            	cout << "Scanning: " << basket.top() << endl;
                basket.pop(); // pop basket item
            }
        }


};*/
