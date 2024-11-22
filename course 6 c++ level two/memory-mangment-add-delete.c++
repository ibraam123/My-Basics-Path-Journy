#include <iostream>
using namespace std;

int main()
{

    // declare a pointer
    int * ptrx;
    float *ptrv;


    // dynamically allocate memory
    // إنشاء متغير مؤقت في الذاكرة
    ptrx = new int;
    ptrv = new float;


    // assigning value to the memory
    // إضافة قيمة للمتغير المؤقت في الذاكرة
    *ptrx = 10;
    *ptrv = 50.8;

    cout << *ptrx << endl;
    cout << *ptrv << endl;


    // deallocate the memory
    // إزالة المتغير المؤقت من الذاكرة
    delete ptrx;
    delete ptrv;

    return 0;
}
