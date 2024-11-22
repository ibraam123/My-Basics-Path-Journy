#include <iostream>
#include <string>
#include <string>
using namespace std;

int main()
{
    char x;
char W;
// تجويل الحرف م ن الصغير الى الكبير
x = toupper('a');
// تجويل الحرف م ن الكبير الى الصغير
W = tolower('A');
// ASCII طباعة رقم الرمز أو الحرف في جدول
cout << toupper('a') << endl;
cout << tolower('A') << endl;
cout << "converting a to A : " << x << endl;
cout << "converting A to a : " << W << endl;
// إذا كان الجواب 0 فهو خطأ
// أما إن كان الجواب رقم آخر غير 0 فهو صحيح
// Digits ( A to Z )
// returns zero if not , and non zero of yes
cout << "isupper('A') " << isupper('A') << endl;
// lower case ( a to z )
// returns zero if not , and non zero of yes
cout << "islower('a') " << islower('a') << endl;
// Digits ( 0 to 9 )
// returns zero if not , and non zero of yes
cout << "isdigit('5') " << isdigit('5') << endl;
// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
// returns zero if not, and non zero of yes
cout << "ispunct(';') " << ispunct(';') << endl;
return 0;


}
