#include <iostream>
#include <fstream>
using namespace std;



void PrintFileContenet(string FileName)
{
fstream MyFile;
// للقراءة فقط ios::in
MyFile.open(FileName, ios::in ); // Read Mode
// للتأكد م ن أن الملف يعمل
if (MyFile.is_open())
{
string Line;
// string Line احصل على السطر الأول م ن الملف , واحفظه في هذا
while (getline(MyFile, Line))
{
cout << Line << endl;
}
// بعد الانتهاء م ن الملف لابد م ن إغلاقه
MyFile.close();
}
}
int main()
{
PrintFileContenet("MyFile.txt");

return 0;
}