/**we have three types of access modifier
 * 1 - private
 * access in only inside class
 * 2 - protected
 * access in class and inhertence this class
 * 3 - puplic
 * to every one
 * 
 * Public
شبه نقود الامه ( بتكون لكل الامه )

Protectde
شبه نقود الاب ( بيكون للاب و الوارثه ( اولاده ) فقط ) 

Private 
شبه نقود الابن ( بتكون للابن فقط لا غير )
*/

#include <iostream>
using namespace std;

class clsperson
{
private: // we can not write
    // only accessable inside this calass
    int varaible11 = 5;
    int function1()
    {
        return 40;
    }

protected:
    // only accessable inside this calass and all classes inhertence
    int varaible12 = 5;
    int function2()
    {
        return 40;
    }


public:
    string firstname;
    string lastname;
    string fullname(){
        return firstname + " " + lastname;
    }
    float function3(){
        return function1() * varaible11 * varaible12;
    }


};



int main(){

    clsperson person1;

    person1.firstname = "ibraam";
    person1.lastname = "magdy";

    cout << person1.fullname() << endl;
    cout << person1.function3();

    return 0;

}