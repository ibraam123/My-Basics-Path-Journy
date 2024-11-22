#include <iostream>
#include <cstdlib>
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
 for (int i = 0; i < arrLength; i++) {
  cout << arr[i] << " "; 
 }
 cout << "\n"; 
} 
void copy_array(int arr[100],int arrLength){
     int copyarr[100];
    for (int i = 0; i < arrLength; i++)
    {
         copyarr[i] = arr[i];
    }

    for (int i = 0; i < arrLength; i++)
    {
      cout << copyarr[i] << " ";

    }
    cout << endl;
    
    
   
}

int main (){
     srand((unsigned)time(NULL));

    int arr[100] , arrLength;

    ReadArray(arr , arrLength);

    cout << "\n elements of array 1 : " ;
    PrintArray(arr , arrLength);

    cout << "\n elements of array 2 after copy: " ;
    copy_array(arr , arrLength);

}

