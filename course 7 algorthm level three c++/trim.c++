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

string trimleft(string S1) {
    char space = ' ';

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
             return S1.substr(i , S1.length());
        }
        
    }
    return "";
}



int main (){
    string S1 = ReadString();

    cout << trimleft(S1);

    return 0;
}