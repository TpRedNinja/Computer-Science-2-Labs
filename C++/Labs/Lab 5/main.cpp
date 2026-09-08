#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string Encrypt_Message(string message, int key);
void Write_Message(string encrypted_message);
string Read_Message();
string Decrypt_Message(string encrypyted_message, int key);


int main()
{
    string message; // the unencrypted message
    int shift; // how many characters to shift the message by
    string encrypted_message; // original message encrypted by ceaser code

    cout << "This program will encrypt your message using Caesar code and write it to a file" << endl;
    cout << "Please enter your message: ";
    getline(cin, message);

    //input validation
    do
    {
        cout << "Please enter the amount you want the message to be encrypted by(Choose between 1 and 25): ";
        cin >> shift;

        if (shift < 1 || shift > 25)
        {
            cout << "Error: Please enter a valid number between 1 or 25" << endl;
        }

    } while (shift < 1 || shift > 25);

    // encrypting the message
    cout << message << endl;
    encrypted_message = Encrypt_Message(message, shift);
    cout << "Your message encrypted is: " << encrypted_message << endl;

    // writing the message to the file
    Write_Message(encrypted_message);
    cout << "Message written to secret_message.txt successfully" << endl;

    // reading the message from the file
    string encryptedMessage = Read_Message();

    // decrypting the message from the file
    string decryptedMessage = Decrypt_Message(encryptedMessage, shift);
    cout << "Your message decrypted is: " << decryptedMessage << endl;

    return 0;
}

// encrypt the users message
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

// write the users encrypted message to the file
void Write_Message(string encrypted_message)
{
    ofstream myfile("secret_message.txt");
    if (myfile.is_open())
    {
        myfile << encrypted_message << endl;
    }
}

// read the encrypted message
string Read_Message()
{
    ifstream myfile("secret_message.txt");
    string message;
    if (myfile.is_open())
    {
        while (getline(myfile, message))
        {
            return message;
        }
    } else
    {
        return message;
    }
}

string Decrypt_Message(string encrypyted_message, int key)
{
    string decrypted_message;
    for (int i = 0; i < encrypyted_message.length(); i++)
    {
        if (encrypyted_message[i] == ' ')
        {
            decrypted_message += ' ';
        } else if (isupper(encrypyted_message[i]))
        {
            decrypted_message += char(int(encrypyted_message[i]- key - 65 + 26) % 26 + 65);
        } else
        {
            decrypted_message += char(int(encrypyted_message[i]- key - 97 + 26) % 26 + 97);
        }
    }
    return decrypted_message;
}