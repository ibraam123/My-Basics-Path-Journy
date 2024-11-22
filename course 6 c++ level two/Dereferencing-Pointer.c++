
/**
variable is container have a value and adress

we access to adress by add &


we store a adress by pointer variable


we can not store value in pointer just adresses


pointer must have same type of adress point to another variable


derefracing pointer 


when add *to varisble is it key to move on another varaibke and open it to get value

we can print value and change it by this way



*p : take value 
p : take refrence 

*p = 50; true 
p = &a; true

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


    cout << "Pointer Value = " << p << endl;
    cout << "pointing p to adress value = " << *p << endl;


    *p = 20;
    

    cout << a << endl;
    cout << *p << endl;

    *p = 801;
    
    cout << a << endl;
    cout << *p << endl;


    a = 50;

    cout << a << endl;
    cout << *p << endl;

    return 0;

}