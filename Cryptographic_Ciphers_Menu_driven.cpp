// Header Files
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

const int SIZE = 5;

// Function Declarations
string caesarCipher(string, int);
string substitutionCipher(string, string, string);
string affineCipher(string, int, int);
string vigenereCipher(string, string);
string playfairCipher(string, char[][SIZE]);
void generateKeyTable(string, char[][SIZE]);

// Entry Point Function
int main(void)
{
    // Code
    int choice = 0;

    while (true)
    {
        /* code */
        cout << "Choose a Cipher for Encrypting Message: " << endl;
        cout << "---------------------" << endl;
        cout << "1. Caesar Cipher: " << endl;
        cout << "2. Substitution Cipher: " << endl;
        cout << "3. Affine Cipher: " << endl;
        cout << "4. Vigenere Cipher: " << endl;
        cout << "5. Playfair Cipher: " << endl;
        cout << "---------------------" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string message;
            int key;

            cout << "Enter the message to Encrypt: " << endl;
            getline(cin, message);

            cout << "Enter the key value (1-25): " << endl;
            cin >> key;
            string encrpytedMsg = caesarCipher(message, key);
            cout << "Encrypted Message: " << encrpytedMsg << endl;
        }
        break;
        case 2:
        {
            string message;
            string key;
            string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            cout << "Enter the message to Encrypt: " << endl;
            cin.ignore();
            getline(cin, message);

            cout << "Enter the substitution key (must be 26 unique letters): " << endl;
            getline(cin, key);

            string encrpytedMsg = substitutionCipher(message, key, alphabet);
            cout << "Encrypted Message: " << encrpytedMsg << endl;
        }
        break;
        case 3:
        {
            string message;
            int firstKey, secondKey;

            cout << "Enter the mesage to Encrypt: " << endl;
            cin.ignore();
            getline(cin, message);

            cout << "Enter First key (it must be co-prime with 26)" << endl;
            cin >> firstKey;

            cout << "Enter Second key (0-25)" << endl;
            cin >> secondKey;

            string encrpytedMsg = affineCipher(message, firstKey, secondKey);
            cout << "Encrypted Message: " << encrpytedMsg << endl;
        }
        break;
        case 4:
        {
            string message;
            string key;

            cout << "Enter the message to Encrypt: " << endl;
            cin.ignore();
            getline(cin, message);

            cout << "Enter the key: " << endl;
            getline(cin, key);

            string encrpytedMsg = vigenereCipher(message, key);
            cout << "Encrypted Message: " << encrpytedMsg << endl;
        }
        break;
        case 5:
        {
            string message;
            string key;
            //string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            cout << "Enter the message to Encrypt: " << endl;
            cin.ignore();
            getline(cin, message);

            cout << "Enter the Playfair key (25 unique letters): " << endl;
            getline(cin, key);

            char keyTable[SIZE][SIZE];
            generateKeyTable(key, keyTable);
            string encrpytedMsg = playfairCipher(message, keyTable);
            cout << "Encrypted Message: " << encrpytedMsg << endl;
        }
        break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        // Ask user if they want to continue
        char toContinue;
        cout << "Do you want to continue (y/n)? ";
        cin >> toContinue;

        if (tolower(toContinue) == 'n')
        {
            cout << "Thank You. Happy Coding!" << endl;
            exit(0);
        }
    }

    return 0;
}

// Functions Definitions
string caesarCipher(string message, int key)
{
    // Code

    // check whether key is in range or not
    key = key % 26;

    // Encrypt the message using caesar cipher
    for (char &c : message)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            c = (((c - 65) + key) % 26) + 65;
        }
    }

    return (message);
}

string substitutionCipher(string message, string key, string alphabet)
{
    // code

    // to remove any whitespaces from the given key
    key.erase(remove(key.begin(), key.end(), ' '), key.end());

    if (key.length() != 26)
    {
        return ("ERROR: key must be a 26 characters (only alphabet)");
    }

    /* transform(key.begin(), key.end(), key.begin(), ::toupper):
    __first – An input iterator.
    __last – An input iterator.
    __result – An output iterator.
    __unary_op – A unary operator.*/

    // Converting the given key into Uppercase
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    // check key is valid or not
    for (char c : key)
    {
        if (!isalpha(c))
        {
            return ("ERROR: key must contains only alphabets");
        }
        if (count(key.begin(), key.end(), c) > 1)
        {
            return ("ERROR: key must not have repeated characters");
        }
    }

    // Encrypt the message using substitution cipher
    for (char &c : message)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            int index = alphabet.find(c);
            c = key[index];
        }
    }

    return (message);
}

string affineCipher(string message, int firstKey, int secondKey)
{
    // code

    // check first key is co prime or not
    if (firstKey % 2 == 0 || firstKey % 13 == 0)
    {
        return ("ERROR: Key Must be co-prime with 26. (co-prime meaning :- Numbers which do not have any common factor other than 1 will be the co-prime of the given number.)");
    }

    // Check validity of the secondKey
    if (secondKey < 0 || secondKey > 25)
    {
        return ("ERROR: second key must be between 0-25");
    }

    // Find modular multiplicative inverse of a
    int firstKey_inv = -1;

    for (int i = 0; i < 26; i++)
    {
        if ((firstKey * i) % 26 == 1)
        {
            firstKey_inv = i;
            break;
        }
    }

    if (firstKey_inv == -1)
    {
        return ("ERROR: Could not find modular multiplicative inverse of first key value.");
    }

    // Encrypt the message using affine cipher
    for (char &c : message)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            // c = s(p + r)(mod 26).
            c = (((firstKey * (c - 65)) + secondKey) % 26) + 65;
        }
    }

    return (message);
}

string vigenereCipher(string message, string key)
{
    // code

    // Convert key to uppercase
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Encrypt message using Vigenere cipher
    for (int i = 0, j = 0; i < message.length(); i++)
    {
        char c = message[i];

        if (isalpha(c))
        {
            c = toupper(c);
            int key_index = j % key.length();
            char key_char = key[key_index];
            int key_value = key_char - 65;
            c = (((c - 65) + key_value) % 26) + 65;
            j++;
        }

        message[i] = c;
    }

    return (message);
}

// to generate 5*5 Key Table for Playfair Matrix
void generateKeyTable(string key, char keyTable[SIZE][SIZE])
{
    bool isTaken[26] = {false};

    // Remove spaces and duplicate letters from the key
    key.erase(remove(key.begin(), key.end(), ' '), key.end());

    // transform the given key to UPPERCASE
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Erases all non-alphabetic characters from the key
    key.erase(remove_if(key.begin(), key.end(),
                        [](char c)
                        { return !isalpha(c); }),
              key.end());

    // Removing all occurrences of the character 'J'
    key.erase(remove_if(key.begin(), key.end(),
                        [](char c)
                        { return (c == 'J'); }),
              key.end());

    key.erase(unique(key.begin(), key.end()), key.end());

    // Replace J with 
    key = regex_replace(key, regex("J"), "I");

    // Fill the key table with the key
    int row = 0, col = 0;
    for (char letter : key)
    {
        keyTable[row][col++] = letter;
        isTaken[letter - 'A'] = true;
        if (col == SIZE)
        {
            row++;
            col = 0;
        }
    }

    // Fill the remaining spaces of the key table with remaining letters of the alphabet
    for (int i = 0; i < 26; i++)
    {
        if (!isTaken[i])
        {
            keyTable[row][col++] = (char)('A' + i);
            if (col == SIZE)
            {
                row++;
                col = 0;
            }
        }
    }
}

// to get the position of the letter
void getPositions(char keyTable[SIZE][SIZE], char letter, int &row, int &col)
{
    if(letter == 'J')
    {
        letter = 'I';
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (keyTable[i][j] == letter)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string playfairCipher(string message, char keyTable[5][5])
{
    // Remove spaces and duplicate letters from the plaintext
    message.erase(remove(message.begin(), message.end(), ' '), message.end());

    transform(message.begin(), message.end(), message.begin(), ::toupper);
    
    message.erase(remove_if(message.begin(), message.end(),
                              [](char c)
                              { return !isalpha(c); }),
                    message.end());

    // Pad the plaintext with X if its length is odd
    if (message.length() % 2 == 1)
    {
        message += 'X';
    }

    // Encrypt the plaintext using the key table
    string ciphertext;
    for (int i = 0; i < message.length(); i += 2)
    {
        int row1, col1, row2, col2;
        getPositions(keyTable, message[i], row1, col1);
        getPositions(keyTable, message[i + 1], row2, col2);

        if (row1 == row2)
        {
            // Same row
            ciphertext += keyTable[row1][(col1 + 1) % SIZE];
            ciphertext += keyTable[row2][(col2 + 1) % SIZE];
        }
        else if (col1 == col2)
        {
            // Same column
            ciphertext += keyTable[(row1 + 1) % SIZE][col1];
            ciphertext += keyTable[(row2 + 1) % SIZE][col2];
        }
        else
        {
            // Different row and column
            ciphertext += keyTable[row1][col2];
            ciphertext += keyTable[row2][col1];
        }
    }

    return ciphertext;
}
