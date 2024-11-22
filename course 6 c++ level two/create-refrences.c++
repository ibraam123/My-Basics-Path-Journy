#include <iostream>
using namespace std;

int main ()
{
    int num1 = 10;
    int &num_copy = num1;

    /**two variable 
     * have same adress
     * and same value
     * if we change in 
     * any variable 
     * the change action do
     * on two variable 
     */



    cout << & num1 << endl << &num_copy << endl;


    num_copy = 15;
    cout <<  num1 << endl << num_copy << endl;

    num1 = 20;
    cout <<  num1 << endl << num_copy << endl;

    num1 ++;
    cout <<  num1 << endl << num_copy << endl;

    num_copy += 5;
    cout <<  num1 << endl << num_copy << endl;
}
