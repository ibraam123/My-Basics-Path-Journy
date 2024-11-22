#include <iostream>
using namespace std;

char readoperator (char& op){
    cout << "please select operator you need cacluate? " << endl;
    cout << "(+) addition" << endl << "(-) substraction" << endl << "(*) multiblaction" << endl << "(/) divider" << endl;

    cin >> op;
    return op;

}
int twonumbertocalculate(int& number1 , int& number2){
    cout << "please enter number one? " << endl;
    cin >> number1;
    cout << endl << "please enter number two? " << endl;
    cin >> number2;
    return number1 , number2;
}

void calculate(char op , int number1 , int number2){
    switch (op)
    {
    case '+' :
        cout << number1 << " + " << number2 << " = " << number1+number2;
        break;
    
    case '-':
        cout << number1 << " - " << number2 << " = " << number1-number2;
        break;
    
    case '*':
        cout << number1 << " * " << number2 << " = " << number1*number2;
        break;
    case '/':
        cout << number1 << " / " << number2 << " = " << number1/number2;
        break;
    default:
    cout << "wrong operator";
    }
}

int main(){
    char op;
    int number1 , number2;
    twonumbertocalculate(number1,number2);
    
    calculate(readoperator(op),number1,number2);
    return 0;
}