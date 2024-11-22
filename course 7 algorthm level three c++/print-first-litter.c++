#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string ReadString()
{
    string S1 = " ";
    cout << "Pleas Enter your string ? \n";
    getline(cin, S1);
    return S1;
}
string UpeerFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
     if (S1[i] != ' ' && isFirstLetter)
     {
        S1[i] = toupper(S1[i]);
     }


      isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}

int main(){
    
    string s1 = ReadString();


    cout << UpeerFirstLetterOfEachWord(s1);
    system("pause>0");
}