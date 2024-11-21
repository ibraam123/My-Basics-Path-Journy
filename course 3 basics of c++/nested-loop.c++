#include <iostream>
using namespace std;

int main (){
   /* for (int i = 1; i <= 10; i++)
    {
        cout << "i= " << i << endl;
        for (int j = 1; j <= 10; j++)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        
    }
    */




   for (int i = 0; i <= 10; i++)
   {
    for (int j = 10; j >= i; j--)
    {
        cout << "*" ;
    }
    cout << endl;
   }
   
}