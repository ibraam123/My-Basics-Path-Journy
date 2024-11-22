#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Problem #23
string ReadString()
{
    string S1 = " ";
    cout << "Pleas Enter your string ? \n";
    getline(cin, S1);
    return S1;
}
// Problem #26
string UpperAllString(string S3)
{
    for (int i = 0; i < S3.length(); i++)
    {
     S3[i] = toupper(S3[i]);
    }
    return S3;
}
string LowerAllString(string S3)
{
    for (int i = 0; i < S3.length(); i++)
    {
        S3[i] = tolower(S3[i]);
    }
    return S3;
}
int main()
{
// Problem #26
    string S3 = ReadString();


    cout << "\n String after Upper : \n";
    S3 = UpperAllString(S3);
    cout << S3 << endl;
    cout << "\n String after Lower : \n";
    S3 = LowerAllString(S3);
    cout << S3 << endl;
    system("pause>0");
}