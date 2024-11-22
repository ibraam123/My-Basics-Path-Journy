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

void printlengthofstring(string S1){

cout << "String length = " << S1.length() << endl;

}
void checksentence(string S1)
{
    int smallcount = 0;
    int capitalletter = 0;


    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            capitalletter ++;
        }
        else if (islower(S1[i]))
        {
            smallcount ++;
        }
        
    }
    
    cout << "capital letters = " << capitalletter << endl;
    cout << "small letters = " << smallcount << endl;

}

int main(){

string S1 = ReadString();

printlengthofstring(S1);
checksentence(S1);


return 0;

}