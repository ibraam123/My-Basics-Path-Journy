#include <iostream>
#include <string>
using namespace std;

string readtext(){
    string text;

    cout << "please enter Text?" << endl;
    getline(cin , text);

    return text;
}

string encrypttext(string Text, short Encryptionkey){

    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int) Text[i] + Encryptionkey);
    }

    return Text;
}

string decrypt(string Text, short Encryptionkey){

    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int) Text[i] - Encryptionkey);
    }

    return Text;
}




int main (){
    const short encryptionkey = 2;  // this is a key

    string text = readtext();
    cout << "text before encryption: " << text << endl;
    cout << "text after encryption: " <<encrypttext(text , encryptionkey) << endl;


}