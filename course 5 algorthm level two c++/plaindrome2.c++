#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message) {
	int Number = 0;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int checknumber_ifplainornot(int Number){
    int remainder = 0;
    int Number2 = 0;
    while (Number > 0)
	{
		remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + remainder;
	}
	return Number2;
}

int main(){
    int Number = ReadPositiveNumber("please enter a positive number");
    if (Number == checknumber_ifplainornot(Number))
    {
        cout << "Yes,number is plaindrome";
    }
    else
    {
        cout << "No,number not plaindrome";
    }
    
    

}

