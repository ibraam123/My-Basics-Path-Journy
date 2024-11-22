#include <iostream>
#include <string>
using namespace std;

string replace(string S12, string StringToReplace, string sRepalceTo){

    int pos = S12.find(StringToReplace);
    while(pos != string::npos)
    {
        S12.erase(pos , StringToReplace.length());
        S12.insert(pos , sRepalceTo);
        pos = S12.find(StringToReplace);
    }

    return S12;
    

}

int main(){

    string S12 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "Jordan";
    string ReplaceTo = "USA";
    cout << "\nOrigial String\n" << S12;
    cout << "\n\nString After Replace:";
    cout << "\n" << replace(S12, StringToReplace, ReplaceTo);
    system("pause>0");

}

/**#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
// Problem #26
string LowerAllString(string S3)
{
for (int i = 0; i < S3.length(); i++)
{
S3[i] = tolower(S3[i]);
}
return S3;
}
// Problem #37
vector <string> SplitString(string S9, string Delim)
{
vector <string> vString;
short pos = 0;
string sWord; // define a string variable
// use fine() function to get the position of the delimiters
while ((pos = S9.find(Delim)) != std::string::npos)
{
// اوجد ) الحد - الفراغ S9.find(delim)
sWord = S9.substr(0, pos);
if (sWord != "")
{
vString.push_back(sWord);
}
// احذف م ن ) 0 الى عدد الأحرف + الحد
// erase() until positon and move to next word
S9.erase(0, pos + Delim.length());
}
// طباعة الكلمة الأخيرة من النص
if (S9 != "")
{
// it print last word of the string
vString.push_back(S9);
}
return vString;
} */