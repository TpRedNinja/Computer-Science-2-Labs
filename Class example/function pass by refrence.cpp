// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int count(int &num){
    num++;
    
    return num;
}

int main() {
    int num = 0;
    cout << "Num Before the count () was called " << num << endl;
    //call the count function
    for (int i = 0; i < 5; i++)
    {
        cout << count(num) << endl;
    }
    cout << "Num After the count () was called " << num << endl;

    return 0;
}