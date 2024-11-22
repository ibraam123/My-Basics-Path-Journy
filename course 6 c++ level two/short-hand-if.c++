#include <iostream>
using namespace std;

/**syntax
 *      condition? if true : if false;
 *      EX: (5 > 4)? true
 */

// homwork

#include <iostream>
using namespace std;
int ReadNumber ()
{
    int Number;
    cout <<"Please enter a number :"<<endl;
    cin >>Number;
    return Number;
}
void CheckNumber (int Number)
{
    string  Result;
    Result = (Number == 0) ? "Zero " : (Number > 0) ? "Positive " : "Negative ";;
    cout <<Result;
}
int main ()
{
    CheckNumber(ReadNumber());
}