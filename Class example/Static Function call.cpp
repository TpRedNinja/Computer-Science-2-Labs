// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int count(){
    static int num = 0;
    num++;
    
    return num;
}

int main() {
    //call the count function
    for (int i = 0; i < 5; i++)
    {
        cout << count() << endl;
    }

    return 0;
}