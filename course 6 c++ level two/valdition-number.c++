#include <iostream>
using namespace std;
#include <limits>

int ReadNumber()
{
	int Number = 0;
	cout << "please enter number ?" << endl;
	cin >> Number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "invalid Number please enter valid Number ?" << endl;
		cin >> Number;
	}
	return Number;
}

int main()
{
	int Num = ReadNumber();
	cout << "\nYour Number is : " << Num << endl;

	return 0;

}