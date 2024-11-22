#include <iostream>
using namespace std;

/*void swap(int &n1 , int &n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}*/

void swap(int *n1 , int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}


int main()
{
    int a = 10 , b = 20 ;
    cout << "numbers before swap: " << endl << a << endl << b << endl ;

    swap(a , b);

    cout  << "numbers after swap: "  << endl << a << endl << b << endl ;

    return 0;
}