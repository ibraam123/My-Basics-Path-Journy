#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
// Problem #40
string JoinString(string arrString[], short Length, string Delim)
{
string S1 = "";
for (short i = 0; i < Length; i++)
{
S1 = S1 + arrString[i] + Delim;
}
// الأخير Delim حذف
return S1.substr(0, S1.length() - Delim.length());
}
int main()
{
// Problem #40
string arrString[] = { "Mohammed","Faid","Ali","Maher" };
cout << "\n\nArray after join: \n";
cout << JoinString(arrString, 4, "***");
system("pause>0");
}