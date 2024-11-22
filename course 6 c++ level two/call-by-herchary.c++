#include <iostream>
using namespace std;

void function4()
{
    cout << "oh my guto it is abd el bast hamouda" << endl;
}
void function3()
{
    function4();
}
void function2()
{
    function3();
}
void function1()
{
    function2();
}

int main ()
{
    function1();
}

/**steps doing while excution of code
 * push main function
 * push function1
 * push function2
 * push function3
 * push function4
 * pop function4
 * pop function3
 * pop function2
 * pop function1
 * pop main function
 * end code
 */
