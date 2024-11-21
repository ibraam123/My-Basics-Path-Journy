#include <iostream>
#include <string>
using namespace std;

int main()
{

    int num1;
    double num2 = 18.99;

    num1 = num2; // implecit cinvertion from double to int (compiler understand)

    num1 = (int)num2; // explic it covertion

    num1 = int(num2);

    cout << num1 << endl;

    string st1;
    st1 = to_string(num2);

    cout << st1 << endl;
    /*stoi;
      stod;
      stof;*/
    string numberStr = "123.45";

    // Convert to integer (truncates decimals)
    int intValue = stoi(numberStr);
    cout << numberStr << " to int: " << intValue << endl; // Output: 123

    // Convert to float
    float floatValue = stof(numberStr);
    cout << numberStr << " to float: " << floatValue << endl; // Output: 123.45

    // Convert to double (more precise)
    double doubleValue = stod(numberStr);
    cout << numberStr << " to double: " << doubleValue << endl; // Output: 123.45

}