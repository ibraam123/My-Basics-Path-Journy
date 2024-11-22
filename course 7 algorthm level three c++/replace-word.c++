#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string S12, string StringToReplace, string sRepalceTo)
{
    // البحث عن الكلمة المراد تبديلها
    short pos = S12.find(StringToReplace);
    // هل الكلمة موجودة ل تساوي فراغ
    while (pos != std::string::npos)
    {
    // بدل الكلمة من طول مثلا 12 , + طول
    S12 = S12.replace(pos, StringToReplace.length(), sRepalceTo);
    // البحث عن الكلمة المراد تبديلها
    pos = S12.find(StringToReplace); //find next
    }
    return S12;
}
int main()
{
    string S12 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "Jordan";
    string ReplaceTo = "USA";
    cout << "\nOrigial String\n" << S12;
    cout << "\n\nString After Replace:";
    cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(S12, StringToReplace, ReplaceTo);
    system("pause>0");
}