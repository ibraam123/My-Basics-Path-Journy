#include <iostream>
using namespace std;

/**
 * rename sympole : change name function in all code 
 * peek : just look
 *  
some useful shortcut  
بعض الأختصارات المفيدة جدا ايضا
Ctrl + D: لتكرار السطر الحالي أو التحديد.
Alt + Up/Down: لنقل الأسطر أو الكتل الشيفرة إلى الأعلى أو الأسفل.
Ctrl + T: البحث السريع عن الملفات أو الفئات أو الدوال.
Ctrl + Tab: التنقل بين الملفات المفتوحة.
Ctrl + G: الانتقال إلى سطر معين.

 */

void function2(); // declation function

void koko()
{
    cout << "oh my guto it is abd el bast hamouda" << endl;
}
void function3()
{
    koko();
}
void function2()
{
    function3();
}
void function1()
{
    function2();
}

int main ()
{
    function1();

    return 0;
}

