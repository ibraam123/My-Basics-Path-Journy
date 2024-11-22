#include <iostream>
#include <cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() ;
 return randNum;
}
int main() {
 //Seeds the random number generator in C++, called only once
 srand((unsigned)time(NULL));
 cout << char (RandomNumber(65, 90)) << endl;


 return 0;
}
