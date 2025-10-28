#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 500;

void readFile(string sentence[]);
string findLastWord(string userSentence);
vector<string> FindWordInFile(string word, string sentence[]);
vector<string> FindNextWord(string word, vector<string> validSentences);

int main()
{
    string userSentence;
    string sentence [SIZE] = {};
    vector<string> possibleSentences = {};
    vector<string> wordsToDisplay = {};

    cout << "Please enter a non complete sentence: ";
    getline(cin, userSentence);
    readFile(sentence);

    string word = findLastWord(userSentence);
    //cout << word << endl;

    possibleSentences = FindWordInFile(word, sentence);
    /* debug
     for (int i = 0; i < possibleSentences.size(); i++)
    {
        cout << possibleSentences[i] << endl;
    }
    */

    wordsToDisplay = FindNextWord(word, possibleSentences);

    return 0;
}

void readFile(string sentences[])
{
    string line;
    ifstream file("my_story.txt");
    if (file.is_open())
    {
        int i = 0;
        while (getline(file, line))
        {
            sentences[i] = line;
            //cout << sentences[i] + "," << endl;
            i ++;
        }
    }

}

string findLastWord(string userSentence)
{
    string word;
    auto index = userSentence.find_last_of(" ");
    word = " " + userSentence.substr(++index) + " ";
    return word;
}

vector<string> FindWordInFile(string word, string sentence[])
{
    vector<string> possibleSentences;
    string temp;
    int i = 0;
    while (sentence[i] != "")
    {
        temp = sentence[i];
        if (temp.find(word) != string::npos)
        {
            possibleSentences.push_back(temp);
        }
        i++;
    }
    return possibleSentences;
}

vector<string> FindNextWord(string word, vector<string> validSentences)
{
    int i = 0;
    vector<string> wordsToDisplay;
    string temp;
    while (validSentences[i] != "")
    {
        temp = validSentences[i].substr(validSentences[i].find(word));
        string temp2 = temp.substr(0,temp.find(" "));
        // do something to find the next word after the word and add it to the vector
        wordsToDisplay.push_back(temp2);
        i++;
    }

}