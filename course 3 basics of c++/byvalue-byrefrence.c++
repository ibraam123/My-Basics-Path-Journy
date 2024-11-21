#include <iostream>
#include <string>
using namespace std;

/*void myfunction(int& num1) // (& = adress) refrence 
{
    num1 = 700;
    cout << "number inside function became = " << num1 << endl;

}

int main(){
    int num1;
    num1 = 100;
    myfunction(num1);
    cout <<"number sfter calling the function became: " << num1 << endl << &num1 ;
}
// second call by refrence dont be convert and value be constant
*/
/** 
   void myfunction(int num1){
    num1 = 700;
    cout << "number inside function became = " << num1 << endl;

}

int main(){
    int num1;
    num1 = 100;
    myfunction(num1);
    cout <<"number sfter calling the function became: " << num1 ;
} 
// first call by value and send value to function after that change number from 100 to 700 then print it
*/

/**summary
 * CALL BY VALUE : passes a copy of the argumnt changes in the function do not affect the original argument 
 * CALL BY REFERNCE : passes a refrence to the argumnt changes in the function changes on main argument
 */
