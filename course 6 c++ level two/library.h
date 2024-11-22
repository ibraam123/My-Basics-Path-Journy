#include <iostream>
using namespace std;

/**
 * simple calculator
 */

namespace calculator 
{

    void calc()
    {

        int num1 = 0;
        int num2 = 0;
        cout << "please enter numbers one? " << endl;
        cin >> num1 ;
        cout << "please enter number two? " << endl;
        cin >> num2;

        char op;

        cout << "enter operation {+ , - , * , /}" << endl;
        cin >> op;

        switch (op)
        {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 ;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 ;
            break;
        
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 ;
            break;

        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2 ;
            break;
        }

    }
}