#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Encrypt_Message(string message, int key);
void Write_Message(string encrypted_message);

int main()
{
    string message; // the unencrypted message
    int shift; // how many characters to shift the message by
    string encrypted_message; // original message encrypted by ceaser code

    cout << "This program will encyrpt your message using ceasar code and write it to a file" << endl;
    cout << "Please enter your message: ";
    getline(cin, message);

    //input validation
    do
    {
        cout << "Please enter the amount you want the message to be encyrpted by(Choose between 1 and 25): ";
        cin >> shift;

        if (shift < 1 || shift > 25)
        {
            cout << "Error: Please enter a valid number between 1 or 25" << endl;
        }

    } while (shift < 1 || shift > 25);

    // encrypting the message
    cout << message << endl;
    encrypted_message = Encrypt_Message(message, shift);
    cout << "Your message encypted is: " << encrypted_message << endl;

    // writing the message to the file
    Write_Message(encrypted_message);
    cout << "Message written to secret_message.txt successfully";

    return 0;
}

string Encrypt_Message(string message, int key)
{
    string encrypted_message;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
        {
            encrypted_message += ' ';
        } else if (isupper(message[i]))
        {
            encrypted_message += char(int(message[i]+ key - 65) % 26 + 65);
        } else
        {
            encrypted_message += char(int(message[i]+ key - 97) % 26 + 97);
        }
    }
    return encrypted_message;
}

void Write_Message(string encrypted_message)
{
    ofstream myfile("secret_message.txt");
    if (myfile.is_open())
    {
        myfile << encrypted_message << endl;
    }
}