/*#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


string ReadString()
{
    string S1 = " ";
    cout << "Please Enter your string ? \n";
    getline(cin, S1);
    return S1;
}

void printeachword(string S1){

    for (int i = 0; i < S1.length(); i++)
    {
        cout << S1[i];
        if (S1[i] == ' ')
        {
            
            cout << endl;
        }
        
    }
    

}
int main(){
    string s1 = ReadString();

    printeachword(s1);
}
*/
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

void printeachword(string S1)
{
    string delim = " "; // Delimiter: space to know we have a complete word or not
    cout << "\nYour string words are:\n\n";

    size_t pos = 0;
    string word; // Define each word in the string

    while ((pos = S1.find(delim)) != string::npos)
    {
        word = S1.substr(0, pos); // Store word
        if (!word.empty())
        {
            cout << word << endl;
        }
        S1.erase(0, pos + delim.length()); // Erase until the next word
    }

    // Print the last word (or the only word if there's no delimiter)
    if (!S1.empty())
    {
        cout << S1 << endl;
    }
}

int main()
{
    string S1 = ReadString();
    printeachword(S1);
    return 0;
}


