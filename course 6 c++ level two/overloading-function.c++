#include <iostream>
using namespace std;
/**
 * function overloading 
 * can diffrention by two types
 * 1 - by numbers of variables
 * 2 - by types of variable if have same numbers of variables
 * EX: (int a , int b) and (double a ,double b) same names but not same types (10 , 20) to integer (10.1 , 20.2) to double
 */

int sum(double a , double b)
{
    return (a + b);
}
int sum(int a, int b) {

	return (a + b);
}

int sum(int a, int b , int c) {

	return (a + b + c);
}

int sum(int a, int b , int c , int d) {

	return (a + b + c + d);
}





int main()
{
	cout << sum(1, 2) << endl;
	cout << sum(1, 2, 3) << endl;
	cout << sum(1, 2, 3, 4) << endl;
    cout << sum(10.1 , 20.2) << endl;
	
}