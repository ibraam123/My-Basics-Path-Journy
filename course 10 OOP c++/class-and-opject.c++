/**
    *struct stperson // data type
    *{
    *    string fname;
    *    string lname;
    *};
    * stperson person1;
    * person1.fname;
    * person1.lname;
 *
 * we thimling by objects to easily way (OOP)
 * classification a code into classes (date type like struct)
 * EX: {class a , class b , class c}
 * 
 * class is type of data type if we need to declare 
 * must create object
 */

#include <iostream>
using namespace std;


class clscar
{
private:
    int num;

    

public: // to access variable in int main
    string brand;
    int release_year;
    int price;
    
    int allprce(){
        return price;
    }

};
// every varible is private by defult

int main(){

    clscar car1; // person1 is opject

    car1.brand = "BMW";
    car1.release_year = 2016;
    car1.price = 200000;
    cout << car1.brand << endl << car1.release_year << endl << car1.allprce();

    return 0;
}
