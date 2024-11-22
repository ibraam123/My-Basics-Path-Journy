#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1 = " ";
    cout << "Pleas Enter your string ? \n";
    getline(cin, S1);
    return S1;
}

string remove_punc(string &S1)
{
    string afterremove = "";
    for (int i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            afterremove += S1[i];
        }
        
    }
    return afterremove;
    
}

int main(){
    string S1 = ReadString();

    cout << "original string: " << endl;
    cout << S1 << endl;
    cout << "after remove punctiuation: " << endl << remove_punc(S1) << endl;

    return 0;
}