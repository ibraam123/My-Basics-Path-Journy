/*Then Print the “PASS” if mark >=50, otherwise print “Fail”*/

#include <iostream>
using namespace std;

int readmark(int& mark){
    cout << "enter your mark? " << endl;
    cin >> mark;
    return mark;
}
void checkmark(int mark){

    if (mark >= 50)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL";
    }
    
    
    


}

int main(){

    int mark;
    checkmark(readmark(mark));
}