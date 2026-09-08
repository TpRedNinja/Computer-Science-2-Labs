#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout << "This program will store songs and display play them in order." << endl;

    queue <string> mySongs; // create our queue of songs
    string songHold; // temp variable
    do{
        cout << "Enter a song to add: (Leave Blank when done): ";
        getline(cin,songHold);
        if (songHold != ""){
            mySongs.push(songHold);
        }

    }
    while (songHold != "");

    // create a temp queue which we can play/iterate over
    queue <string> storeSongs;
    storeSongs = mySongs;
    cout << "Play List: "<<endl;
    while(! storeSongs.empty()){
        if (storeSongs.front() == storeSongs.back()){
            cout << "Warning: This is the last song."<<endl;
        };
        cout << "("<<storeSongs.size() <<") Now Playing: "<< storeSongs.front() <<endl;
        storeSongs.pop();
    }


    return 0;
}
