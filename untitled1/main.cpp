#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // create sentence variable
    string sentence;
    ifstream File("TextFile.txt");

    if (!File) {
        cout << "File could not be found" << endl;
    }
    else {
        while (getline(File, sentence)) {
            cout << sentence << endl;
        }
    }
    File.close();
    return 0;
}