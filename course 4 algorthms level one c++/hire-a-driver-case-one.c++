#include <iostream>
using namespace std;
/*int i;
void readage(int &age){
    cout << "enter your age: " << endl;
    cin >> age;
}

void readDriverlicense(){
    bool istrue = true;
     i = 0;
   
    
    if (istrue)
    {
        i ++;
    }
    else
    {
        cout << "rejected" << endl;
    }
    
    
}

int main(){
    int age;
    readage(age);
    if (age > 21 && (i = 1))
    {
        cout << "hired" << endl;
    }
    
}
/**if (boolean_expression_name) {
  // Code to be executed if the boolean_expression is true
}
 */

struct stinfo
{
    int age;
    bool hasdriverlinens;
};

stinfo readinfo(){
    stinfo info;

    cout << "please enter your age? " << endl;
    cin >> info.age;

    cout << "do you have a diver license? " << endl;
    cin >> info.hasdriverlinens;

    return info;
}

bool isaccepted(stinfo info){

}

void printresult (stinfo info){
    if (isaccepted(info))
    {
        cout << "Hired" << endl;
    }
    else
    {
        cout << "rejected" << endl;
    }
    
    
}
