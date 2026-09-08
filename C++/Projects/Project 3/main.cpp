#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

const int SIZE = 500;
bool noWordsAvailable = false;
bool optionIsNull = false;

void readFile(string sentence[]);
string findLastWord(string userSentence);
vector<string> FindWordInFile(string word, string sentence[]);
vector<string> FindNextWord(string word, vector<string> validSentences);
void display(vector<string> wordsToDisplay, string userSentence);
void writeNewSentenceToFile(string newSentence);
bool inarray(vector<string> wordsToDisplay, string temp2);

int main()
{
    string userSentence;
    string sentence [SIZE] = {};
    vector<string> possibleSentences = {};
    vector<string> wordsToDisplay = {};
    int choice_main = 0;

    cout << "Please enter a non complete sentence: ";
    getline(cin, userSentence);
    readFile(sentence);

    string word = findLastWord(userSentence);
    cout << word << endl;

    possibleSentences = FindWordInFile(word, sentence);
    cout << "------------------------" << endl;
    wordsToDisplay = FindNextWord(word, possibleSentences);
    display(wordsToDisplay, userSentence);

    do
    {
        cout << "would you like to run this again or exit?" << endl;
        cout << "Enter 1 to restart and 2 to exit: ";
        cin >> choice_main;

        if (choice_main < 1 || choice_main > 2)
        {
            cout << "Error, enter a valid option!" << endl;
        }

        switch (choice_main)
        {
            case 1:
                cout << "Restarting..." << endl;
                main();
            case 2:
                cout << "Exiting..." << endl;
                break;
        }
    }
    while(choice_main < 1 || choice_main > 2);

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
    vector<string> wordsToDisplay;
    string temp;
    string temp2;
    for (int i = 0; i < validSentences.size(); i++)
    {
        temp = validSentences[i].substr(validSentences[i].find(word) + word.length());
        cout << temp << endl;
        temp2 = temp.substr(0,temp.find(' '));
        cout << temp2 << endl;
        if (!inarray(wordsToDisplay, temp2))
        {
            wordsToDisplay.push_back(temp2);
        }
    }

    return wordsToDisplay;
}

bool inarray(vector<string> wordsToDisplay, string temp2)
{
    if (wordsToDisplay.size() > 0)
    {
        for (int i = 0; i < wordsToDisplay.size(); i++)
        {
            if (wordsToDisplay[i] != temp2)
            {
                return false;
            } else
            {
                return true;
            }
        }
    }

    return false;

}

void display(vector<string> wordsToDisplay, string userSentence)
{
    cout << "Your words are:" << endl;
    cout << "-------------------" << endl;
    int size = wordsToDisplay.size();
    vector<string> chosenWords = {};
    string option1, option2, option3, newSentence;
    int choice;
    string newWord;

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
        optionIsNull = true;
        if (size == 1)
        {
            option1 = wordsToDisplay[0];
            option2 = "NULL please do not choose";
            option3 = "NULL please do not choose";
            cout << option1 << endl;
            cout << option2 << endl;
            cout << option3 << endl;

        } else if (size == 2)
        {
            option1 = wordsToDisplay[0];
            option2 = wordsToDisplay[1];
            option3 = "NULL please do not choose";
            cout << option1 << endl;
            cout << option2 << endl;
            cout << option3 << endl;
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

    do
    {
        if (noWordsAvailable)
        {
            cout << "Error: No possible words to recommend\nPlease complete the sentence" << endl;
            cin >> newSentence;
        } else
        {
            cout << "Enter 1 for the first word\n2 for the second\n3 for the third word\n4 if you want to put in your own word";
            cin >> choice;
            cout << choice << endl;
            if (choice > 4 || choice < 1)
            {
                cout << "Please enter a valid choice" << endl;
            }
            cout << "At line 194" << endl;
            if (!optionIsNull)
            {
                switch (choice)
                {
                    case 1:
                        newSentence = userSentence + " " + option1;
                        break;
                    case 2:
                        newSentence = userSentence + " " + option2;
                        break;
                    case 3:
                        newSentence = userSentence + " " + option3;
                        break;
                    case 4:
                        cin >> newWord;
                        newSentence = userSentence + " " + newWord;
                        break;
                }
            } else
            {
                if (option3 == "NULL please do not choose")
                {
                    switch (choice)
                    {
                        case 1:
                            newSentence = userSentence + " " + option1;
                            break;
                        case 2:
                            newSentence = userSentence + " " + option2;
                            break;
                        case 3:
                            cout << "Error can not choose null choose another option" << endl;
                            display(wordsToDisplay, userSentence);
                            break;
                        case 4:
                            cin >> newWord;
                            newSentence = userSentence + " " + newWord;
                            break;
                    }
                } else if (option2 == "NULL please do not choose" && option3 == "NULL please do not choose")
                {
                    switch (choice)
                    {
                        case 1:
                            newSentence = userSentence + " " + option1;
                            break;
                        case 2:
                            cout << "Error can not choose null choose another option" << endl;
                            display(wordsToDisplay, userSentence);
                            break;
                        case 3:
                            cout << "Error can not choose null choose another option" << endl;
                            display(wordsToDisplay, userSentence);
                            break;
                        case 4:
                            cin >> newWord;
                            newSentence = userSentence + " " + newWord;
                            break;
                    }
                }
            }
        }
        cout << "At line 207" << endl;
    } while ((choice > 4 || choice < 1) && !noWordsAvailable);

    cout <<  "Your new sentence is: " << newSentence << endl;
    cout << "Adding: " << newSentence << " to file" << endl;
    writeNewSentenceToFile(newSentence);
}

void writeNewSentenceToFile(string newSentence)
{
    ofstream outfile("my_story.txt", ios::app);
    outfile << newSentence << "\n";
}
