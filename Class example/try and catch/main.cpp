#include <iostream>
using namespace std;

class DivByZeroEx {
    public:
        DivByZeroEx(): m_message("error: divide by zero"){}
        string what() {return m_message; }
    private:
        string m_message;
};

double quotient(int num, int den) {
    if (den == 0)
        throw DivByZeroEx();
    return num / den;
}

int main() {
    try {
        cout << quotient(7, 0) << endl;
    }
    catch (DivByZeroEx& e) {
        cout << e.what() << endl;
    }
    return 0;
}