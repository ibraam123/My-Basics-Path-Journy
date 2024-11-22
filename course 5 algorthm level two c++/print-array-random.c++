#include <iostream>
#include <string>

using namespace std;


int RandomNumber(int From, int To)
{
 //Function to generate a random number

 int randNum = rand() % (To - From + 1) + From;
 return randNum;
}

void ReadArray(int arr[100], int& arrLength)   
// & main لترجع ( تخزن ) القيمة المدخلة في  
{ 
 cout << "Enter number of elements : \n"; 
 cin >> arrLength; 
 cout << "\n"; 
 
 for (int i = 0 ; i < arrLength; i++) {
 arr[i] = RandomNumber(1 , 100);  
 }


} 
void PrintArray(int arr[100], int arrLength)  
// main استدعاء  القيمة المخزنة في   arrLength 
{ 
 for (int i = 0; i < arrLength; i++) 
  cout << arr[i] << " "; 
 
 cout << "\n"; 
} 


int MinNumberInArray(int arr[100], int arrLength) 
{ 
 int min = 100; 
 for (int i = 0; i < arrLength; i++) 
 { 
  if (arr[i] < min) 
  { 
   min = arr[i]; 
  } 
 } 
 return min; 
}

int main(){



  

    int arr[100] , arrLength;

    ReadArray(arr , arrLength);

    cout << "\n elements of array: " ;
    PrintArray(arr , arrLength);

    cout << endl <<  MinNumberInArray(arr , arrLength);
}