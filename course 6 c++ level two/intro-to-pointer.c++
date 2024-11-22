
/**
variable is container have a value and adress

we access to adress by add &


we store a adress by pointer variable


we can not store value in pointer just adresses


pointer must have same type of adress point to another variable
 */



#include<iostream>
using namespace std;
 int main()
{
    int a = 10;

    cout <<"a value        = " << a << endl;
    cout << "a address     = "<< & a << endl;


    int * p;
    p = &a;


    cout << "Pointer Value = " << p;
    cout << endl;


    return 0;

}