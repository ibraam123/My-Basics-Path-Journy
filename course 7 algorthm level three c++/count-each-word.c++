#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1 = "";
    cout << "Please Enter your string: \n";
    getline(cin, S1);
    return S1;
}

int printnumberofword(string S1)
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

    return countword;
}

int main()
{
    string S1 = ReadString();
    printnumberofword(S1);
    return 0;
}
