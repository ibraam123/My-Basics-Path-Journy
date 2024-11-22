#include <iostream>
using namespace std;


/**optionanl paramters can make it
 *if add value to paramter on function */
int sum(int a , int b , int c = 5 , int d = 5)
{
    return (a + b + c + d);
}

int main (){
    cout << sum(10 ,20) << endl;
    cout << sum(10 ,20 ,30) << endl;
    cout << sum(10 ,20 ,30 ,40) << endl;

}