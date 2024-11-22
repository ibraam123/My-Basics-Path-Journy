#include <iostream>
#include <cmath>
#include "mylibs.h"
using namespace std;



void printnumbers(int N , int M)
{
    if (N <= M)
    {
        cout << M << endl;
        printnumbers(N  , M - 1);
    }
    
}

int main(){
    cout << mylib::printpownumbers(2 , 6)<< endl;
    cout << mylib::factroial(5);  // give answer after end of stack

    return 0;
}




/**steps doing while excution of code
 * push main function
 * push printnumbers(1,4)
 * push printnumbers(2,4)
 * push printnumbers(3,4)
 * push printnumbers(4,4)
 * pop printnumbers(4,4)
 * pop printnumbers(3,4)
 * pop printnumbers(2,4)
 * pop printnumbers(1,4)
 * pop main function
 * end code
 * 
 * 
 * 
 * 
 *step 1                      step 2                      step 3                       step 4                         step 5                        step 6
          |                 |         |                 |        |                 |            |printnumbers(4,4)|            |                 |          |                 |        
          |                 |         |                 |        |printnumbers(3,4)|            |printnumbers(3,4)|            |printnumbers(3,4)|          |                 |        
 *        |                 |         |                 |        |printnumbers(2,4)|            |printnumbers(2,4)|            |printnumbers(2,4)|          |printnumbers(2,4)|        
 *        |                 |         |printnumbers(1,4)|        |printnumbers(1,4)|            |printnumbers(1,4)|            |printnumbers(1,4)|          |printnumbers(1,4)|        
 *        |     main        |         |     main        |        |     main        |            |     main        |            |      main       |          |      main       |        
 *        |________ ________|         |________ ________|        |________ ________|            |________ ________|            |________ ________|          |________ ________|        
 */        