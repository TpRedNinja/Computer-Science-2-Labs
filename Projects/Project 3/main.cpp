#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

const int SIZE = 500;
bool noWordsAvailable = false;

void readFile(string sentence[]);
string findLastWord(string userSentence);
vector<string> FindWordInFile(string word, string sentence[]);
vector<string> FindNextWord(string word, vector<string> validSentences);
void display(vector<string> wordsToDisplay, string userSentence);

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
    display(wordsToDisplay, userSentence);



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

    return wordsToDisplay;
}

void display(vector<string> wordsToDisplay, string userSentence)
{
    cout << "Your words are:" << endl;
    cout << "-------------------" << endl;
    int size = wordsToDisplay.size();
    vector<string> chosenWords = {};
    string option1, option2, option3, newSentence;
    int choice;

    random_device rd;
    mt19937 gen(rd());

    if (size == 0)
    {
        noWordsAvailable = true;
        option1 = "NULL";
        option2 = "NULL";
        option3 = "NULL";
        cout << option1 << endl;
        cout << option2 << endl;
        cout << option3 << endl;

    } else if (size == 3)
    {
        option1 = wordsToDisplay[0];
        option2 = wordsToDisplay[1];
        option3 = wordsToDisplay[2];
        cout << option1 << endl;
        cout << option2 << endl;
        cout << option3 << endl;
    }
    else if (size < 3 && size > 0)
    {
        if (size == 1)
        {
            option1 = wordsToDisplay[0];
            option2 = "NULL";
            option3 = "NULL";
        } else if (size == 2)
        {
            option1 = wordsToDisplay[0];
            option2 = wordsToDisplay[1];
            option3 = "NULL";
        }

    } else if (size > 3)
    {
        sample(wordsToDisplay.begin(), wordsToDisplay.end(), back_inserter(chosenWords),3, gen);
        option1 = chosenWords[0];
        option2 = chosenWords[1];
        option3 = chosenWords[2];
        cout << option1 << endl;
        cout << option2 << endl;
        cout << option3 << endl;
    }

    while (choice > 3 || choice < 1)
    {
        cout << "Enter 1 for the first word 2 for the second and 3 for the third word";
        cin >> choice;
        if (choice > 3 || choice < 1)
        {
            cout << "Please enter a valid choice";
        }
    }

    switch (choice)
    {
        case 1:
            newSentence = userSentence + " " + option1;
        case 2:
            newSentence = userSentence + " " + option2;
        case 3:
            newSentence = userSentence + " " + option3;
        default:
            newSentence = userSentence + " " + option1;
    }

    cout <<  "Your new sentence is: " << newSentence << endl;
}