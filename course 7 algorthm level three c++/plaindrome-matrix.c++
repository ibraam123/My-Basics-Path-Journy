
#include <iostream>
#include "mylibs.h"
#include <string>
using namespace std;

struct converter
{
    string row_one;
    string row_two;
    string row_three;
};


int ReverseNumber(int Number) {
  int Remainder = 0;
  int ReversedNumber = 0;  // Initialize a variable to store the reversed number
  while (Number > 0) {
    Remainder = Number % 10;  // Extract the last digit
    Number = Number / 10;    // Remove the last digit from the original number
    ReversedNumber = ReversedNumber * 10 + Remainder;  // Build the reversed number
  }
  return ReversedNumber;     // Return the reversed number
}


void printmatrix(int matrix[3][3]){

    for (int i = 0; i < 3; i++)
    {
            for (int j = 0; j < 3; j++)
            {
               cout << matrix[i][j] << "\t" ;
            }
        cout << endl;
        
    }
}

void convert_to_string(int matrix[3][3])
{

converter tostring;

for (int i = 0; i < 3; i++)
{
    tostring.row_one += to_string (matrix[0][i]);
    tostring.row_two += to_string (matrix[1][i]);
    tostring.row_three += to_string (matrix[2][i]);
}
 
 int rowone = stoi (tostring.row_one);
 int rowtwo = stoi (tostring.row_two);
 int rowthree = stoi (tostring.row_three);

 if ((rowone == ReverseNumber(rowone)) && (rowtwo == ReverseNumber(rowtwo)) && (rowthree == ReverseNumber(rowthree)))
 {
    cout << "it is a plaindrome number." << endl;
 }
 else
 {
    cout << "it is not a plaindrome number." << endl;
 }
 
}
  


int main(){
    int matrix[3][3] = {{1,2,1} , {2,1,2} , {3,2,3}};


    cout << "matrix : " << endl;
    printmatrix(matrix);

    convert_to_string(matrix);


    return 0;


}