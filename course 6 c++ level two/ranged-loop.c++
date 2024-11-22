#include <iostream>
using namespace std;
/**syntax
 *  for(range declartion : range expression)
 * {
 *  block of code
 * }
 * 
 * usage in array
 * must type of array same as type of range declartion
 */

int main(){

    int arrayone[] = {0,1,2,3,4};

    for (int number : arrayone)
    {
        cout << number << endl;
    }

    string arraytwo[] = {"ibraam" , "magdy" , "haliem" , "boles" , "rizk" };

    for (string name : arraytwo)
    {
        cout << name << endl;
    }

    bool arraythree[] = {true , false , 1 , 0};

    for (bool state : arraythree)
    {
        cout << state << endl;
    }
    
    

    

}

