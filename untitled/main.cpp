#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    //create a file name
    ofstream FileOut("TextFile.txt");

    // get setence from the user
    string line;
    cout << "Enter a sentence here: ";
    getline(cin, line);

    FileOut << line << endl; // write line to file

    FileOut.close(); // close the file
    return 0;
}