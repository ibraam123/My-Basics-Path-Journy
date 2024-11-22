#include <iostream>
#include <string>
using namespace std;

int readnumber(int &number){
    cout << "please enter posotive number? " << endl;
    cin >> number;
    return number;
}
void PrintNormalLetter(int num) {
	for (int i = 65; i <= 65 + num - 1; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << (char)i;
		}
		cout << "\n";
	}
}
int main (){
    int number;
    PrintNormalLetter(readnumber(number));
}
