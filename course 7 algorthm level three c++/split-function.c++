#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string S1 = "";
    cout << "Please Enter your string: \n";
    getline(cin, S1);
    return S1;
}

void printnumberofword(string S1)
{
    int countword = 0;
    bool inWord = false;

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ') // If the current character is not a space
        {
            if (!inWord)
            {
                countword++; // Start of a new word
                inWord = true; // We are inside a word now
            }
        }
        else
        {
            inWord = false; // We are between words (or at the start)
        }
    }

    cout << "Tokens = " << countword << endl;
}

void split(string S1, vector<string> &vword)
{
    string word = "";
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ') // If the current character is not a space
        {
            word += S1[i]; // Add the character to the current word
        }
        else if (!word.empty())
        {
            vword.push_back(word); // Push the completed word into the vector
            word = ""; // Reset the word for the next word
        }
    }
    // Add the last word (if any) to the vector
    if (!word.empty())
    {
        vword.push_back(word);
    }

    // Print the words in the vector
    for (int i = 0; i < vword.size(); i++)
    {
        cout << vword[i] << endl;
    }
}

int main()
{
    string S1 = ReadString();
    vector <string> vword;
    printnumberofword(S1);
    split(S1 , vword);

    return 0;
}
