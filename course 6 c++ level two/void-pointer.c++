#include <iostream>
using namespace std;

int main()
{
void* ptr;
float f1 = 10.5;
ptr = &f1;
// Address طباعة
cout << "Address f1 : " << ptr << endl;
// الصحيح
// void م ن نوع Pointer لطباعة أو تعديل القيمة ل
cout << *(static_cast < float *> (ptr)) << endl;
*(static_cast <float*> (ptr)) = 22.8;
cout << *(static_cast <float*> (ptr)) << endl;
int x2 = 50;
// الى متغير آخر Pointer تحويل
ptr = &x2;
// Address طباعة
cout << "Address x2 : " << ptr << endl;
// الصحيح
// void م ن نوع Pointer لطباعة أو تعديل القيمة ل
cout << *(static_cast <int*> (ptr)) << endl;
*(static_cast <int*> (ptr)) = 99;
cout << *(static_cast <int*> (ptr)) << endl;


return 0;

}